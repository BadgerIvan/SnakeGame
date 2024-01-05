#include "GameField.hpp"
#include <iostream>

void GameField::print() {
    std::string temp = "";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp += field[i][j];
        }
        temp += "\n";
    }
    std::cout << temp;
}

void GameField::Init() {

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            field[i][j] = ' ';
        }
    }

    for (int i = 0; i < height; i += height - 1) {
        for (int j = 0; j < width; j++) {
            field[i][j] = '-';
        }
    }

    for (int i = 0; i < width; i += width - 1) {
        for (int j = 1; j < height - 1; j++) {
            field[j][i] = '|';
        }
    }

    field[1][1] = '0';
}