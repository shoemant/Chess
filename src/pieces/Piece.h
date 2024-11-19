#pragma once

#include <SFML/Graphics.hpp>
#include "../Types.h"
#include <memory>
#include <iostream>
#include "Utilities.h"

class Board;

class Piece
{
public:
    Piece(int x, int y, const sf::Sprite &sprite, PieceColor color)
        : x_(x), y_(y), sprite_(sprite), color_(color), hasMoved_(false) {}

    virtual ~Piece() = default;

    Piece(const Piece &other)
        : x_(other.x_), y_(other.y_), color_(other.color_), type_(other.type_),
          isSliding_(other.isSliding_), hasMoved_(other.hasMoved_)
    {

        sprite_.setTexture(*other.sprite_.getTexture());
        sprite_.setTextureRect(other.sprite_.getTextureRect());
        sprite_.setPosition(x_ * 100.f, y_ * 100.f);
        sprite_.setScale(0.3f, 0.3f);
    }

    int getX() const { return x_; }
    int getY() const { return y_; }
    PieceColor getColor() const { return color_; }
    PieceType getType() const { return type_; }
    sf::Sprite getSprite() const { return sprite_; }

    void setPosition(int x, int y)
    {
        x_ = x;
        y_ = y;
        sprite_.setPosition(x_ * 100.f, y_ * 100.f);
    }

    virtual void move(int x, int y)
    {
        setPosition(x, y);
        hasMoved_ = true;
    }

    bool isSlidingPiece() const { return isSliding_; }

    bool hasMoved() const { return hasMoved_; }

    void setHasMoved(bool moved) { hasMoved_ = moved; }

    virtual std::vector<std::pair<int, int>> getPotentialMoves(const Board &board) const = 0;

    virtual std::unique_ptr<Piece> clone() const = 0;

protected:
    int x_;
    int y_;
    sf::Sprite sprite_;
    PieceColor color_;
    PieceType type_;
    bool isSliding_;
    bool hasMoved_ = false;
};
