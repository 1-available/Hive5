#include "Input.h"

#include <iostream>
#include <array>
#include <string>
#include <cctype>

Message::Message(){
    request_type = 0;
    input_position = {-1, -1};
}

Message Input::get_input() {
    Message message;
    std::array<int, 2> input_result = { -1, -1 };

    std::string input;
    //std::cout << "请输入坐标（例： A1 或 1A）：" << std::endl;
    std::cin >> input;

    if ((input == "Q") || (input == "q"))
    {
        message.request_type = 1;
        return message;
    }else if ((input == "S") || (input == "s"))
    {
        message.request_type = 2;
        return message;
    }

    char letter = 0;
    int number = -1;
    bool hasInputChar = false;

    // Parse input, order-independent
    for (char c : input) {
        if (std::isalpha(c)) {
            if (hasInputChar) {
                message.request_type = 3;
                return message;
            }
            letter = std::toupper(c);
            hasInputChar = true;
        } else if (std::isdigit(c)) {
            number = (number == -1) ? (c - '0') : number * 10 + (c - '0');
        }
    }

    // Validate letter and number range
    if (letter >= 'A' && letter <= 'O' && number >= 1 && number <= 15) {
        int col = letter - 'A';   // A-O -> 0-14
        int row = number - 1;     // 1-15 -> 0-14
        input_result = { row, col };
        message.input_position = input_result;
        return message;
    } else {
        message.request_type = 3;
        return message;
        //std::cerr << "输入非法，请输入 A1 到 O15 范围内的坐标。" << std::endl;
    }
}
