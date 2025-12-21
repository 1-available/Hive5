#include "Game.h"
#include "Board.h"
#include "Input.h"

#include <iostream>
#include <array>

Game::Game() {
    player = 1;
}

void Game::game_turn(){
    // 显示一张空棋盘
    display_board();
    while (true) {
        // 获取用户输入
        std::array<int, 2> position;
        position = get_input();
        // 检查位置是否可以落子：非乱码，范围内（否则position={-1,-1}），无子
        // 如果可以落子，修改棋盘，换玩家
        if ((position[0] != -1) && check_position(position)) {
            // 改棋盘
            board.add_piece(position[0], position[1], player);
            // 展示改完后的棋盘
            display_board();
            // 检查输赢，如果赢了跳出循环
            if (check_win()) {
                return;
            } else {
                // 切换玩家
                switch_player();
            }
        }
        // 如果不可以，什么都不做
    }
}

void Game::display_board(){
    board.display_board();
}

std::array<int, 2> Game::get_input(){
    return input.get_input();
}

bool Game::check_win(){
    // @todo
    return false;
}

void Game::switch_player(){
    if (player == 1)
    {
        player = -1;
    } else if (player == -1)
    {
        player = 1;
    } else
    {
        std::cout << "Something is wrong, please look around if there is a third player..." << std::endl;
    }
}

bool Game::check_position(std::array<int, 2> position){
    if (board.get_piece(position[0], position[1]) == 0){
        return true;
    } else {
        std::cout << "输入非法，该位置已有棋子" << std::endl;
        return false;
    }
}