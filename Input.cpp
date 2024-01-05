#ifndef Input_CPP
#define Input_CPP

#include "OS.hpp"
#include "KeyCodes.hpp"

#ifdef WINDOWS

#include <Windows.h>
const unsigned char keyCodes[5] = { VK_UP, VK_DOWN, VK_RIGHT, VK_LEFT, VK_ESCAPE };

#elif LINUX

#include <iostream>
#include <termios.h>
#include <unistd.h>

#else 

#error OS is not Windows or Linux

#endif

int InputKey() {
	unsigned char key = ' ';

#ifdef WINDOWS
	for (unsigned char ell : keyCodes) {
		if(GetKeyState(ell)) {
			key =  ell;
		}
	}

	switch (key) {
	case VK_UP:
		return K_UP;
	case VK_DOWN:
		return K_DOWN;
	case VK_RIGHT:
		return K_RIGHT;
	case VK_LEFT:
		return K_LEFT;
	case VK_ESCAPE:
		return K_ESC;
	default:
		return K_NONE;
	}

#endif //WINDOWS

#ifdef LINUX
    struct termios oldt, newt;
    int ch;

    if (tcgetattr(STDIN_FILENO, &oldt) != 0) {
        std::cerr << "Error: tcgetattr failed" << std::endl;
        return 1;
    }

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) != 0) {
        std::cerr << "Error: tcsetattr failed" << std::endl;
        return 1;
    }

    ch = std::cin.get();

    if (tcsetattr(STDIN_FILENO, TCSANOW, &oldt) != 0) {
        std::cerr << "Error: tcsetattr failed" << std::endl;
        return 1;
    }

    key = (unsigned char)ch;

#endif //LINUX

}

#endif // Input_CPP
