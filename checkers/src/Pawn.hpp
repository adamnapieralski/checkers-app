#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece {
    using Piece::Piece;
    
public:
    Pawn(Position pos, bool isWhite, Board& board);

    void getCaptureMoves(std::vector<Move> &moves, Board board, Move current);
    void canCapture(std::vector<Move> &moves, Board board, Move current) override;
    std::vector<Move> getValidMoves(Board& board, bool mustCaputer=false) override;

    std::ostream& print(std::ostream&) override;
};

#endif  // PAWN_HPP