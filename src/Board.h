
#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "pieces/Piece.h"
#include "Types.h"

class Board
{
public:
    Board();
    Board(const Board &other);

    void initializeBoard();

    void setupBoardGraphics();

    void draw(sf::RenderWindow &window, Piece *selectedPiece, const std::vector<std::pair<int, int>> &validMoves);

    Piece *getPieceAt(int x, int y) const;

    std::vector<std::pair<int, int>> getValidMoves(Piece *piece, const std::pair<Piece *, std::pair<int, int>> &lastMove) const;

    void movePiece(Piece *piece, int endX, int endY, bool enPassant, bool castling);

    bool isKingInCheck(PieceColor color) const;

    bool hasValidMoves(PieceColor color) const;

    bool isInsufficientMaterial() const;

    bool isPathClear(int startX, int startY, int endX, int endY) const;

    bool isSquareUnderAttack(int x, int y, PieceColor color) const;

    bool isOccupied(int x, int y) const;
    bool isOccupiedByOpponent(int x, int y, PieceColor color) const;

    const std::vector<std::unique_ptr<Piece>> &getPieces() const { return pieces; }

private:
    std::vector<std::unique_ptr<Piece>> pieces;

    sf::RectangleShape squares[8][8];

    void removePieceAt(int x, int y);
    void capturePieceAt(int x, int y);
    bool canCastle(PieceColor color, bool isKingSide) const;
    void promotePawn(Piece *pawn);
};
