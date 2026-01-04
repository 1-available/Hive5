#include <iostream>
#include <array>

#include "Board.h"
#include "Game.h"

int main() {

    Game game;
    game.init_game();
    game.game_turn();

    return 0;
}