#ifndef TIMES_H
#define TIMES_H

#include <iostream>
#include <ostream>
#include <string>
#include <thread>

struct Time {
    // produce time in x seconds
    void seconds(const int &seconds) {
        const auto definedSeconds = std::chrono::seconds(seconds);
        std::this_thread::sleep_for(definedSeconds);
    }
    // produce time in x milliseconds
    void milliseconds(const int &milliseconds) {
        const auto definedMilliseconds =
            std::chrono::milliseconds(milliseconds);
        std::this_thread::sleep_for(definedMilliseconds);
    }
    void procedurallyPrintText(const std::string &text, const int &time) {
        const auto definedTime = std::chrono::milliseconds(time);

        for (int i = 0; i < text.length(); i++) {
            std::this_thread::sleep_for(definedTime);
            std::cout << text[i] << std::flush;
        }
    }
};

#endif
