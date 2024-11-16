
#include "Rook.h"
#include "../Board.h"

std::vector<std::pair<int, int>> Rook::getPotentialMoves(const Board &board) const
{
    std::vector<std::pair<int, int>> moves;

    int directions[4][2] = {
        {0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    for (auto &dir : directions)
    {
        int newX = x_ + dir[0];
        int newY = y_ + dir[1];

        while (newX >= 0 && newX <= 7 && newY >= 0 && newY <= 7)
        {
            Piece *target = board.getPieceAt(newX, newY);
            if (target)
            {
                if (target->getColor() != color_)
                {
                    moves.emplace_back(newX, newY);
                }
                break;
            }
            moves.emplace_back(newX, newY);
            newX += dir[0];
            newY += dir[1];
        }
    }

    return moves;
}

std::unique_ptr<Piece> Rook::clone() const
{
    return std::make_unique<Rook>(*this);
}
