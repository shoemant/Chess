#include "AIPlayer.h"
#include "PieceSquareTables.h"
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include "Utilities.h"

// constructor
AIPlayer::AIPlayer(PieceColor aiColor)
    : aiColor_(aiColor), maxDepth_(3)
{
}

// get best move for ai
Move AIPlayer::getBestMove(Board &board, const std::pair<Piece *, std::pair<int, int>> &lastMove)
{
    int bestValue = std::numeric_limits<int>::min();
    Move bestMove;

    auto possibleMoves = getAllPossibleMoves(board, aiColor_, lastMove);

    for (auto &move : possibleMoves)
    {
        Board tempBoard = board;
        Piece *tempPiece = tempBoard.getPieceAt(move.startX, move.startY);
        bool isCastling = (move.pieceType == PieceType::King && std::abs(move.endX - move.startX) == 2);

        tempBoard.movePiece(tempPiece, move.endX, move.endY, false, isCastling);

        int moveValue = -negamax(tempBoard, maxDepth_ - 1, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), -1, lastMove);

        if (moveValue > bestValue)
        {
            bestValue = moveValue;
            bestMove = move;
        }
    }

    return bestMove;
}

// negamax algorithm with alpha-beta pruning
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

    // sort moves based on heuristic to improve pruning
    sort(possibleMoves.begin(), possibleMoves.end(), [this](const Move &a, const Move &b)
         {
             int scoreA = moveOrderingHeuristic(a);
             int scoreB = moveOrderingHeuristic(b);
             return scoreA > scoreB; });

    for (auto &move : possibleMoves)
    {
        Board tempBoard = board;
        Piece *tempPiece = tempBoard.getPieceAt(move.startX, move.startY);
        if (!tempPiece)
        {

            continue;
        }

        bool isCastling = false;
        if (move.pieceType == PieceType::King && std::abs(move.endX - move.startX) == 2)
        {
            isCastling = true;
        }

        tempBoard.movePiece(tempPiece, move.endX, move.endY, false, isCastling);

        int eval = -negamax(tempBoard, depth - 1, -beta, -alpha, -colorMultiplier, lastMove);

        maxEval = std::max(maxEval, eval);
        alpha = std::max(alpha, eval);

        if (alpha >= beta)
            break;
    }

    return maxEval;
}

// heuristic for ordering moves
int AIPlayer::moveOrderingHeuristic(const Move &move)
{
    int score = 0;

    if (move.isCapture)
        score += 1000;

    if (move.pieceType == PieceType::King && std::abs(move.endX - move.startX) == 2)
        score += 900;

    if (move.isPromotion)
        score += 800;

    return score;
}

// evaluate the board state
int AIPlayer::evaluateBoard(const Board &board)
{
    int score = 0;

    // define piece values
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

        // add positional value based on piece type
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

        if (piece->getType() == PieceType::King)
        {
            if (!piece->hasMoved())
            {
                if (piece->getColor() == aiColor_)
                {
                    score -= 30;
                }
                else
                {
                    score += 30;
                }
            }
        }
        // adjust score based on king's movement
        if (piece->getType() == PieceType::King)
        {
            if (piece->hasMoved())
            {
                int kingX = piece->getX();
                int kingY = piece->getY();

                bool castledPosition = (kingX == 6 || kingX == 2) && (kingY == 0 || kingY == 7);
                if (castledPosition)
                {
                    if (piece->getColor() == aiColor_)
                    {
                        score += 50;
                    }
                    else
                    {
                        score -= 50;
                    }
                }
            }
        }
    }

    // prioritize king safety
    score += evaluateKingSafety(board, aiColor_);
    score -= evaluateKingSafety(board, aiColor_ == PieceColor::White ? PieceColor::Black : PieceColor::White);

    return score;
}

// evaluates king safety based on position, cover, pawn structure
int AIPlayer::evaluateKingSafety(const Board &board, PieceColor color)
{
    int safetyScore = 0;
    Piece *king = nullptr;

    for (const auto &piece : board.getPieces())
    {
        if (piece->getType() == PieceType::King && piece->getColor() == color)
        {
            king = piece.get();
            break;
        }
    }

    if (!king)
        return safetyScore;

    int kingX = king->getX();
    int kingY = king->getY();

    if (kingY < 2 || kingY > 5)
        safetyScore += 20;
    else
        safetyScore -= 20;

    if (!king->hasMoved())
        safetyScore -= 50;

    return safetyScore;
}

// returns a vector of all possible moves a piece can make
std::vector<Move> AIPlayer::getAllPossibleMoves(Board &board, PieceColor color, const std::pair<Piece *, std::pair<int, int>> &lastMove)
{
    std::vector<Move> moves;
    for (const auto &piece : board.getPieces())
    {
        if (piece->getColor() == color)
        {
            auto validMoves = board.getValidMoves(piece.get(), lastMove);
            for (const auto &move : validMoves)
            {
                if (piece->getType() == PieceType::King && !piece->hasMoved())
                {
                    int dx = move.first - piece->getX();
                    int dy = move.second - piece->getY();

                    if (dy == 0 && std::abs(dx) == 1)
                    {
                        if (board.canCastle(color, dx > 0))
                            continue;
                    }
                }
                Move m;
                m.startX = piece->getX();
                m.startY = piece->getY();
                m.endX = move.first;
                m.endY = move.second;
                m.pieceType = piece->getType();
                m.pieceColor = piece->getColor();
                moves.push_back(m);
            }
        }
    }
    return moves;
}