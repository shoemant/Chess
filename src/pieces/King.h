
#pragma once

#include "Piece.h"

class King : public Piece
{
public:
    King(int x, int y, const sf::Sprite &sprite, PieceColor color)
        : Piece(x, y, sprite, color)
    {
        type_ = PieceType::King;
        isSliding_ = false;
    }

    King(const King &other) : Piece(other)
    {
    }

    virtual std::vector<std::pair<int, int>> getPotentialMoves(const Board &board) const override;

    virtual std::unique_ptr<Piece> clone() const override;
};