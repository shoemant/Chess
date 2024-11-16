
#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(int x, int y, const sf::Sprite &sprite, PieceColor color)
        : Piece(x, y, sprite, color)
    {
        type_ = PieceType::Pawn;
        isSliding_ = false;
    }

    virtual std::vector<std::pair<int, int>> getPotentialMoves(const Board &board) const override;

    virtual std::unique_ptr<Piece> clone() const override;
};
