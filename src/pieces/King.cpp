
#include "King.h"
#include "../Board.h"

std::vector<std::pair<int, int>> King::getPotentialMoves(const Board &board) const
{
    std::vector<std::pair<int, int>> moves;
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (auto &dir : directions)
    {
        int newX = x_ + dir[0];
        int newY = y_ + dir[1];

        if (newX < 0 || newX > 7 || newY < 0 || newY > 7)
            continue;

        Piece *target = board.getPieceAt(newX, newY);
        if (target && target->getColor() == color_)
            continue;

        moves.emplace_back(newX, newY);
    }

    return moves;
}

std::unique_ptr<Piece> King::clone() const
{
    return std::make_unique<King>(*this);
}
