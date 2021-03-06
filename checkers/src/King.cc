/**
 * @file King.cc
 * @brief Source file for King class, representing king piece.
 * 
 * @author Adam Napieralski
 * @author Patrycja Cieplicka
 */

#include "King.h"

King::King(Position pos, bool isWhite, bool isUser, Board& board) : Piece(pos, isWhite, isUser) {
    if (isWhite)
        board.placePiece(pos, WHITE_KING);
    else
        board.placePiece(pos, BLACK_KING);
}

std::shared_ptr<Piece> King::cloneImplementation() const {
    return std::shared_ptr<King>(new King(*this));
}



void King::captureMoves(std::vector<Move>& moves, Board board, Move current) const {
    int dy[4] = {1, 1, -1, -1};
    int dx[4] = {1, -1, -1, 1};

    auto tmpCurrent = current;
    auto tmpBoard = board;

    auto startPos = getPosition();

    int countMoves = 0;
    for (int i = 0; i < 4; ++i) {
        bool metOpponent = false;
        Position newPos(startPos.x + dx[i], startPos.y + dy[i]);
        Position capPos;
        while (newPos.isValid()) {
            auto pn = board.getPieceName(newPos);
            if (isSameColor(pn) || (metOpponent && isDiffColor(pn))) break;
            if (metOpponent && pn == EMPTY) {
                ++countMoves;
                Move tmp(startPos, newPos, capPos);

                if (current.isInitial()) current = tmp;
                else current = current.merge(tmp);

                board.makeMove(tmp);
                King k(newPos, isWhite(), isUser(), board);
                k.captureMoves(moves, board, current);
                current = tmpCurrent;
                board = tmpBoard;
            }
            if (isDiffColor(pn)) {
                if (metOpponent) break;
                else {
                    metOpponent = true;
                    capPos = newPos;
                }
            }
            newPos.x += dx[i];
            newPos.y += dy[i];
        }
    }
    if (countMoves == 0 && !current.isInitial()){
        moves.push_back(current);
    }
}

std::vector<Move> King::getCaptureMoves(Board& board) const{
    std::vector<Move> moves;

    Move move;
    captureMoves(moves, board, move);

    return moves;
}

std::vector<Move> King::getNonCaptureMoves(Board& board) const {

    std::vector<Move> moves;

    int dy[4] = {1, 1, -1, -1};
    int dx[4] = {1, -1, -1, 1};
    auto startPos = getPosition();

    for (int i = 0; i < 4; ++i) {
        Position newPos(startPos.x + dx[i], startPos.y + dy[i]);
        while (newPos.isValid() && board.getPieceName(newPos) == EMPTY) {
            moves.push_back(Move(startPos, newPos));
            newPos.x += dx[i];
            newPos.y += dy[i];
        }
    }

    return moves;
}

std::ostream& King::print(std::ostream& os) const{
    if (this->isWhite()) os << "w";
    else os << "b";
    return os;
}