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

// constructor for game
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

// run the game loop
void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

// update game state
void Game::update()
{
    if (aiMoveInProgress && aiFutureMove.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        Move bestMove = aiFutureMove.get();

        Piece *pieceToMove = board.getPieceAt(bestMove.startX, bestMove.startY);
        if (!pieceToMove)
        {
            std::cerr << "failed to find the piece to move at the expected position." << std::endl;
            aiMoveInProgress = false;
            return;
        }

        bool isCastling = false;
        if (pieceToMove->getType() == PieceType::King && std::abs(bestMove.endX - bestMove.startX) == 2)
        {
            isCastling = true;
            std::cout << "ai is attempting to castle.\n";
        }

        board.movePiece(pieceToMove, bestMove.endX, bestMove.endY, false, isCastling);

        lastMove = {pieceToMove, {bestMove.endX, bestMove.endY}};
        aiMoveInProgress = false;

        if (board.isKingInCheck(PieceColor::White) && !board.hasValidMoves(PieceColor::White))
        {
            uiManager.displayGameOver("checkmate! ai wins!");
            gameState = GameState::GameOver;
        }
        else if (!board.hasValidMoves(PieceColor::White))
        {
            uiManager.displayGameOver("stalemate! it's a draw!");
            gameState = GameState::GameOver;
        }
        else
        {
            currentTurn = PieceColor::White;
        }
    }
}

// process user and system events
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

// handle mouse click events
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
                        }
                    }
                }

                if (King *king = dynamic_cast<King *>(selectedPiece))
                {
                    int dx = boardX - king->getX();
                    if (std::abs(dx) == 2)
                    {
                        castling = true;
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
                        uiManager.displayGameOver("draw!\ninsufficient material.");
                        gameState = GameState::GameOver;
                    }
                    else if (board.isKingInCheck(opponentColor) && !board.hasValidMoves(opponentColor))
                    {
                        std::string winner = (currentTurn == PieceColor::White) ? "white" : "black";
                        uiManager.displayGameOver("checkmate!\n" + winner + " wins!");
                        gameState = GameState::GameOver;
                    }
                    else if (!board.hasValidMoves(opponentColor))
                    {
                        uiManager.displayGameOver("stalemate!\nit's a draw!");
                        gameState = GameState::GameOver;
                    }
                    else
                    {
                        currentTurn = opponentColor;
                    }
                }
                catch (const std::exception &e)
                {
                    std::cerr << "error during move: " << e.what() << std::endl;
                }
            }
            else
            {
                std::cout << "invalid move attempted." << std::endl;
                selectedPiece = nullptr;
                validMoves.clear();
            }
        }
    }
}

// render the game window
void Game::render()
{
    window.clear(sf::Color::White);
    board.draw(window, selectedPiece, validMoves);
    uiManager.draw(window, gameState);
    window.display();
}

// reset and replay the game
void Game::replayGame()
{
    std::cout << "replaying the game..." << std::endl;
    board.initializeBoard();
    currentTurn = PieceColor::White;
    selectedPiece = nullptr;
    validMoves.clear();
    lastMove = {nullptr, {-1, -1}};
    gameState = GameState::Playing;
    std::cout << "game has been reset." << std::endl;
}

// exit the game
void Game::exitGame()
{
    std::cout << "exiting the game." << std::endl;
    window.close();
}

// convert move to chess notation
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
        type = 'k';
        break;
    case PieceType::Queen:
        type = 'q';
        break;
    case PieceType::Rook:
        type = 'r';
        break;
    case PieceType::Bishop:
        type = 'b';
        break;
    case PieceType::Knight:
        type = 'n';
        break;
    default:
        throw std::invalid_argument("unknown piece type");
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

// handle AI move
void Game::handleAIMove()
{
    auto bestMove = aiPlayer_.getBestMove(board, lastMove);

    Piece *pieceToMove = board.getPieceAt(bestMove.startX, bestMove.startY);
    if (!pieceToMove)
    {
        std::cerr << "failed to find the piece to move at the expected position." << std::endl;
        return;
    }

    bool isCastling = false;
    if (pieceToMove->getType() == PieceType::King && std::abs(bestMove.endX - bestMove.startX) == 2)
    {
        isCastling = true;
    }

    board.movePiece(pieceToMove, bestMove.endX, bestMove.endY, false, isCastling);

    lastMove = {pieceToMove, {bestMove.endX, bestMove.endY}};

    currentTurn = (currentTurn == PieceColor::White) ? PieceColor::Black : PieceColor::White;
}
