#ifndef TIMES_H
#define TIMES_H

#include "Colors.h"
#include <iostream>
#include <ostream>
#include <string>
#include <thread>

// helper struct to define all time related functions

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

    // procedurally generate text with specified time gap and color
    // fourth parameter is an option for clearing current color
    // this function is also used for used for setting color precedence
    // for following text
    void procedurallyPrintSetter(const std::string &text, const int &time,
                                 const std::string &color, const bool &escape) {
        Color colors;

        std::cout << color;
        procedurallyPrint(text, time);

        if (escape)
            std::cout << colors.NC;
    }
    // procedurally generate text with specified time gap
    void procedurallyPrint(const std::string &text, const int &time) {
        const auto definedTime = std::chrono::milliseconds(time);

        for (int i = 0; i < text.length(); i++) {
            std::this_thread::sleep_for(definedTime);
            std::cout << text[i] << std::flush;
        }
    }

    void glitchedColorText(const std::string &text, const int &time) {
        Color colors;

        for (int i = 0; i < text.length(); i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            std::cout << colors.RED << text[i] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            std::cout << colors.GREEN << text[i] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            std::cout << colors.BLUE << text[i] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            std::cout << colors.PURPLE << text[i] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            std::cout << colors.CYAN << text[i] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            std::cout << colors.LIGHTGRAY << text[i] << std::flush;
        }
    }
};

#endif
