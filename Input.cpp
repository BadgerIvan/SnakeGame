#ifndef Input_CPP
#define Input_CPP

#include <vector>
#include "OS.hpp"
#include "KeyCodes.hpp"

#ifdef WINDOWS

#include <Windows.h>
const unsigned char keyCodes[5] = { VK_UP, VK_DOWN, VK_RIGHT, VK_LEFT, VK_ESCAPE };

#elif LINUX
// todo input for linux
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

#endif //WINDOWS

#ifdef LINUX
// todo input for linux
#endif //LINUX

	switch (key) {
	case VK_UP:
		return K_UP;
	case VK_DOWN:
		return K_UP;
	case VK_RIGHT:
		return K_RIGHT;
	case VK_LEFT:
		return K_LEFT;
	case VK_ESCAPE:
		return K_ESC;
	default:
		return K_NONE;
	}
}

#endif // Input_CPP
