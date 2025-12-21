#pragma once

#include "Board.h"
#include "Input.h"
#include "UI.h"

#include <array>

class Game{
public:
    std::string message;

    Game();

    /**
     * @brief Realize game loop.
     */
    void game_turn();
    void update();
    const Board& get_board() const;
    const int get_player() const;

private:
    Board board;
    Input input;
    UI ui;
    int player; // the player that is playing in this turn (player1: player=1, black; player2: player=-1, white)
    std::array<int, 2> get_input();
    /**
     * @return true: this position is empty, false:this position already have piece
     */
    bool check_position(std::array<int, 2>);
    /**
     * @return true: this player win; false: the game is playing
     */
    bool check_win();
    void switch_player();
    void write_message(std::string);
    void clear_message();
};