
#pragma once
#include <vector>
#include "Types.h"
#include <string>

class Piece;

bool isOccupied(int x, int y, const std::vector<Piece *> &pieces);
bool isOccupiedByOpponent(int x, int y, PieceColor color, const std::vector<Piece *> &pieces);
bool isSquareUnderAttack(int x, int y, PieceColor color, const std::vector<Piece *> &pieces);

bool isPathClear(int startX, int startY, int endX, int endY, const std::vector<Piece *> &pieces);

inline std::string pieceTypeToString(PieceType type)
{
    switch (type)
    {
    case PieceType::Pawn:
        return "Pawn";
    case PieceType::Knight:
        return "Knight";
    case PieceType::Bishop:
        return "Bishop";
    case PieceType::Rook:
        return "Rook";
    case PieceType::Queen:
        return "Queen";
    case PieceType::King:
        return "King";
    default:
        return "Unknown";
    }
}
