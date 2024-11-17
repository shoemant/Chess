#pragma once
#include "Board.h"
#include "Types.h"

class AIPlayer
{
public:
    AIPlayer(PieceColor aiColor);

    std::pair<Piece *, std::pair<int, int>> getBestMove(Board &board, const std::pair<Piece *, std::pair<int, int>> &lastMove);

private:
    PieceColor aiColor_;
    int maxDepth_;

    int negamax(Board &board, int depth, int alpha, int beta, int colorMultiplier, const std::pair<Piece *, std::pair<int, int>> &lastMove);

    int evaluateBoard(const Board &board);

    std::vector<std::pair<Piece *, std::pair<int, int>>> getAllPossibleMoves(Board &board, PieceColor color, const std::pair<Piece *, std::pair<int, int>> &lastMove);
};
