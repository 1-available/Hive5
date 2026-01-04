#pragma once
#include "Board.h"
#include "Shape.h"

class AI{
public:
    /**
     * Calculate piece position (strategy1: randomly palce a piece, strategy2: calculate piece with maximum position score).
     */
    std::array<int, 2> place_piece(Board board, int player);
    int calculate_score(Board board, std::array<int, 2> position, int player);
private:
    std::array<int, 2> random_place_piece(Board board, int player);
    std::array<int, 2> calculate_piece(Board board, int player);
    
    int shape_score(ShapeType type);
    int get_random(int min, int max);
    bool check_position(Board board, int x, int y);
};