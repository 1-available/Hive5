#include "Input.h"

#include <iostream>
#include <array>
#include <string>
#include <cctype>

std::array<int, 2> Input::get_input() {
    std::array<int, 2> input_result = { -1, -1 };

    std::string input;
    std::cout << "请输入坐标（例： A1 或 1A）：" << std::endl;
    std::cin >> input;

    char letter = 0;
    int number = -1;

    // Parse input, order-independent
    for (char c : input) {
        if (std::isalpha(c)) {
            letter = std::toupper(c);
        } else if (std::isdigit(c)) {
            number = (number == -1) ? (c - '0') : number * 10 + (c - '0');
        }
    }

    // Validate letter and number range
    if (letter >= 'A' && letter <= 'O' && number >= 1 && number <= 15) {
        int col = letter - 'A';   // A-O -> 0-14
        int row = number - 1;     // 1-15 -> 0-14
        input_result = { row, col };
    } else {
        std::cerr << "输入非法，请输入 A1 到 O15 范围内的坐标。" << std::endl;
    }

    return input_result;
}
