#include <iostream>

//#include "Pawn.hpp"
//#include "Piece.hpp"
//#include "Checkers.hpp"
#include "AIPlayer.h"
#include "UserPlayer.h"
#include "Board.h"
#include "King.h"
#include "Pawn.h"
#include "GameTree.h"

int main() {
 
    Board board = Board();
    auto user = UserPlayer(true);
    auto computer = AIPlayer(false);
    computer.addPiece(false, Position(2, 2), board);
    // computer.addPiece(true, Position(3, 0), board);
    // user.addPiece(false, Position(3,3), board);
    user.addPiece(false, Position(1,1), board);
    user.addPiece(false, Position(5,3), board);
    std::cout << board << std::endl;

    auto userPieces = user.getPieces();
    auto p1 = userPieces[0];
    auto p2 = p1->clone();

    std::cout << board << std::endl;
    Move t = computer.minmax(computer, user, board);
    computer.movePiece(board, user, t);
    std::cout << board << std::endl;
    //std::vector<Piece*> newComp = computer.getPieces();
    //std::vector<Piece*> newUs = user.getPieces();*/

    return 0;
}