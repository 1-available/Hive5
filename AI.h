#pragma once
#include "Board.h"

class AI{
public:
    /**
     * Calculate piece position (strategy: randomly palce a piece).
     */
    std::array<int, 2> place_piece(Board board, int player);
private:
    std::array<int, 2> random_place_piece(Board board, int player);
    int get_random(int min, int max);
    bool check_position(Board board, int x, int y);
};