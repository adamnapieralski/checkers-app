/**
 * @file Piece.cc
 * @brief Source file for abstract Piece class, representing piece.
 * 
 * @author Patrycja Cieplicka
 * @author Adam Napieralski
 */

#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Board.h"

Piece::Piece(Position pos, bool isWhite, bool isUser) :
    pos_(pos), isWhite_(isWhite), isUser_(isUser) {}

std::shared_ptr<Piece> Piece::clone() const {
    return cloneImplementation();
}

bool Piece::isWhite() const { return isWhite_;    }

bool Piece::isUser() const {  return isUser_; }

Position Piece::getPosition() const { return pos_;    }

void Piece::changePosition(Position pos){
    pos_ = pos;
}

bool Piece::isSameColor(PieceName &pn) const {
    if ( (isWhite_ && ( pn == WHITE_PAWN  || pn == WHITE_KING ) )
        || (!isWhite_ && (pn == BLACK_PAWN || pn == BLACK_KING) ) )
        return true;
    else return false;
}

bool Piece::isDiffColor(PieceName pn) const{
    if ( (isWhite_ && ( pn == BLACK_PAWN || pn == BLACK_KING) )
        || (!isWhite_ && (pn == WHITE_PAWN || pn == WHITE_KING) ) )
        return true;
    else return false;
}