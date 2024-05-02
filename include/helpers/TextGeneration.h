#ifndef TEXTGENERATION_H
#define TEXTGENERATION_H

#include "Colors.h"
#include "Times.h"
#include <string>

struct TextGenerator {
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
    // offers same functionality as procedurallyPrintSetter, however without
    // procerually printing.
    void printSetter(const std::string &text, const std::string &color,
                     const bool &escape) {
        Color colors;

        std::cout << color << text;

        if (escape)
            std::cout << colors.NC;
    }
    // procedurally generate text with specified time gap
};

#endif
