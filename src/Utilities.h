
#pragma once
#include <vector>
#include "Types.h"

class Piece;

bool isOccupied(int x, int y, const std::vector<Piece *> &pieces);
bool isOccupiedByOpponent(int x, int y, PieceColor color, const std::vector<Piece *> &pieces);
bool isSquareUnderAttack(int x, int y, PieceColor color, const std::vector<Piece *> &pieces);

bool isPathClear(int startX, int startY, int endX, int endY, const std::vector<Piece *> &pieces);
