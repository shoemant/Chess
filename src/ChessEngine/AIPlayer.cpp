#include "AIPlayer.h"
#include "PieceSquareTables.h"
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include "Utilities.h"

AIPlayer::AIPlayer(PieceColor aiColor)
    : aiColor_(aiColor), maxDepth_(5)
{
}

std::pair<Piece *, std::pair<int, int>> AIPlayer::getBestMove(Board &board, const std::pair<Piece *, std::pair<int, int>> &lastMove)
{
    int bestValue = std::numeric_limits<int>::min();
    std::pair<Piece *, std::pair<int, int>> bestMove = {nullptr, {-1, -1}};

    auto possibleMoves = getAllPossibleMoves(board, aiColor_, lastMove);

    std::cout << "AI is evaluating " << possibleMoves.size() << " possible moves.\n";

    for (auto &move : possibleMoves)
    {
        Piece *piece = move.first;
        int destX = move.second.first;
        int destY = move.second.second;

        std::cout << "AI considering move: " << pieceTypeToString(piece->getType())
                  << " from (" << piece->getX() << ", " << piece->getY() << ") to ("
                  << destX << ", " << destY << "), hasMoved_ = "
                  << (piece->hasMoved() ? "true" : "false") << std::endl;

        bool isCastling = false;
        if (piece->getType() == PieceType::King && std::abs(destX - piece->getX()) == 2 && destY == piece->getY())
        {
            isCastling = true;
            std::cout << "AI considers castling move.\n";
        }

        Board tempBoard = board;
        Piece *tempPiece = tempBoard.getPieceAt(move.first->getX(), move.first->getY());

        tempBoard.movePiece(tempPiece, destX, destY, false, isCastling);

        int moveValue = -negamax(tempBoard, maxDepth_ - 1, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), -1, lastMove);

        std::cout << "Move value: " << moveValue << std::endl;

        if (moveValue > bestValue)
        {
            bestValue = moveValue;
            bestMove = move;
            if (isCastling)
                std::cout << "AI selects castling move.\n";
        }
    }

    std::cout << "AI selected move: " << (bestMove.first ? pieceTypeToString(bestMove.first->getType()) : "None")
              << " to (" << bestMove.second.first << ", " << bestMove.second.second << ")\n";

    return bestMove;
}
int AIPlayer::negamax(Board &board, int depth, int alpha, int beta, int colorMultiplier, const std::pair<Piece *, std::pair<int, int>> &lastMove)
{
    PieceColor currentColor = (colorMultiplier == 1) ? aiColor_ : (aiColor_ == PieceColor::White ? PieceColor::Black : PieceColor::White);

    if (depth == 0 || board.isInsufficientMaterial())
    {
        return colorMultiplier * evaluateBoard(board);
    }

    if (!board.hasValidMoves(currentColor))
    {
        if (board.isKingInCheck(currentColor))
        {
            return -100000 + depth;
        }
        else
        {
            return 0;
        }
    }

    int maxEval = std::numeric_limits<int>::min();
    auto possibleMoves = getAllPossibleMoves(board, currentColor, lastMove);

    for (auto &move : possibleMoves)
    {
        Board tempBoard = board;
        Piece *tempPiece = tempBoard.getPieceAt(move.first->getX(), move.first->getY());

        bool isCastling = false;
        if (tempPiece->getType() == PieceType::King && std::abs(move.second.first - tempPiece->getX()) == 2)
        {
            isCastling = true;
        }

        tempBoard.movePiece(tempPiece, move.second.first, move.second.second, false, isCastling);

        int eval = -negamax(tempBoard, depth - 1, -beta, -alpha, -colorMultiplier, lastMove);

        maxEval = std::max(maxEval, eval);
        alpha = std::max(alpha, eval);

        if (alpha >= beta)
            break;
    }
    return maxEval;
}

int AIPlayer::evaluateBoard(const Board &board)
{
    int score = 0;

    const std::unordered_map<PieceType, int> pieceValues = {
        {PieceType::Pawn, 100},
        {PieceType::Knight, 320},
        {PieceType::Bishop, 330},
        {PieceType::Rook, 500},
        {PieceType::Queen, 900},
        {PieceType::King, 20000}};

    for (const auto &piece : board.getPieces())
    {
        int value = pieceValues.at(piece->getType());
        int x = piece->getX();
        int y = piece->getY();

        if (piece->getColor() == PieceColor::Black)
        {
            x = 7 - x;
            y = 7 - y;
        }

        int positionValue = 0;
        switch (piece->getType())
        {
        case PieceType::Pawn:
            positionValue = PieceSquareTables::pawnTable[y][x];
            break;
        case PieceType::Knight:
            positionValue = PieceSquareTables::knightTable[y][x];
            break;
        case PieceType::Bishop:
            positionValue = PieceSquareTables::bishopTable[y][x];
            break;
        case PieceType::Rook:
            positionValue = PieceSquareTables::rookTable[y][x];
            break;
        case PieceType::Queen:
            positionValue = PieceSquareTables::queenTable[y][x];
            break;
        case PieceType::King:
            positionValue = PieceSquareTables::kingTable[y][x];
            break;
        }

        if (piece->getColor() == aiColor_)
        {
            score += value + positionValue;
        }
        else
        {
            score -= value + positionValue;
        }
    }

    return score;
}

std::vector<std::pair<Piece *, std::pair<int, int>>> AIPlayer::getAllPossibleMoves(Board &board, PieceColor color, const std::pair<Piece *, std::pair<int, int>> &lastMove)
{
    std::vector<std::pair<Piece *, std::pair<int, int>>> moves;

    for (const auto &piece : board.getPieces())
    {
        if (piece->getColor() == color)
        {
            auto validMoves = board.getValidMoves(piece.get(), lastMove);
            for (const auto &move : validMoves)
            {
                moves.emplace_back(piece.get(), move);
            }
        }
    }

    return moves;
}
