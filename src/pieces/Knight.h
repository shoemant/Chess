
#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(int x, int y, const sf::Sprite &sprite, PieceColor color)
        : Piece(x, y, sprite, color)
    {
        type_ = PieceType::Knight;
        isSliding_ = false;
    }

    virtual std::vector<std::pair<int, int>> getPotentialMoves(const Board &board) const override;

    virtual std::unique_ptr<Piece> clone() const override;
};
