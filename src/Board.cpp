#include "Board.h"
#include "pieces/King.h"
#include "pieces/Queen.h"
#include "pieces/Bishop.h"
#include "pieces/Knight.h"
#include "pieces/Rook.h"
#include "pieces/Pawn.h"
#include "Utilities.h"
#include "ResourceManager/ResourceManager.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

Board::Board()
{
    setupBoardGraphics();
    initializeBoard();
}

Board::Board(const Board &other)
{
    for (const auto &piece : other.pieces)
    {
        pieces.emplace_back(piece->clone());
    }
}

void Board::initializeBoard()
{

    pieces.clear();

    try
    {
        sf::Texture &chessPiecesTexture = ResourceManager::getInstance().getTexture("assets/chess_pieces.png");
    }
    catch (const std::exception &e)
    {

        throw;
    }

    auto addPiece = [&](PieceType type, PieceColor color, int x, int y)
    {
        sf::Sprite sprite;
        sprite.setTexture(ResourceManager::getInstance().getTexture("assets/chess_pieces.png"));
        int textureCol = 0;
        switch (type)
        {
        case PieceType::King:
            textureCol = 0;
            break;
        case PieceType::Queen:
            textureCol = 1;
            break;
        case PieceType::Bishop:
            textureCol = 2;
            break;
        case PieceType::Knight:
            textureCol = 3;
            break;
        case PieceType::Rook:
            textureCol = 4;
            break;
        case PieceType::Pawn:
            textureCol = 5;
            break;
        }

        int textureRow = (color == PieceColor::White) ? 0 : 333;
        sprite.setTextureRect(sf::IntRect(textureCol * 333, textureRow, 333, 333));
        sprite.setPosition(x * 100.f, y * 100.f);
        sprite.setScale(0.3f, 0.3f);

        switch (type)
        {
        case PieceType::King:
            pieces.emplace_back(std::make_unique<King>(x, y, sprite, color));
            break;
        case PieceType::Queen:
            pieces.emplace_back(std::make_unique<Queen>(x, y, sprite, color));
            break;
        case PieceType::Rook:
            pieces.emplace_back(std::make_unique<Rook>(x, y, sprite, color));
            break;
        case PieceType::Bishop:
            pieces.emplace_back(std::make_unique<Bishop>(x, y, sprite, color));
            break;
        case PieceType::Knight:
            pieces.emplace_back(std::make_unique<Knight>(x, y, sprite, color));
            break;
        case PieceType::Pawn:
            pieces.emplace_back(std::make_unique<Pawn>(x, y, sprite, color));
            break;
        }
    };

    addPiece(PieceType::Rook, PieceColor::White, 0, 7);
    addPiece(PieceType::Knight, PieceColor::White, 1, 7);
    addPiece(PieceType::Bishop, PieceColor::White, 2, 7);
    addPiece(PieceType::Queen, PieceColor::White, 3, 7);
    addPiece(PieceType::King, PieceColor::White, 4, 7);
    addPiece(PieceType::Bishop, PieceColor::White, 5, 7);
    addPiece(PieceType::Knight, PieceColor::White, 6, 7);
    addPiece(PieceType::Rook, PieceColor::White, 7, 7);
    for (int i = 0; i < 8; ++i)
        addPiece(PieceType::Pawn, PieceColor::White, i, 6);

    addPiece(PieceType::Rook, PieceColor::Black, 0, 0);
    addPiece(PieceType::Knight, PieceColor::Black, 1, 0);
    addPiece(PieceType::Bishop, PieceColor::Black, 2, 0);
    addPiece(PieceType::Queen, PieceColor::Black, 3, 0);
    addPiece(PieceType::King, PieceColor::Black, 4, 0);
    addPiece(PieceType::Bishop, PieceColor::Black, 5, 0);
    addPiece(PieceType::Knight, PieceColor::Black, 6, 0);
    addPiece(PieceType::Rook, PieceColor::Black, 7, 0);
    for (int i = 0; i < 8; ++i)
        addPiece(PieceType::Pawn, PieceColor::Black, i, 1);
}

void Board::setupBoardGraphics()
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            squares[row][col].setSize(sf::Vector2f(100.f, 100.f));
            squares[row][col].setPosition(col * 100.f, row * 100.f);
            if ((row + col) % 2 == 0)
                squares[row][col].setFillColor(sf::Color::White);
            else
                squares[row][col].setFillColor(sf::Color(139, 69, 19));
        }
    }
}

void Board::draw(sf::RenderWindow &window, Piece *selectedPiece, const std::vector<std::pair<int, int>> &validMoves)
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            window.draw(squares[row][col]);
        }
    }

    if (selectedPiece)
    {
        sf::CircleShape highlight(30.f);
        highlight.setFillColor(sf::Color(100, 255, 100, 100));
        highlight.setOrigin(30.f, 30.f);
        for (const auto &move : validMoves)
        {
            float posX = move.first * 100.f + 50.f;
            float posY = move.second * 100.f + 50.f;
            highlight.setPosition(posX, posY);
            window.draw(highlight);
        }
    }

    for (const auto &piece : pieces)
    {
        window.draw(piece->getSprite());
    }
}

Piece *Board::getPieceAt(int x, int y) const
{
    for (const auto &piece : pieces)
    {
        if (piece->getX() == x && piece->getY() == y)
            return piece.get();
    }
    return nullptr;
}

std::vector<std::pair<int, int>> Board::getValidMoves(Piece *piece, const std::pair<Piece *, std::pair<int, int>> &lastMove) const
{
    std::vector<std::pair<int, int>> potentialMoves;

    if (!piece)
        return potentialMoves;

    potentialMoves = piece->getPotentialMoves(*this);

    std::vector<std::pair<int, int>> validMoves;

    if (piece->getType() == PieceType::King && !piece->hasMoved())
    {

        if (canCastle(piece->getColor(), true))
        {

            validMoves.emplace_back(piece->getX() + 2, piece->getY());
        }

        if (canCastle(piece->getColor(), false))
        {

            validMoves.emplace_back(piece->getX() - 2, piece->getY());
        }
    }

    if (piece->getType() == PieceType::Pawn)
    {

        Pawn *pawn = dynamic_cast<Pawn *>(piece);
        int direction = (pawn->getColor() == PieceColor::White) ? -1 : 1;
        int startRank = (pawn->getColor() == PieceColor::White) ? 3 : 4;

        if (pawn->getY() == startRank)
        {
            for (int dx = -1; dx <= 1; dx += 2)
            {
                int captureX = pawn->getX() + dx;
                int captureY = pawn->getY() + direction;

                if (captureX < 0 || captureX > 7)
                    continue;

                if (lastMove.first && lastMove.first->getType() == PieceType::Pawn &&
                    lastMove.first->getColor() != pawn->getColor() &&
                    lastMove.first->getX() == captureX &&
                    lastMove.first->getY() == pawn->getY())
                {
                    validMoves.emplace_back(captureX, captureY);
                }
            }
        }
    }

    for (const auto &move : potentialMoves)
    {
        int destX = move.first;
        int destY = move.second;

        if (destX < 0 || destX > 7 || destY < 0 || destY > 7)
            continue;

        Piece *targetPiece = getPieceAt(destX, destY);
        if (targetPiece && targetPiece->getColor() == piece->getColor())
            continue;

        if (piece->getType() == PieceType::King && !piece->hasMoved())
        {
            int deltaX = destX - piece->getX();
            if ((deltaX == 2 || deltaX == -2) && destY == piece->getY())
            {
                bool isKingSide = (deltaX == 2);
                int rookX = isKingSide ? 7 : 0;
                int rookNewX = isKingSide ? 5 : 3;

                Piece *rook = getPieceAt(rookX, destY);
                if (!rook || rook->getType() != PieceType::Rook || rook->getColor() != piece->getColor() || rook->hasMoved())
                {
                    continue;
                }

                int step = isKingSide ? 1 : -1;
                bool pathClear = true;
                for (int x = piece->getX() + step; x != rookX; x += step)
                {
                    if (isOccupied(x, destY))
                    {
                        pathClear = false;
                        break;
                    }
                }
                if (!pathClear)
                    continue;

                if (isKingInCheck(piece->getColor()))
                    continue;

                int kingPathX1 = piece->getX() + step;
                int kingPathX2 = piece->getX() + 2 * step;

                if (isSquareUnderAttack(kingPathX1, destY, piece->getColor()) ||
                    isSquareUnderAttack(kingPathX2, destY, piece->getColor()) ||
                    isSquareUnderAttack(piece->getX(), destY, piece->getColor()))
                    continue;

                validMoves.emplace_back(destX, destY);
                continue;
            }
        }

        if (piece->isSlidingPiece())
        {
            if (!isPathClear(piece->getX(), piece->getY(), destX, destY))
                continue;
        }

        Board tempBoard = *this;
        Piece *tempPiece = tempBoard.getPieceAt(piece->getX(), piece->getY());

        if (!tempPiece)
            continue;

        tempBoard.movePiece(tempPiece, destX, destY, false, false);

        if (!tempBoard.isKingInCheck(piece->getColor()))
        {
            validMoves.emplace_back(destX, destY);
        }
    }

    return validMoves;
}

bool Board::canCastle(PieceColor color, bool isKingSide) const
{

    int row = (color == PieceColor::White) ? 7 : 0;
    int rookX = isKingSide ? 7 : 0;
    int direction = isKingSide ? 1 : -1;

    Piece *king = nullptr;
    for (const auto &p : pieces)
    {
        if (p->getType() == PieceType::King && p->getColor() == color)
        {
            king = p.get();
            break;
        }
    }
    if (!king)
    {

        return false;
    }

    Piece *rook = getPieceAt(rookX, row);
    if (!rook || rook->getType() != PieceType::Rook || rook->getColor() != color)
    {

        return false;
    }

    if (king->hasMoved() || rook->hasMoved())
    {

        return false;
    }

    for (int x = king->getX() + direction; x != rookX; x += direction)
    {
        if (isOccupied(x, row))
        {

            return false;
        }
    }

    if (isKingInCheck(color))
    {

        return false;
    }
    for (int i = 0; i <= 2; ++i)
    {
        int x = king->getX() + i * direction;
        if (isSquareUnderAttack(x, row, color))
        {

            return false;
        }
    }

    return true;
}

void Board::movePiece(Piece *piece, int endX, int endY, bool enPassant, bool castling)
{
    if (!piece)
        throw std::invalid_argument("Null piece pointer.");

    if (enPassant)
    {
        int captureY = (piece->getColor() == PieceColor::White) ? endY + 1 : endY - 1;
        auto it = std::find_if(pieces.begin(), pieces.end(),
                               [&](const std::unique_ptr<Piece> &p)
                               {
                                   return p->getX() == endX && p->getY() == captureY &&
                                          p->getColor() != piece->getColor() && p->getType() == PieceType::Pawn;
                               });
        if (it != pieces.end())
        {
            pieces.erase(it);
        }
        else
        {
            throw std::logic_error("En passant capture failed; target pawn not found.");
        }
    }
    else
    {
        auto it = std::find_if(pieces.begin(), pieces.end(),
                               [&](const std::unique_ptr<Piece> &p)
                               { return p->getX() == endX && p->getY() == endY && p->getColor() != piece->getColor(); });
        if (it != pieces.end())
            pieces.erase(it);
    }

    if (castling)
    {
        King *king = dynamic_cast<King *>(piece);
        if (!king)
            throw std::invalid_argument("Only kings can perform castling.");

        bool isKingSide = (endX - king->getX() == 2);
        int rookX = isKingSide ? 7 : 0;
        int rookNewX = isKingSide ? 5 : 3;

        Piece *rookPiece = getPieceAt(rookX, king->getY());
        Rook *rook = dynamic_cast<Rook *>(rookPiece);
        if (rook && !rook->hasMoved())
        {
            rook->move(rookNewX, king->getY());
            rook->setHasMoved(true);
        }
    }

    piece->move(endX, endY);

    if (piece->getType() == PieceType::Pawn)
    {
        int promotionRank = (piece->getColor() == PieceColor::White) ? 0 : 7;
        if (endY == promotionRank)
        {
            promotePawn(piece);
        }
    }
}

void Board::promotePawn(Piece *pawn)
{
    if (!pawn || pawn->getType() != PieceType::Pawn)
        throw std::invalid_argument("Only pawns can be promoted.");

    sf::Sprite sprite;
    sprite.setTexture(ResourceManager::getInstance().getTexture("assets/chess_pieces.png"));

    int textureCol = 1;
    int textureRow = (pawn->getColor() == PieceColor::White) ? 0 : 333;
    sprite.setTextureRect(sf::IntRect(textureCol * 333, textureRow, 333, 333));
    sprite.setPosition(pawn->getX() * 100.f, pawn->getY() * 100.f);
    sprite.setScale(0.3f, 0.3f);

    auto it = std::find_if(pieces.begin(), pieces.end(),
                           [&](const std::unique_ptr<Piece> &p)
                           { return p.get() == pawn; });
    if (it != pieces.end())
    {
        pieces.erase(it);
    }

    pieces.emplace_back(std::make_unique<Queen>(pawn->getX(), pawn->getY(), sprite, pawn->getColor()));
}

bool Board::isKingInCheck(PieceColor color) const
{
    int kingX = -1, kingY = -1;
    for (const auto &piece : pieces)
    {
        if (piece->getType() == PieceType::King && piece->getColor() == color)
        {
            kingX = piece->getX();
            kingY = piece->getY();
            break;
        }
    }

    if (kingX == -1 || kingY == -1)
    {

        return false;
    }

    for (const auto &piece : pieces)
    {
        if (piece->getColor() != color)
        {
            std::vector<std::pair<int, int>> opponentMoves = piece->getPotentialMoves(*this);
            for (const auto &move : opponentMoves)
            {
                if (move.first == kingX && move.second == kingY)
                {
                    if (piece->isSlidingPiece())
                    {
                        if (!isPathClear(piece->getX(), piece->getY(), move.first, move.second))
                            continue;
                    }
                    return true;
                }
            }
        }
    }

    return false;
}

bool Board::isSquareUnderAttack(int x, int y, PieceColor color) const
{
    for (const auto &piece : pieces)
    {
        if (piece->getColor() == color)
            continue;

        std::vector<std::pair<int, int>> moves = piece->getPotentialMoves(*this);
        for (const auto &move : moves)
        {
            if (move.first == x && move.second == y)
            {
                if (piece->isSlidingPiece())
                {
                    if (!isPathClear(piece->getX(), piece->getY(), move.first, move.second))
                        continue;
                }
                return true;
            }
        }
    }
    return false;
}

bool Board::hasValidMoves(PieceColor color) const
{
    for (const auto &piece : pieces)
    {
        if (piece->getColor() == color)
        {
            std::vector<std::pair<int, int>> moves = getValidMoves(piece.get(), {nullptr, {-1, -1}});
            if (!moves.empty())
            {
                return true;
            }
        }
    }
    return false;
}

bool Board::isInsufficientMaterial() const
{
    int whitePieces = 0, blackPieces = 0;
    bool whiteHasBishop = false, whiteHasKnight = false;
    bool blackHasBishop = false, blackHasKnight = false;

    for (const auto &piece : pieces)
    {
        if (piece->getType() == PieceType::King)
            continue;

        if (piece->getColor() == PieceColor::White)
        {
            whitePieces++;
            if (piece->getType() == PieceType::Bishop)
                whiteHasBishop = true;
            if (piece->getType() == PieceType::Knight)
                whiteHasKnight = true;
        }
        else
        {
            blackPieces++;
            if (piece->getType() == PieceType::Bishop)
                blackHasBishop = true;
            if (piece->getType() == PieceType::Knight)
                blackHasKnight = true;
        }
    }

    if (whitePieces == 0 && blackPieces == 0)
        return true;

    if ((whitePieces == 1 && whiteHasBishop) && blackPieces == 0)
        return true;
    if ((blackPieces == 1 && blackHasBishop) && whitePieces == 0)
        return true;

    if ((whitePieces == 1 && whiteHasKnight) && blackPieces == 0)
        return true;
    if ((blackPieces == 1 && blackHasKnight) && whitePieces == 0)
        return true;

    if (whitePieces == 1 && blackPieces == 1 &&
        whiteHasBishop && blackHasBishop)
    {
        const Bishop *whiteBishop = nullptr;
        const Bishop *blackBishop = nullptr;

        for (const auto &piece : pieces)
        {
            if (piece->getType() == PieceType::Bishop)
            {
                if (piece->getColor() == PieceColor::White)
                {
                    whiteBishop = dynamic_cast<const Bishop *>(piece.get());
                }
                else
                {
                    blackBishop = dynamic_cast<const Bishop *>(piece.get());
                }
            }
        }

        if (whiteBishop && blackBishop)
        {
            bool whiteBishopOnLight = (whiteBishop->getX() + whiteBishop->getY()) % 2 == 0;
            bool blackBishopOnLight = (blackBishop->getX() + blackBishop->getY()) % 2 == 0;

            if (whiteBishopOnLight == blackBishopOnLight)
                return true;
        }
    }

    return false;
}

bool Board::isPathClear(int startX, int startY, int endX, int endY) const
{
    int dx = endX - startX;
    int dy = endY - startY;

    int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
    int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);

    int currentX = startX + stepX;
    int currentY = startY + stepY;

    while (currentX != endX || currentY != endY)
    {
        if (isOccupied(currentX, currentY))
            return false;

        currentX += stepX;
        currentY += stepY;
    }

    return true;
}

bool Board::isOccupied(int x, int y) const
{
    return getPieceAt(x, y) != nullptr;
}
