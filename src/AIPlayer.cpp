#include "AIPlayer.h"
#include <limits>
#include <algorithm>
#include <unordered_map>

AIPlayer::AIPlayer(PieceColor aiColor)
    : aiColor_(aiColor), maxDepth_(3)
{
}

// piece square tables taken from https://github.com/terredeciels/TSCP/blob/master/eval.c

const int pawnTable[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {5, 10, 15, 20, 20, 15, 10, 5},
    {4, 8, 12, 16, 16, 12, 8, 4},
    {3, 6, 9, 12, 12, 9, 6, 3},
    {2, 4, 6, 8, 8, 6, 4, 2},
    {1, 2, 3, -10, -10, 3, 2, 1},
    {0, 0, 0, -40, -40, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};
const int rookTable[8][8] = {
    {32, 42, 32, 51, 63, 9, 31, 43},
    {27, 32, 58, 62, 80, 67, 26, 44},
    {-5, 19, 26, 36, 17, 45, 61, 16},
    {-24, -11, 7, 26, 24, 35, -8, -20},
    {-36, -26, -12, -1, 9, -7, 6, -23},
    {-45, -25, -16, -17, 3, 0, -5, -33},
    {-44, -16, -20, -9, -1, 11, -6, -71},
    {-19, -13, 1, 17, 16, 7, -37, -26}};

const int knightTable[8][8] = {
    {-10, -10, -10, -10, -10, -10, -10, -10},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, 0, 5, 5, 5, 5, 0, -10},
    {-10, 0, 5, 10, 10, 5, 0, -10},
    {-10, 0, 5, 10, 10, 5, 0, -10},
    {-10, 0, 5, 5, 5, 5, 0, -10},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, -30, -10, -10, -10, -10, -30, -10}};

const int bishopTable[8][8] = {
    {-10, -10, -10, -10, -10, -10, -10, -10},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, 0, 5, 5, 5, 5, 0, -10},
    {-10, 0, 5, 10, 10, 5, 0, -10},
    {-10, 0, 5, 10, 10, 5, 0, -10},
    {-10, 0, 5, 5, 5, 5, 0, -10},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, -10, -20, -10, -10, -20, -10, -10}};

const int kingTable[8][8] = {
    {-40, -40, -40, -40, -40, -40, -40, -40},
    {-40, -40, -40, -40, -40, -40, -40, -40},
    {-40, -40, -40, -40, -40, -40, -40, -40},
    {-40, -40, -40, -40, -40, -40, -40, -40},
    {-40, -40, -40, -40, -40, -40, -40, -40},
    {-40, -40, -40, -40, -40, -40, -40, -40},
    {-20, -20, -20, -20, -20, -20, -20, -20},
    {0, 20, 40, -20, 0, -20, 40, 20}};

const int queenTable[8][8] = {
    {-20, -10, -10, -5, -5, -10, -10, -20},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, 0, 5, 5, 5, 5, 0, -10},
    {-5, 0, 5, 5, 5, 5, 0, -5},
    {0, 0, 5, 5, 5, 5, 0, 0},
    {-10, 5, 5, 5, 5, 5, 0, -10},
    {-10, 0, 5, 0, 0, 0, 0, -10},
    {-20, -10, -10, -5, -5, -10, -10, -20}};

std::pair<Piece *, std::pair<int, int>>
AIPlayer::getBestMove(Board &board, const std::pair<Piece *, std::pair<int, int>> &lastMove)
{
    int bestValue = std::numeric_limits<int>::min();
    std::pair<Piece *, std::pair<int, int>> bestMove = {nullptr, {-1, -1}};

    // all possible moves for AI
    auto possibleMoves = getAllPossibleMoves(board, aiColor_, lastMove);

    for (auto &move : possibleMoves)
    {
        // copy of board to simulate move
        Board tempBoard = board;
        Piece *tempPiece = tempBoard.getPieceAt(move.first->getX(), move.first->getY());
        tempBoard.movePiece(tempPiece, move.second.first, move.second.second, false, false);

        // evaluate game using negamax
        int moveValue = -negamax(tempBoard, maxDepth_ - 1, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), -1, lastMove);

        if (moveValue > bestValue)
        {
            bestValue = moveValue;
            bestMove = move;
        }
    }

    return bestMove;
}

int AIPlayer::negamax(Board &board, int depth, int alpha, int beta, int colorMultiplier, const std::pair<Piece *, std::pair<int, int>> &lastMove)
{
    if (depth == 0 || board.isInsufficientMaterial() || !board.hasValidMoves(PieceColor::White) || !board.hasValidMoves(PieceColor::Black))
    {
        return colorMultiplier * evaluateBoard(board);
    }

    int maxEval = std::numeric_limits<int>::min();
    auto possibleMoves = getAllPossibleMoves(board, colorMultiplier == 1 ? aiColor_ : (aiColor_ == PieceColor::White ? PieceColor::Black : PieceColor::White), lastMove);

    for (auto &move : possibleMoves)
    {
        Board tempBoard = board;
        Piece *tempPiece = tempBoard.getPieceAt(move.first->getX(), move.first->getY());
        tempBoard.movePiece(tempPiece, move.second.first, move.second.second, false, false);

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
            positionValue = pawnTable[y][x];
            break;
        case PieceType::Knight:
            positionValue = knightTable[y][x];
            break;
        case PieceType::Bishop:
            positionValue = bishopTable[y][x];
            break;
        case PieceType::Rook:
            positionValue = rookTable[y][x];
            break;
        case PieceType::Queen:
            positionValue = queenTable[y][x];
            break;
        case PieceType::King:
            positionValue = kingTable[y][x];
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
