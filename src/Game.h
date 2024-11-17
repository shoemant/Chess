
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Board.h"
#include "UIManager.h"
#include "pieces/Piece.h"
#include "ChessEngine/AIPlayer.h"
#include <thread>
#include <future>

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void handleClick(sf::Vector2i mousePos);
    void render();
    void replayGame();
    void exitGame();

    void toChessNotation(Piece *selectedPiece, int boardX, int boardY);

    void handleAIMove();

    void update();

    std::future<std::pair<Piece *, std::pair<int, int>>> aiFutureMove;
    bool aiMoveInProgress = false;

    AIPlayer aiPlayer_;

    sf::RenderWindow window;
    Board board;
    UIManager uiManager;
    GameState gameState;

    PieceColor currentTurn;
    Piece *selectedPiece;
    std::vector<std::pair<int, int>> validMoves;
    std::pair<Piece *, std::pair<int, int>> lastMove;
};
