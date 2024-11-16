
#include "Pawn.h"
#include "../Board.h"

std::vector<std::pair<int, int>> Pawn::getPotentialMoves(const Board &board) const
{
    std::vector<std::pair<int, int>> moves;
    int direction = (color_ == PieceColor::White) ? -1 : 1;
    int startRow = (color_ == PieceColor::White) ? 6 : 1;

    int newX = x_;
    int newY = y_ + direction;
    if (newY >= 0 && newY <= 7 && !board.isOccupied(newX, newY))
    {
        moves.emplace_back(newX, newY);

        if (y_ == startRow)
        {
            int twoStepY = y_ + 2 * direction;
            if (twoStepY >= 0 && twoStepY <= 7 && !board.isOccupied(newX, twoStepY))
            {
                moves.emplace_back(newX, twoStepY);
            }
        }
    }

    int captureOffsets[2][2] = {
        {-1, direction}, {1, direction}};

    for (auto &offset : captureOffsets)
    {
        int captureX = x_ + offset[0];
        int captureY = y_ + offset[1];

        if (captureX >= 0 && captureX <= 7 && captureY >= 0 && captureY <= 7)
        {
            Piece *target = board.getPieceAt(captureX, captureY);
            if (target && target->getColor() != color_)
            {
                moves.emplace_back(captureX, captureY);
            }
        }
    }

    return moves;
}

std::unique_ptr<Piece> Pawn::clone() const
{
    return std::make_unique<Pawn>(*this);
}