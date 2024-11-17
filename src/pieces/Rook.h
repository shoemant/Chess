
#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(int x, int y, const sf::Sprite &sprite, PieceColor color)
        : Piece(x, y, sprite, color)
    {
        type_ = PieceType::Rook;
        isSliding_ = true;
    }

    virtual std::vector<std::pair<int, int>> getPotentialMoves(const Board &board) const override;

    virtual std::unique_ptr<Piece> clone() const override;

    Rook(const Rook &other) : Piece(other)
    {
    }
};
