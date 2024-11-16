
#include "Knight.h"
#include "../Board.h"

std::vector<std::pair<int, int>> Knight::getPotentialMoves(const Board &board) const
{
    std::vector<std::pair<int, int>> moves;

    int deltas[8][2] = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

    for (auto &delta : deltas)
    {
        int newX = x_ + delta[0];
        int newY = y_ + delta[1];

        if (newX < 0 || newX > 7 || newY < 0 || newY > 7)
            continue;

        Piece *target = board.getPieceAt(newX, newY);
        if (target && target->getColor() == color_)
            continue;

        moves.emplace_back(newX, newY);
    }

    return moves;
}

std::unique_ptr<Piece> Knight::clone() const
{
    return std::make_unique<Knight>(*this);
}