#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <memory>

#include "Piece.hpp"
#include "Board.hpp"

class Player {
public:

    Player(Board* board, bool isWhite, bool isUser);
    Player(){};
    bool isWhite();
    void setHasTurn(bool hasTurn);
    void initializePieces();
    std::vector<std::vector<Move>> getValidMoves(Board &board);
    std::vector<Move> getValidMovePiece(Board &board, int index); // do testów
    void printPlayer(); // testy
    void movePiece(Board &board, Player &opponent, Move move);
    std::shared_ptr<Piece> findPiece(Position pos);
    void erasePiece(std::shared_ptr<Piece> piece);
    void changePiece(std::shared_ptr<Piece> piece, Position pos);
    void addPiece(bool isKing, Position pos, Board &board); //tylko do testow
    std::vector<std::shared_ptr<Piece>> getPieces(); //tylko do testow
    

private:
    std::vector<std::shared_ptr<Piece>> pieces_;
    Board* board_;
    bool hasTurn_;
    bool isWhite_;
    bool isUser_;
};

#endif  // PLAYER_HPP