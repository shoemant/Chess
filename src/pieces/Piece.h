#pragma once

#include <SFML/Graphics.hpp>
#include "../Types.h"
#include <memory>
#include <iostream>
#include "Utilities.h"

class Board;

// piece class representing a chess piece
class Piece
{
public:
    // constructor for piece
    Piece(int x, int y, const sf::Sprite &sprite, PieceColor color)
        : x_(x), y_(y), sprite_(sprite), color_(color), hasMoved_(false) {}

    // destructor for piece
    virtual ~Piece() = default;

    // copy constructor for piece
    Piece(const Piece &other)
        : x_(other.x_), y_(other.y_), color_(other.color_), type_(other.type_),
          isSliding_(other.isSliding_), hasMoved_(other.hasMoved_)
    {

        sprite_.setTexture(*other.sprite_.getTexture());
        sprite_.setTextureRect(other.sprite_.getTextureRect());
        sprite_.setPosition(x_ * 100.f, y_ * 100.f);
        sprite_.setScale(0.3f, 0.3f);
    }

    // get the x position of the piece
    int getX() const { return x_; }

    // get the y position of the piece
    int getY() const { return y_; }

    // get the color of the piece
    PieceColor getColor() const { return color_; }

    // get the type of the piece
    PieceType getType() const { return type_; }

    // get the sprite of the piece
    sf::Sprite getSprite() const { return sprite_; }

    // set the position of the piece
    void setPosition(int x, int y)
    {
        x_ = x;
        y_ = y;
        sprite_.setPosition(x_ * 100.f, y_ * 100.f);
    }

    // move the piece to a new position
    virtual void move(int x, int y)
    {
        setPosition(x, y);
        hasMoved_ = true;
    }

    // check if the piece is a sliding piece
    bool isSlidingPiece() const { return isSliding_; }

    // check if the piece has moved
    bool hasMoved() const { return hasMoved_; }

    // set the moved status of the piece
    void setHasMoved(bool moved) { hasMoved_ = moved; }

    // get all potential moves for the piece
    virtual std::vector<std::pair<int, int>> getPotentialMoves(const Board &board) const = 0;

    // clone the piece
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
