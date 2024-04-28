#include "./include/colors.h"
#include "./include/exception.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <thread>

// Global ANSI Escape Codes
const Color color;

void printSword() {  // Prints out sword ASCII
    std::cout << color.BOLD << "      [|_________________" << std::endl
              << "0|===|<>_________________>" << std::endl
              << "      [|" << color.NC << std::endl;
}

void beginningScreenSequence() {  // beginning animation-ish sequence
    const auto two_seconds = std::chrono::seconds(2);
    const auto one_second = std::chrono::seconds(1);

    std::cout << color.ITALICIZE_BLUE
              << "           The kingdom sent me here to these depths.."
              << std::endl
              << std::endl;

    std::this_thread::sleep_for(two_seconds);

    std::cout << color.ITALICIZE_LIGHTGRAY << "...I know nothing else"
              << std::endl
              << std::endl;

    std::this_thread::sleep_for(two_seconds);

    std::cout << color.ITALICIZE_PURPLE << "               But to serve."
              << std::endl
              << std::endl;

    std::this_thread::sleep_for(two_seconds);

    std::cout << color.ITALICIZE_RED << "       As a " << color.BOLD
              << "warrior." << std::endl;

    std::random_device rd;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 27; j++) {
            std::uniform_int_distribution<int> dist(i, 20);
            if (dist(rd) >= 17) {
                std::uniform_int_distribution<int> dist(1, 2);
                if (dist(rd) % 2 == 0)
                    std::cout << color.ITALICIZE_ORANGE;
                else
                    std::cout << color.ITALICIZE_RED;
                std::cout << "~";
            } else {
                std::cout << " ";
            }
            std::cout << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        std::cout << std::endl;
    }
}

void titleScreen() {
    // Begin title screen
    std::cout
        << std::endl
        << color.UNDERLINE << color.BOLD_CYAN << "PREFACE" << color.NC
        << std::endl  // Preface going over ANSI recommendation
        << std::endl
        << color.GREEN
        << "This game is best experienced with ANSI escape codes enabled. "
           "(i.e colors!!)"
        << std::endl
        << std::endl
        << "Unix-like terminals (Linux & macOS) should have ANSI escape "
           "codes enabled by default, however Windows 10+ needs manual "
           "configuration. (correct me if im wrong :p)"
        << std::endl
        << std::endl
        << "Thank you for reading, enjoy~!" << std::endl
        << std::endl
        << "(\\ _ /)\n(=t.t=)" << color.NC << std::endl
        << std::flush;

    const auto six_seconds =
        std::chrono::seconds(6);  // allow time for preface to be read

    std::this_thread::sleep_for(six_seconds);
    std::cout << std::endl << std::endl;

    beginningScreenSequence();
}

int startOptions() {
    // Title Screen Printout
    std::cout << color.NC << std::endl << std::endl;
    printSword();  // print sword ASCII art

    std::cout << std::endl;

    std::cout << "     " << color.UNDERLINE << color.BOLD_RED
              << "Dungeon Warrior" << color.NC << std::endl;
    // Start Menu
    int choice = 0;
    while (true) {
        std::cout << "(1) New Game" << std::endl
                  << "(2) Load Game" << std::endl
                  << "(3) Exit" << std::endl
                  << std::endl
                  << "Enter your choice: ";
        if (std::cin >> choice) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (choice == 1 || choice == 2 || choice == 3) {
                return choice;
            } else {
                std::cout << "Not an option!" << std::endl;
                continue;
            }
        } else {
            std::cout << "Invalid input type, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::string appendFileDirectory(const std::string fileInput) {
    // append directory and .txt
    std::string saveGameDirectory = "./savedGames/";

    saveGameDirectory.append(fileInput).append(".txt");

    return saveGameDirectory;
}

void programExit() {
    std::cout << color.UNDERLINE << color.BOLD_CYAN << "EXITING CREDITS"
              << color.NC << std::endl
              << std::endl;
    std::cout << color.BOLD_GREEN << "Thank you for playing Dungeon Warrior!"
              << std::endl;
    // utilizing raw string literals for ASCII art
    /*

       ‼️  BE SURE TO INCLUDE SAVE GAME BEFORE EXITING
        DELETE ONCE IMPLEMENTED

    */
    std::cout << R"(
      ／l、             
    （ﾟ､ ｡ ７   Creator: Jester 💜  
      l  ~ヽ       
      じしf_,)ノ
    )" << color.NC
              << std::endl;
    // exit code 0, no errors!!
    exit(0);
}

void printCurrentSaveFiles() {
    /*
    ‼️  IMPLEMENT PRINTING OUT A LIST OF CURRENT SAVES FILES ALONG WITH DATE
    */
}

void saveGame() {
    // prompt user for save file name
    std::string savedFileName = "";
    std::cout << "Enter a name for your save file: ";
    std::cin >> savedFileName;
    std::string saveGameDirectory = appendFileDirectory(savedFileName);
    // create a save file in savedGames directory
    std::ofstream saveFile(saveGameDirectory);

    try {
        if (!saveFile.is_open()) {  // verify if file is open
            throw fileNotOpen(saveGameDirectory);
        }
    } catch (fileNotOpen &exec) {
        std::cerr << "Error: File could not be saved at" << exec.getFileName();
        std::cerr << "Please try again." << std::endl;
        saveGame();
    }
    /*
       ‼️  IMPLEMENT SAVE DATA HERE
        DELETE ONCE IMPLEMENTED
    */
}

void loadGame() {
    // Receive saveFile from user
    std::string loadedSaveFile = "";
    std::cout << "Please input a save file to load: ";
    printCurrentSaveFiles();  // load current save files
    std::cin >> loadedSaveFile;

    std::string saveGameDirectory = appendFileDirectory(loadedSaveFile);

    // load file save below
    std::ifstream loadFile(saveGameDirectory);

    try {
        if (!loadFile.is_open()) {
            throw fileNotOpen(saveGameDirectory);
        }
    } catch (fileNotOpen exec) {
        std::cerr << "Error: File not open: " << exec.getFileName();
        std::cerr << "Please choose another file." << std::endl;
        loadGame();
    }
    /*
       ‼️  IMPLEMENT LOAD DATA HERE
        DELETE ONCE IMPLEMENTED
    */
}

int main() {
    titleScreen();  // Initialize title screen

    int option = startOptions();

    switch (option) {
    case (1):  // New Game
        std::cout << "Switch case 1" << std::endl;
        break;
    case (2):  // Load Game
        std::cout << "Switch case 2" << std::endl;
        break;
    case (3):  // Exit
        std::cout << std::endl << std::endl;
        programExit();
        break;
    }
}
