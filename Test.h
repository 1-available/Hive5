#pragma once

#include "Board.h"
#include "Shape.h"
#include "UI.h"
#include "AI.h"

class Test{
public:
    static void shapeTest() {
        UI ui;
        AI ai;
        Board board;
        board.add_piece(7, 7, 1);
        board.add_piece(0, 0, -1);
        Shape shape0 = Shape::getShape(board, {7,9}, 1, 0);
        int a = ai.calculate_score(board, {7,9},1);
        int b = ai.calculate_score(board, {7,9},-1);
        ui.display_board(board);
    }
};