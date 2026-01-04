#include "Referee.h"
#include "Shape.h"

int Referee::check_win(Board board, std::array<int, 2> position){
    int player = board.get_piece(position[0], position[1]);
    for (int i = 0; i < 4; i++)
    {
        if ((Shape::getShapeType(Shape::getShape(board, position, i)) == ShapeType::FIVE) || (Shape::getShapeType(Shape::getShape(board, position, i)) == ShapeType::OVERLINE))
        {
            if (player == 1)
            {
                return 1;
            }else if (player == -1)
            {
                return 2;
            }
        }
    }
    int empty_position = 0;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (board.get_piece(i, j) == 0)
            {
                empty_position += 1;
            } 
        }
    }
    if (empty_position == 0)
    {
        return 3;
    }else
    {
        return 0;
    }
}

bool Referee::prohibited_move(Board board, std::array<int, 2> position, int player){
    if (player == -1)
    {
        return false;
    }
    // else: player == 1
    for (int i = 0; i < 4; i++)
    {
        if (Shape::getShapeType(Shape::getShape(board, position, player, i)) == ShapeType::FIVE)
        {
            return false;
        }
    }
    // not directly win
    if (prohibited_overline(board, position) || prohibited_double_four(board, position) || prohibited_double_three(board, position))
    {
        return true;
    }else
    {
        return false;
    }
}

bool Referee::prohibited_overline(Board board, std::array<int, 2> position){
    for (int i = 0; i < 4; i++)
    {
        if (Shape::getShapeType(Shape::getShape(board, position, 1, i)) == ShapeType::OVERLINE)
        {
            return true;
        }
    }
    return false;
}

bool Referee::prohibited_double_four(Board board, std::array<int, 2> position){
    int double_four_number = 0;
    for (int i = 0; i < 4; i++)
    {
        if (Shape::getShapeType(Shape::getShape(board, position, 1, i)) == ShapeType::DOUBLE_SLEEP_FOUR)
        {
            return true;
        }else if ((Shape::getShapeType(Shape::getShape(board, position, 1, i)) == ShapeType::LIVE_FOUR) || (Shape::getShapeType(Shape::getShape(board, position, 1, i)) == ShapeType::SLEEP_FOUR))
        {
            double_four_number += 1;
        }
    }
    if (double_four_number >= 2)
    {
        return true;
    }else
    {
        return false;
    }
}

bool Referee::prohibited_double_three(Board board, std::array<int, 2> position){
    int double_three_number = 0;
    for (int i = 0; i < 4; i++)
    {
        if (Shape::getShapeType(Shape::getShape(board, position, 1, i)) == ShapeType::LIVE_THREE)
        {
            double_three_number += 1;
        }
    }
    if (double_three_number >= 2)
    {
        return true;
    }else
    {
        return false;
    }
}