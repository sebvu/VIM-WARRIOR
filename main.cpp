#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include "./include/colors.h"
#include "./include/enemy.h"

// Global ANSI Escape Codes
Color color;

void printSword() { // Prints out sword ASCII

std::cout << color.BOLD << "      [|_________________" << std::endl
<< "0|===|<>_________________>" << std::endl
<< "      [|" << color.NC << std::endl;

}

void beginningScreenSequence() { // beginning animation-ish sequence

    auto two_seconds = std::chrono::seconds(2);
    auto one_second = std::chrono::seconds(1);

    std::cout << color.ITALICIZE_BLUE << "           The kingdom sent me here to these depths.." << std::endl << std::endl;

    std::this_thread::sleep_for(two_seconds);
    
    std::cout << color.ITALICIZE_LIGHTGRAY << "...I know nothing else" << std::endl << std::endl;
    
    std::this_thread::sleep_for(two_seconds);
    
    std::cout << color.ITALICIZE_BLACK << "               But to serve." << std::endl << std::endl;

    std::this_thread::sleep_for(two_seconds);

    std::cout << color.ITALICIZE_RED << "       As a " << color.BOLD << "warrior." << std::endl;

    std::random_device rd;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 27; j++) {
            std::uniform_int_distribution<int> dist(i, 20);
            if (dist(rd) >= 17) {
                std::uniform_int_distribution<int> dist(1,2);
                if (dist(rd) % 2 == 0)
                    std::cout << color.ITALICIZE_ORANGE;
                else
                    std::cout << color.ITALICIZE_RED;
                std::cout << "~";
            }
            else
               std::cout << " ";
            std::cout << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        std::cout << std::endl;
    }

    
}

void titleScreen() { // Begin title screen

    std::cout << std::endl << color.UNDERLINE << color.BOLD_CYAN << "PREFACE" << color.NC << std::endl // Preface going over ANSI recommendation
    << std::endl << color.GREEN << "This game is best experienced with ANSI escape codes enabled. (i.e colors!!)" << std::endl << std::endl
    << "Unix-like terminals (Linux & macOS) should have ANSI escape codes enabled by default, however Windows 10+ needs manual configuration. (correct me if im wrong :p)" << std::endl
    << std::endl << "Thank you for reading, enjoy~!" << std::endl
    << std::endl << "(\\ _ /)\n(=t.t=)" << color.NC << std::endl << std::flush; 

    auto six_seconds = std::chrono::seconds(6); // allow time for preface to be read

    std::this_thread::sleep_for(six_seconds);
    std::cout << std::endl << std::endl;

    beginningScreenSequence();

    std::cout << color.NC << std::endl << std::endl;
    printSword(); // print sword ASCII art

    std::cout << std::endl;

    std::cout << "     " << color.UNDERLINE << color.BOLD_RED << "Dungeon Warrior" << color.NC << std::endl;
}

int startOptions() {
    // std::cout << "(I) New Game"
    // std::cout << "(X) 
}

int main() {

    titleScreen(); // Initialize title screen

    startOptions(); // starting options



}