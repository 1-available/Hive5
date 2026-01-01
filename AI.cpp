#include "AI.h"
#include <random>

std::array<int, 2> AI::place_piece(Board board, int player){
    return random_place_piece(board, player);
}

std::array<int, 2> AI::random_place_piece(Board board, int player){
    // 获取[0-14]之间随机整数，作为row x
    int x = get_random(0, 14);
    // 再获取一次，作为order y
    int y = get_random(0, 14);
    // 检测是否可以落子，如果可以落子，return {x, y}
    if (check_position(board, x, y))
    {
        return {x, y};
    }else  // 如果不可以继续random_place_piece
    {
        return random_place_piece(board, player);
    }
}

int AI::get_random(int min, int max){
    // static 保证随机引擎只初始化一次
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);

    return distrib(gen);
}

bool AI::check_position(Board board, int x, int y){
    return board.get_piece(x, y) == 0;
}