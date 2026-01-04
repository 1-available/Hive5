#pragma once

#include "Board.h"

class Referee{
public:
    /**
     * @return 0:继续进行；1：player1 win；2：player2 win；3：棋盘已满，平局
     */
    static int check_win(Board board, std::array<int, 2> position);
    /**
     * @brief 检查刚才下的子position是否造成禁手
     * @return true:黑棋造成禁手；false:白棋或黑棋未禁手
     */
    static bool prohibited_move(Board board, std::array<int, 2> position, int player);
private:
    static bool prohibited_overline(Board board, std::array<int, 2> position);
    static bool prohibited_double_four(Board board, std::array<int, 2> position);
    static bool prohibited_double_three(Board board, std::array<int, 2> position);
};