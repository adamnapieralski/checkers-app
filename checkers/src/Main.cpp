#include <iostream>

//#include "Pawn.hpp"
//#include "Piece.hpp"
//#include "Checkers.hpp"
#include "Player.hpp"
#include "Board.hpp"

int main() {

    //Checkers ch = Checkers(true);

    Board board = Board();
    std::cout << "Drukuje tablice" << std::endl;
    std::cout << board << std::endl;
    std::cout << board.getFEN() << std::endl;


    Player user = Player(&board, true, true);
    user.initializePieces();

    std::cout << board << std::endl;
    std::cout << board.getFEN() << std::endl;

    user.getValidMoves(board);


    Player computer = Player(&board, false, false);
    computer.initializePieces();

    std::cout << board << std::endl;
    
    std::cout << board.getFEN() << std::endl;

    //std::cout << ch.findTile("s") << std::endl;

    return 0;
}