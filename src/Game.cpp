
#include "Game.h"
#include "Board.h"
#include "UIManager.h"
#include "pieces/King.h"
#include "pieces/Queen.h"
#include "pieces/Bishop.h"
#include "pieces/Knight.h"
#include "pieces/Rook.h"
#include "pieces/Pawn.h"
#include <iostream>
#include <algorithm>

Game::Game()
    : window(sf::VideoMode(800, 800), "Chess Game"),
      board(),
      uiManager(),
      gameState(GameState::Playing),
      currentTurn(PieceColor::White),
      selectedPiece(nullptr),
      lastMove({nullptr, {-1, -1}}),
      aiPlayer_(PieceColor::Black)
{
}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::update()
{
    if (aiMoveInProgress && aiFutureMove.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        auto bestMove = aiFutureMove.get();

        bool isCastling = false;
        if (bestMove.first->getType() == PieceType::King && std::abs(bestMove.second.first - bestMove.first->getX()) == 2)
        {
            isCastling = true;
            std::cout << "AI is attempting to castle.\n";
        }

        board.movePiece(bestMove.first, bestMove.second.first, bestMove.second.second, false, isCastling);

        lastMove = bestMove;
        aiMoveInProgress = false;

        if (board.isKingInCheck(PieceColor::White) && !board.hasValidMoves(PieceColor::White))
        {
            uiManager.displayGameOver("Checkmate! AI wins!");
            gameState = GameState::GameOver;
        }
        else if (!board.hasValidMoves(PieceColor::White))
        {
            uiManager.displayGameOver("Stalemate! It's a draw!");
            gameState = GameState::GameOver;
        }
        else
        {
            currentTurn = PieceColor::White;
        }
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            exitGame();
        }
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (gameState == GameState::GameOver)
            {

                uiManager.handleGameOverClick(mousePos, [this]()
                                              { replayGame(); }, [this]()
                                              { exitGame(); });
            }
            else if (!aiMoveInProgress && currentTurn == PieceColor::White && gameState == GameState::Playing)
            {

                handleClick(mousePos);

                if (currentTurn == PieceColor::Black)
                {
                    aiMoveInProgress = true;
                    aiFutureMove = std::async(std::launch::async, [this]()
                                              { return aiPlayer_.getBestMove(board, lastMove); });
                }
            }
        }
    }
}

void Game::handleClick(sf::Vector2i mousePos)
{
    if (gameState == GameState::Playing)
    {
        int boardX = mousePos.x / 100;
        int boardY = mousePos.y / 100;

        if (selectedPiece == nullptr)
        {

            Piece *piece = board.getPieceAt(boardX, boardY);
            if (piece && piece->getColor() == currentTurn)
            {
                selectedPiece = piece;
                validMoves = board.getValidMoves(piece, lastMove);
            }
        }
        else
        {
            if (std::find(validMoves.begin(), validMoves.end(), std::make_pair(boardX, boardY)) != validMoves.end())
            {

                bool enPassant = false;
                bool castling = false;

                if (Pawn *pawn = dynamic_cast<Pawn *>(selectedPiece))
                {
                    int direction = (pawn->getColor() == PieceColor::White) ? -1 : 1;
                    if (boardY == pawn->getY() + direction && std::abs(boardX - pawn->getX()) == 1)
                    {
                        Piece *target = board.getPieceAt(boardX, boardY);
                        if (!target)
                        {
                            enPassant = true;
                            std::cout << "En passant move detected." << std::endl;
                        }
                    }
                }

                if (King *king = dynamic_cast<King *>(selectedPiece))
                {
                    int dx = boardX - king->getX();
                    if (std::abs(dx) == 2)
                    {
                        castling = true;
                        std::cout << "Castling move detected." << std::endl;
                    }
                }

                try
                {
                    board.movePiece(selectedPiece, boardX, boardY, enPassant, castling);

                    lastMove = {selectedPiece, {boardX, boardY}};

                    selectedPiece = nullptr;
                    validMoves.clear();

                    PieceColor opponentColor = (currentTurn == PieceColor::White) ? PieceColor::Black : PieceColor::White;

                    if (board.isInsufficientMaterial())
                    {
                        uiManager.displayGameOver("Draw!\nInsufficient material.");
                        gameState = GameState::GameOver;
                    }
                    else if (board.isKingInCheck(opponentColor) && !board.hasValidMoves(opponentColor))
                    {
                        std::string winner = (currentTurn == PieceColor::White) ? "White" : "Black";
                        uiManager.displayGameOver("Checkmate!\n" + winner + " wins!");
                        gameState = GameState::GameOver;
                    }
                    else if (!board.hasValidMoves(opponentColor))
                    {
                        uiManager.displayGameOver("Stalemate!\nIt's a draw!");
                        gameState = GameState::GameOver;
                    }
                    else
                    {
                        currentTurn = opponentColor;
                    }
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Error during move: " << e.what() << std::endl;
                }
            }
            else
            {

                std::cout << "Invalid move attempted." << std::endl;
                selectedPiece = nullptr;
                validMoves.clear();
            }
        }
    }
}

void Game::render()
{
    window.clear(sf::Color::White);
    board.draw(window, selectedPiece, validMoves);
    uiManager.draw(window, gameState);
    window.display();
}

void Game::replayGame()
{
    std::cout << "Replaying the game..." << std::endl;
    board.initializeBoard();
    currentTurn = PieceColor::White;
    selectedPiece = nullptr;
    validMoves.clear();
    lastMove = {nullptr, {-1, -1}};
    gameState = GameState::Playing;
    std::cout << "Game has been reset." << std::endl;
}

void Game::exitGame()
{
    std::cout << "Exiting the game." << std::endl;
    window.close();
}

void Game::toChessNotation(Piece *selectedPiece, int boardX, int boardY)
{

    char type = '\0';
    int rank = boardY + 1;
    char file = 'a' + boardX;

    switch (selectedPiece->getType())
    {
    case PieceType::Pawn:

        break;
    case PieceType::King:
        type = 'K';
        break;
    case PieceType::Queen:
        type = 'Q';
        break;
    case PieceType::Rook:
        type = 'R';
        break;
    case PieceType::Bishop:
        type = 'B';
        break;
    case PieceType::Knight:
        type = 'N';
        break;
    default:
        throw std::invalid_argument("Unknown piece type");
    }

    std::string notation;
    if (type != '\0')
    {
        notation += type;
    }
    notation += file;
    notation += std::to_string(rank);

    std::cout << notation << std::endl;
}

void Game::handleAIMove()
{

    auto bestMove = aiPlayer_.getBestMove(board, lastMove);

    if (bestMove.first != nullptr)
    {

        try
        {

            bool enPassant = false;
            bool castling = false;

            if (Pawn *pawn = dynamic_cast<Pawn *>(bestMove.first))
            {
                int direction = (pawn->getColor() == PieceColor::White) ? -1 : 1;
                if (bestMove.second.second == pawn->getY() + direction && std::abs(bestMove.second.first - pawn->getX()) == 1)
                {
                    Piece *target = board.getPieceAt(bestMove.second.first, bestMove.second.second);
                    if (!target)
                    {
                        enPassant = true;
                    }
                }
            }

            if (King *king = dynamic_cast<King *>(bestMove.first))
            {
                int dx = bestMove.second.first - king->getX();
                if (std::abs(dx) == 2)
                {
                    castling = true;
                }
            }

            board.movePiece(bestMove.first, bestMove.second.first, bestMove.second.second, enPassant, castling);

            lastMove = {bestMove.first, bestMove.second};

            currentTurn = (currentTurn == PieceColor::White) ? PieceColor::Black : PieceColor::White;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error during AI move: " << e.what() << std::endl;
        }
    }
    else
    {
        std::cerr << "AI has no valid moves!" << std::endl;
    }
}
