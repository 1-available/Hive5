#pragma once

#include <iostream>

class Game;
class Board;

class UI{
public:
    UI();       
    void clear_page();
    void display_game(const Game& game);
    void display_board(const Board& board);
    void display_string(const std::string& str);

private:

};