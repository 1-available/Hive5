#include "AI.h"
#include <random>

std::array<int, 2> AI::place_piece(Board board, int player){
    //return random_place_piece(board, player);
    return calculate_piece(board, player);
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

std::array<int, 2> AI::calculate_piece(Board board, int player){
    std::array<int, 2> current_position;
    int current_score;
    std::array<int, 2> maximum_position = {7, 7};
    int maximum_score = 0;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (board.get_piece(i, j) == 0)
            {
                current_position = {i, j};
                current_score = calculate_score(board, current_position, player);
                if (current_score > maximum_score)
                {
                    maximum_score = current_score;
                    maximum_position = current_position;
                }
            }
        }
    }
    return maximum_position;
}

int AI::calculate_score(Board board, std::array<int, 2> position, int player){
    int my_score = 0;
    int opponent_score = 0;
    int location_score = 15 - (std::abs(position[0] - 7) + std::abs(position[1] - 7));
    for (int i = 0; i < 4; i++)
    {
        my_score += shape_score(Shape::getShapeType(Shape::getShape(board, position, player, i)));
        opponent_score += shape_score(Shape::getShapeType(Shape::getShape(board, position, player * (-1), i)));
    }
    int score = my_score * 1.3 + opponent_score + location_score;
    return score;
}

int AI::shape_score(ShapeType type){
    int score;
    if (type == ShapeType::OVERLINE)
    {
        score = 500001;
    }else if (type == ShapeType::FIVE)
    {
        score = 500000;
    }else if (type == ShapeType::LIVE_FOUR)
    {
        score = 25000;
    }else if (type == ShapeType::SLEEP_FOUR)
    {
        score = 5000;
    }else if (type == ShapeType::DOUBLE_SLEEP_FOUR)
    {
        score = 5000;
    }else if (type == ShapeType::LIVE_THREE)
    {
        score = 2500;
    }else if (type == ShapeType::SLEEP_THREE)
    {
        score = 500;
    }else if (type == ShapeType::LIVE_TWO)
    {
        score = 100;
    }else if (type == ShapeType::NONE)
    {
        score = 10;
    }
    return score;
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