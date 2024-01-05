#include <iostream>
#include "Sleep.cpp"
#include "Input.cpp"
#include "GameField.hpp"

#define GameSpeed 500

int main() {

    GameField gameField;
    gameField.Init();

    bool lose = false;
    int lastKey;
    while (!lose)
    {
        lastKey = InputKey();

        if (lastKey == K_ESC) {
            return 0;
        }

        gameField.print();

        Sleep(GameSpeed);
    }

    return 0;
}
