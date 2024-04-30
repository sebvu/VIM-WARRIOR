/*
    EXIT CODE GUIDE:
    0 - Successful exit
    1 - Fatal program error
*/
#include "./include/BossEntity.h"
#include "./include/PlayerEntity.h"
#include "./include/helpers/Colors.h"
#include "./include/helpers/Exception.h"
#include "./include/helpers/Times.h"
#include "./include/helpers/Randomizer.h"
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ostream>
#include <random>
#include <string>

// ANSI Escape Codes for Color Control
Color color;
// Struct for Easy Time Control
Time count;
// Randomizer for easier distributions
Randomizer rando;

// pre-defining all functions
void printSword();
void beginScreenSequence();
void displayTitleScreen();
int displayStartOptions();
bool isEmptyFile(std::ifstream &pFile, const std::string &fileName);
std::string appendFileDirectory(const std::string &fileInput);
void formatFileToTracker(std::ofstream &outputTracker,
                         const std::string &fileName);
void rewriteTrackedWithoutSpecifiedFile(const std::string &fileName);
void addFileToTracker(const std::string &fileName);
void programExit();
void printCurrentSaveFiles();
void saveGame();
void loadGame();
void deleteSavedGame();
void newGameSequence();
void newGame();
// void generateMap();

// Function Definitions

void printSword() {  // Prints out sword ASCII
    std::cout << color.BOLD_RED << R"(
            ()
            )(                 (ULTRA BETA)
         o======o (FEATURES ARE NOT FULLY IMPLEMENTED YET)
            ||    
            ||
            ||
)" << color.NC << color.ORANGE

              << R"(       ,c88888888b
      ,88888888888b
      88888888888Y"
)" << color.GREEN
              << R"(,,;,,;;)" << color.ORANGE << R"("Y888888Y")" << color.GREEN
              << R"(,,,,,,,;;,;
    )";
}

void beginningScreenSequence() {  // beginning animation-ish sequence
    std::cout << color.ITALICIZE_BLUE;
    count.slowTextGenerator("The kingdom sent me here to these depths..", 20);
    count.seconds(2);
    std::cout << std::endl << std::endl;

    std::cout << color.ITALICIZE_LIGHTGRAY;
    count.slowTextGenerator("...I know nothing else", 20);
    count.seconds(2);
    std::cout << std::endl << std::endl;

    std::cout << color.ITALICIZE_BLACK;
    count.slowTextGenerator("But to serve.", 20);
    count.seconds(2);
    std::cout << std::endl << std::endl;

    std::cout << color.ITALICIZE_RED;
    count.slowTextGenerator("       As a ", 20);
    std::cout << color.BOLD;
    count.slowTextGenerator("warrior.", 20);
    std::cout << std::endl;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 27; j++) {
            if (rando.getRandomDistribution(i, 20) >= 17) {
                if (rando.getRandomDistribution(1, 2) % 2 == 0)
                    std::cout << color.ITALICIZE_ORANGE;
                else
                    std::cout << color.ITALICIZE_RED;
                std::cout << "~";
            } else {
                std::cout << " ";
            }
            std::cout << std::flush;
            count.milliseconds(5);
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

    count.seconds(6);
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
        std::cout << color.NC << color.PURPLE << "(" << color.BOLD_ORANGE << "1"
                  << color.NC << color.PURPLE << ") New Game" << std::endl
                  << "(" << color.BOLD_ORANGE << "2" << color.NC << color.PURPLE
                  << ") Load Game" << std::endl
                  << "(" << color.BOLD_ORANGE << "3" << color.NC << color.PURPLE
                  << ") Save Game" << std::endl
                  << "(" << color.BOLD_ORANGE << "4" << color.NC << color.PURPLE
                  << ") Delete Saved Game" << std::endl
                  << "(" << color.BOLD_ORANGE << "5" << color.NC << color.PURPLE
                  << ") Exit" << std::endl
                  << std::endl
                  << "Enter your choice: " << color.BOLD_CYAN;
        if (std::cin >> choice) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << color.NC << std::endl;

            if (choice == 1 || choice == 2 || choice == 3 || choice == 4 ||
                choice == 5) {
                return choice;
            } else {
                std::cout << color.BOLD_ORANGE << "Not an option!" << color.NC
                          << color.PURPLE << std::endl
                          << std::endl;
            }
        } else {
            std::cout << color.BOLD_ORANGE << std::endl
                      << "Invalid input type, please try again." << color.NC
                      << color.PURPLE << std::endl
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

bool isEmptyFile(std::ifstream &pFile, const std::string &fileName) {
    // check if file exists first
    if (!pFile.is_open()) {
        throw essentialFileNotOpen(fileName);
    }
    return pFile.peek() == std::ifstream::traits_type::eof();
}

std::string appendFileDirectory(const std::string &fileInput) {
    // append directory and .txt
    std::string saveGameDirectory = "./savedGames/";

    saveGameDirectory.append(fileInput).append(".txt");

    return saveGameDirectory;
}

void formatFileToTracker(std::ofstream &outputTracker,
                         const std::string &fileName) {
    // get current current date
    time_t now = time(0);

    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;

    outputTracker << month << "/" << day << "/" << year << " " << hour << ":"
                  << minute << " - " << fileName
                  << std::endl;  // append filename and date at end of tracker
}

void rewriteTrackedWithoutSpecifiedFile(const std::string &fileName) {
    std::string fileLine = "";
    std::string tempFile = "temporaryStorage.txt";
    std::string fileTracker = "trackedGameFiles.txt";
    // rewrite trackedGamesFile.txt without specified file
    // create temporary file to rewrite old content in,
    // then write temporary in to original fileTracker
    // delete temporary file in the end
    std::ofstream tempWriteFile(tempFile);
    if (!tempWriteFile.is_open()) {
        throw essentialFileNotOpen(tempFile);
    }
    std::ifstream newInputTracker(fileTracker);
    if (!newInputTracker.is_open()) {
        throw essentialFileNotOpen(fileTracker);
    }
    // re-add to NEW overwritten fileTracker
    while (getline(newInputTracker, fileLine)) {
        int delimeter = fileLine.find("-");  // return index of -
        std::string oldFileName =
            fileLine.substr(delimeter + 2, fileLine.size());
        if (fileName != oldFileName) {
            tempWriteFile << fileLine << std::endl;
        }
    }
    std::ifstream readTempWriteFile(tempFile);
    if (!readTempWriteFile.is_open()) {
        throw essentialFileNotOpen(tempFile);
    }
    std::ofstream overWriteFile(fileTracker);
    if (!overWriteFile.is_open()) {
        throw essentialFileNotOpen(fileTracker);
    }
    while (getline(readTempWriteFile, fileLine)) {
        overWriteFile << fileLine << std::endl;
    }
    tempWriteFile.close();
    readTempWriteFile.close();
    overWriteFile.close();
    const char *c = tempFile.c_str();
    remove(c);  // delete temporary file
}

void addFileToTracker(const std::string &fileName) {

    const std::string fileTracker =
        "trackedGameFiles.txt";  // root proj. directory
    // appending to file
    std::ifstream inputTracker(fileTracker);
    if (!inputTracker.is_open()) {
        throw essentialFileNotOpen(fileTracker);
    }

    std::string fileLine = "";
    // overwrite file copies
    while (getline(inputTracker, fileLine)) {
        // using delimeter " - ", we can pull file name exclusively
        // and compare to check if file exists. if file exists, delete old
        // file off of tracker.
        // return FIRST occurence pos. of -
        int delimeter = fileLine.find("-");
        std::string oldFileName = fileLine.substr(
            delimeter + 2, fileLine.size());  // pull oldFileName
        if (oldFileName == fileName) {
            rewriteTrackedWithoutSpecifiedFile(fileName);
            break;
        }
    }
    inputTracker.close();
    // append newFile
    std::ofstream outputTracker(fileTracker, std::ios::app);
    if (!outputTracker.is_open()) {
        throw essentialFileNotOpen(fileTracker);
    }
    // add original file to end
    formatFileToTracker(outputTracker, fileName);
    outputTracker.close();
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
    const std::string fileTracker =
        "trackedGameFiles.txt";  // root proj. directory
    std::ifstream tracker(fileTracker);

    if (!tracker.is_open()) {
        throw essentialFileNotOpen(fileTracker);
    }

    std::cout << color.PURPLE << "==========" << color.BOLD_ORANGE
              << "LIST OF SAVED FILES" << color.NC << color.PURPLE
              << "==========" << std::endl
              << std::endl
              << color.GREEN << "MM/DD/YYYY HH:MM - FileName " << color.NC
              << std::endl
              << std::endl;
    // print out all current saved files
    std::string savedFile = "";
    while (getline(tracker, savedFile)) {  // file, string
        std::cout << color.GREEN << savedFile << std::endl;
    }
    std::cout << std::endl;
    std::cout << color.PURPLE
              << "=======================================" << color.NC
              << std::endl
              << std::endl;
}

void saveGame() {
    // prompt user for save file name
    while (true) {
        std::string savedFileName = "";
        printCurrentSaveFiles();
        std::cout << color.PURPLE << ">>" << color.BOLD_ORANGE << " SAVE GAME "
                  << color.NC << color.PURPLE << "<<" << std::endl;
        std::cout << color.BOLD_ORANGE << " - " << color.NC << color.PURPLE
                  << "Naming over an existing file will overwrite the file."
                  << std::endl
                  << color.BOLD_ORANGE << " - " << color.NC << color.PURPLE
                  << "Save files are stored in the 'savedGames' directory."
                  << std::endl
                  << color.BOLD_ORANGE << " - " << color.NC << color.PURPLE
                  << "Cannot contain . or /" << std::endl
                  << color.BOLD_ORANGE << " - " << color.NC << color.PURPLE
                  << "Must be 3 - 10 characters" << std::endl
                  << std::endl;
        std::cout << "(Enter 'exit' to return to main menu)" << std::endl;
        std::cout << "Enter a name for your save file: " << color.BOLD_CYAN;
        std::cin >> savedFileName;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << color.NC << std::endl;

        if (savedFileName == "exit") {
            return;
        } else if (savedFileName.find(".") != std::string::npos ||
                   savedFileName.find("/") != std::string::npos ||
                   savedFileName.size() < 3 || savedFileName.size() > 10) {
            std::cout << color.BOLD_ORANGE << savedFileName
                      << " is not a valid save file name! Please try again."
                      << std::endl
                      << color.NC << std::endl;
        } else {
            std::string saveGameDirectory = appendFileDirectory(savedFileName);
            // create a save file in savedGames directory
            std::ofstream saveFile(saveGameDirectory);

            if (!saveFile.is_open()) {  // verify if file is open
                throw essentialFileNotOpen(saveGameDirectory);
            }

            // track current file
            addFileToTracker(savedFileName);
            /*
               ‼️  IMPLEMENT SAVE DATA HERE
                DELETE ONCE IMPLEMENTED
            */
            saveFile.close();
            return;
        }
    }
}

void loadGame() {
    // Receive saveFile from user
    while (true) {
        std::string loadedSaveFile = "";
        const std::string trackedSaves = "trackedGameFiles.txt";
        std::ifstream tracker(trackedSaves);
        if (isEmptyFile(tracker, trackedSaves)) {
            std::cout << color.PURPLE << "==========" << color.BOLD_ORANGE
                      << "LIST OF SAVED FILES" << color.NC << color.PURPLE
                      << "==========" << std::endl
                      << std::endl
                      << color.GREEN << "No saved files found." << color.PURPLE
                      << std::endl
                      << std::endl
                      << "=======================================" << color.NC
                      << std::endl;
            tracker.close();
            return;
        }
        tracker.close();
        printCurrentSaveFiles();  // load current save files
        std::cout << color.PURPLE << ">>" << color.BOLD_ORANGE << " LOAD GAME "
                  << color.NC << color.PURPLE << "<<" << std::endl
                  << std::endl;
        std::cout << "(Enter 'exit' to return to main menu)" << std::endl;
        std::cout << "Enter the name of the save file you wish to load: "
                  << color.BOLD_CYAN;
        std::cin >> loadedSaveFile;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << color.NC << std::endl;

        if (loadedSaveFile == "exit") {
            return;
        }

        std::string saveGameDirectory = appendFileDirectory(loadedSaveFile);

        // load file save below
        std::ifstream loadFile(saveGameDirectory);

        if (!loadFile.is_open()) {
            std::cout << color.BOLD_ORANGE << loadedSaveFile
                      << " is not a save file! Please try again." << color.NC
                      << color.PURPLE << std::endl
                      << std::endl;
            loadFile.close();
        } else {
            /*
               ‼️  IMPLEMENT LOAD DATA HERE
                DELETE ONCE IMPLEMENTED
            */
            loadFile.close();
            return;
        }
    }
}

void deleteSavedGame() {
    // print out list of current files
    const std::string trackedSaves = "trackedGameFiles.txt";
    std::ifstream tracker(trackedSaves);
    if (isEmptyFile(tracker, trackedSaves)) {
        std::cout << color.PURPLE << "==========" << color.BOLD_ORANGE
                  << "LIST OF SAVED FILES" << color.NC << color.PURPLE
                  << "==========" << std::endl
                  << std::endl
                  << color.GREEN << "No saved files found." << color.PURPLE
                  << std::endl
                  << std::endl
                  << "=======================================" << color.NC
                  << std::endl;
        tracker.close();
        return;
    }
    while (true) {
        tracker.close();
        printCurrentSaveFiles();

        std::string input = "";
        std::cout << color.PURPLE << ">>" << color.BOLD_ORANGE
                  << " DELETE SAVED GAME " << color.NC << color.PURPLE << "<<"
                  << std::endl
                  << std::endl;
        std::cout << "(Enter 'exit' to return to main menu)" << std::endl;
        std::cout << "Please enter the saved game you wish to delete: "
                  << color.BOLD_CYAN;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << color.NC << std::endl;
        if (input == "exit")
            return;

        const std::string userInputFile = appendFileDirectory(input);
        // concert to const char * for remove
        const char *c = userInputFile.c_str();
        std::ifstream trackedFiles(userInputFile);
        std::cout << color.BOLD_ORANGE;
        if (!trackedFiles.is_open()) {
            std::cout << input << " is not saved file! Please try again."
                      << std::endl;
            continue;
        } else if (std::remove(c) == 0) {
            rewriteTrackedWithoutSpecifiedFile(input);
            std::cout << "Saved game was successfully deleted." << std::endl;
            return;
        } else {
            std::cout << "Saved game was NOT deleted." << std::endl;
            return;
        }
        std::cout << color.NC << color.PURPLE;
        trackedFiles.close();
    }
}

// void generateMap() {
// }

void newGameSequence() {
    count.slowTextGenerator("As I enter this dungeon..", 20);
    count.seconds(2);
    std::cout << std::endl << std::endl;
    count.slowTextGenerator("I do not know what I will encounter..", 20);
    count.seconds(2);
    std::cout << std::endl << std::endl;
    count.slowTextGenerator("But anything for the ", 20);
    count.slowTextGenerator("kingdom...", 300);
}

void newGame() {
    newGameSequence();
    // generateMap();
}

int main() {
    titleScreen();  // Initialize title screen
    try {
        while (true) {
            int option = startOptions();

            std::cout << std::endl << std::endl;  // spacing

            switch (option) {
            case (1):  // New Game
                newGame();
                break;
            case (2):  // Load Game
                loadGame();
                break;
            case (3):  // Save Game
                saveGame();
                break;
            case (4):  // Delete Saved Game
                deleteSavedGame();
                break;
            case (5):  // Exit
                /*
                   ‼️  FOR EXITING, IMPLEMENT A 'BUFFER'
                   IN WHICH A BUFFER BASICALLY CHECKS IF THERE IS STILL DATA
                   NEEDED TO BE SAVED. IF SO, PROMPT USER TO SAVE GAME
                */
                programExit();
                break;
            }
        }
    } catch (essentialFileNotOpen &exec) {
        std::cerr << "FATAL ERROR: " << exec.getFileName() << " DOES NOT EXIST."
                  << std::endl
                  << std::endl
                  << "TERMINATING PROGRAM." << std::endl;
        exit(1);  // fatal error
    }
}
