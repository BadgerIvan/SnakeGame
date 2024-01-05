#ifndef SLEEP_CPP
#define SLEEP_CPP

#include <iostream>
#include <chrono>
#include <thread>

void Sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

#endif //SLEEP_CPP