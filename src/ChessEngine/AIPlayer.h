#pragma once
#include "Board.h"
#include "Types.h"

struct Move
{
    int startX, startY;
    int endX, endY;
    PieceType pieceType;
    PieceColor pieceColor;
    bool isPromotion;
    bool isCapture;
};

struct TTEntry
{
    int depth;
    int value;
    int flag;
};

class AIPlayer
{
public:
    AIPlayer(PieceColor aiColor);

    Move getBestMove(Board &board, const std::pair<Piece *, std::pair<int, int>> &lastMove);

private:
    PieceColor aiColor_;
    int maxDepth_;

    int negamax(Board &board, int depth, int alpha, int beta, int colorMultiplier, const std::pair<Piece *, std::pair<int, int>> &lastMove);

    int evaluateBoard(const Board &board);

    std::vector<Move> getAllPossibleMoves(Board &board, PieceColor color, const std::pair<Piece *, std::pair<int, int>> &lastMove);

    int moveOrderingHeuristic(const Move &move);

    int evaluateKingSafety(const Board &board, PieceColor color);
};
