#ifndef COLORS_H
#define COLORS_H

#include <iostream>

// Definition in colors.cpp

struct Color {
    // wider defaults
    std::string NC = "\033[0m"; // default
    std::string BOLD = "\033[1m"; // bold
    std::string ITALICIZE = "\033[3m"; //italicize
    std::string UNDERLINE = "\033[4m"; // underlining

    // default
    std::string BLACK = "\033[30m"; // black coloring
    std::string RED = "\033[31m"; // red coloring
    std::string GREEN = "\033[32m"; // green coloring
    std::string ORANGE = "\033[33m"; // orange coloring
    std::string BLUE = "\033[34m"; // blue coloring
    std::string PURPLE = "\033[35m"; // purple coloring
    std::string CYAN = "\033[36m"; // cyan coloring
    std::string LIGHTGRAY = "\033[37m"; // lightgray coloring
    
    // bold
    std::string BOLD_BLACK = "\033[1;30m";
    std::string BOLD_RED = "\033[1;31m";
    std::string BOLD_GREEN = "\033[1;32m";
    std::string BOLD_ORANGE = "\033[1;33m";
    std::string BOLD_BLUE = "\033[1;34m";
    std::string BOLD_PURPLE = "\033[1;35m";
    std::string BOLD_CYAN = "\033[1;36m";
    std::string BOLD_LIGHTGRAY = "\033[1;37m";
    
    // italicize
    std::string ITALICIZE_BLACK = "\033[3;30m";
    std::string ITALICIZE_RED = "\033[3;31m";
    std::string ITALICIZE_GREEN = "\033[3;32m";
    std::string ITALICIZE_ORANGE = "\033[3;33m";
    std::string ITALICIZE_BLUE = "\033[3;34m";
    std::string ITALICIZE_PURPLE = "\033[3;35m";
    std::string ITALICIZE_CYAN = "\033[3;36m";
    std::string ITALICIZE_LIGHTGRAY = "\033[3;37m";

    // underline
    std::string UNDERLINE_BLACK = "\033[4;30m";
    std::string UNDERLINE_RED = "\033[4;31m";
    std::string UNDERLINE_GREEN = "\033[4;32m";
    std::string UNDERLINE_ORANGE = "\033[4;33m";
    std::string UNDERLINE_BLUE = "\033[4;34m";
    std::string UNDERLINE_PURPLE = "\033[4;35m";
    std::string UNDERLINE_CYAN = "\033[4;36m";
    std::string UNDERLINE_LIGHTGRAY = "\033[4;37m";
    
};

#endif