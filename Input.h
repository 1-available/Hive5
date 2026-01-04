#pragma once

#include <array>

class Message{
public:
    int request_type; // 0: get a position, 1: quit, 2: surrender, 3: illegal input
    std::array<int, 2> input_position;

    Message();
};

class Input{
public:
    /**
     * @return message.input_position == {-1, -1} if illegal
     */
    Message get_input();
};