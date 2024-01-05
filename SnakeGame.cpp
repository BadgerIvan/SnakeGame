#include <iostream>
#include "Sleep.cpp"
#include "Input.cpp"

#define width 119
#define height 29

#define GameSpeed 500

void PrintGameField(char(&a)[height][width]) {
    std::string temp = "";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp += a[i][j];
        }
        temp += "\n";
    }
    std::cout << temp;
}

int main() {

    char gameField[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            gameField[i][j] = ' ';
        }
    }

    for (int i = 0; i < height; i += height - 1) {
        for (int j = 0; j < width; j++) {
            gameField[i][j] = '-';
        }
    }

    for (int i = 0; i < width; i += width - 1) {
        for (int j = 1; j < height - 1; j++) {
            gameField[j][i] = '|';
        }
    }

    gameField[1][1] = '0';

    bool lose = false;
    int lastKey;
    while (!lose)
    {
        lastKey = InputKey();

        if (lastKey == K_ESC) {
            return 0;
        }

        PrintGameField(gameField);
        Sleep(GameSpeed);
    }
}
