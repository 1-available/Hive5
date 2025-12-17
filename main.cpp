#include <iostream>
#include <array>

#include "Board.h"

int main() {
    Board board;
    
    board.add_piece(1,1,1);
    board.add_piece(2,2,-1);
    board.add_piece(3,3,3);
    board.display_board();
    std::cout << board.get_piece(1,1) << std::endl;
    std::cout << board.get_piece(2,3) << std::endl;
    std::cout << board.get_piece(3,3) << std::endl;

    return 0;
}