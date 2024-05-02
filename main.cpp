/*
    EXIT CODE GUIDE:
    0 - Successful exit
    1 - Fatal program error

💜 Dungeon Warrior  💜
- This is a text-based RPG game that is currently in development.
- Formatted code abides with the Google C++ Style Guide.
- For more information, please check the .clang-format file.

*/
// #include "./include/BossEntity.h"
#include "./include/PlayerEntity.h"
// #include "./include/AbstractEntity.h"
#include "./include/helpers/Colors.h"
#include "./include/helpers/Exception.h"
#include "./include/helpers/Randomizer.h"
#include "./include/helpers/TextGeneration.h"
#include "./include/helpers/Times.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ostream>
#include <string>

// ANSI Escape Codes for Color Control
Color color;
// Struct for Easy Time Control
Time chrono;
// Randomizer for easier distributions
Randomizer rando;
// Text generation helper for less bloating
TextGenerator generate;

// pre-defining all functions

void clearScreen();          // clears current terminal screen
void printSword();           // prints out sword ASCII
void beginScreenSequence();  // beginning animation-ish sequence
void displayTitleScreen();   // display dungeon warrior title screen
int displayStartOptions();   // display main start options
// check if specified file is empty, if so, throw exception
bool isEmptyFile(std::ifstream &pFile, const std::string &fileName);
// append directory and specify .txt file
std::string appendFileDirectory(const std::string &fileInput);
// formats date, time and file name to tracker
void formatFileToTracker(std::ofstream &outputTracker,
                         const std::string &fileName);
// will rewrite trackedgamefiles.txt without specified file
void rewriteTrackedWithoutSpecifiedFile(const std::string &fileName);
void addFileToTracker(const std::string &fileName);  // add file to trackedgames
void programExit();                                  // end program
void printCurrentSaveFiles();         // print current saved games
void saveGame();                      // save current game state to a saved file
void loadGame();                      // load a saved game
void deleteSavedGame();               // delete a current saved game
void newGameSequence();               // activate new game sequence lore
int gameChoice(PlayerEntity Player);  // display game choices
void titleScreen();                   // display title screen
int startOptions();                   // display start options
void newGame();                       // new game
void newEncounter();                  // init new encounter
void checkInventory();                // open inventory ui
void printLogBook();                  // print previous encounters
void textWall();                      // spam text wall
std::string nameSetter();             // setting name function
void doubleNewLine();                 // double new line to remove bloat
void printNoSavedFiles();             // display no current saved files
// void generateMap();                // will be added later

// Function Definitions

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

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

void doubleNewLine() { std::cout << std::endl << std::endl; }

void beginningScreenSequence() {  // beginning animation-ish sequence
    generate.procedurallyPrintSetter(
        "The kingdom sent me here to these depths..", 20, color.ITALICIZE_BLUE,
        false);
    chrono.seconds(2);
    doubleNewLine();

    generate.procedurallyPrintSetter("...I know nothing else", 20,
                                     color.ITALICIZE_BLACK, true);
    chrono.seconds(2);
    doubleNewLine();

    generate.procedurallyPrint("..but to", 20);
    generate.procedurallyPrintSetter(" serve....", 20, color.ORANGE, true);

    chrono.seconds(2);
    doubleNewLine();

    generate.procedurallyPrint("       as a ", 20);
    generate.procedurallyPrintSetter("WARRIOR.", 20, color.BOLD_RED, true);
    doubleNewLine();

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
            chrono.milliseconds(5);
        }
        std::cout << std::endl;
    }
}

void titleScreen() {
    // Begin title screen
    std::cout << std::endl << color.UNDERLINE;
    generate.printSetter("PREFACE", color.BOLD_CYAN, false);
    doubleNewLine();
    generate.printSetter("This game is best experience with ANSI escape codes "
                         "enabled. (i.e colors!!)",
                         color.GREEN, true);
    doubleNewLine();
    std::cout << "Unix-like terminals";
    generate.printSetter(" should ", color.ITALICIZE, false);
    std::cout << color.GREEN
              << "have escape codes enabled, however, Windows 10+ would need "
                 "manual configuration.";
    doubleNewLine();
    std::cout << "(correct me if I'm wrong, I never tested it personally :P)";
    doubleNewLine();
    std::cout << "Thank you for reading, please enjoy Dungeon Warrior~!";
    doubleNewLine();
    std::cout << "(\\ _ /)\n(=t.t=)" << color.NC << std::flush;

    chrono.seconds(6);

    clearScreen();

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
                  << ") Delete Saved Game" << std::endl
                  << "(" << color.BOLD_ORANGE << "4" << color.NC << color.PURPLE
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

    struct tm localTime;

    localtime_r(&now, &localTime);

    int year = 1900 + localTime.tm_year;
    int month = 1 + localTime.tm_mon;
    int day = localTime.tm_mday;
    int hour = localTime.tm_hour;
    int minute = localTime.tm_min;

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

void printNoSavedFiles() {
    generate.printSetter("==========", color.PURPLE, false);
    generate.printSetter("LIST OF SAVED FILES", color.BOLD_ORANGE, false);
    generate.printSetter("==========", color.PURPLE, false);
    doubleNewLine();
    generate.printSetter("MM/DD/YYYY HH/MM", color.GREEN, true);
    doubleNewLine();
    std::cout << "No saved files found!";
    doubleNewLine();
    generate.printSetter(
        "=======================================", color.PURPLE, false);
    std::cout << std::flush;
}

void loadGame() {
    // Receive saveFile from user
    while (true) {
        std::string loadedSaveFile = "";
        const std::string fileTracker = "trackedGameFiles.txt";
        std::ifstream tracker(fileTracker);
        if (isEmptyFile(tracker, fileTracker)) {
            printNoSavedFiles();
            tracker.close();
            chrono.seconds(3);
            clearScreen();
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
    const std::string fileTracker = "trackedGameFiles.txt";
    std::ifstream tracker(fileTracker);
    if (isEmptyFile(tracker, fileTracker)) {
        printNoSavedFiles();
        tracker.close();
        chrono.seconds(3);
        clearScreen();
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

void textWall() {
    for (int i = 0; i < 100; i++) {
        if (rando.getRandomDistribution(0, 100) < 95)
            generate.procedurallyPrintSetter("ITSALIE", 1, color.BOLD_RED,
                                             false);
        else
            generate.procedurallyPrintSetter("meow", 1, color.BOLD_RED, false);
    }
}

void textWallCloserFunction() { chrono.milliseconds(50); }

std::string nameSetter() {
    std::string name;
    // name scene
    while (true) {
        generate.procedurallyPrintSetter("What is my name..? ", 20,
                                         color.BOLD_CYAN, false);
        std::cin >> name;
        std::cout << std::endl;
        if (name.find(".") != std::string::npos ||
            name.find("/") != std::string::npos || name.size() < 3 ||
            name.size() > 10) {
            generate.procedurallyPrint("That can't be my name... ", 20);
            chrono.seconds(2);
        } else {
            generate.procedurallyPrint("Ah yes... ", 20);
            chrono.seconds(1);
            generate.procedurallyPrint("my name is " + name + ".", 20);
            chrono.seconds(2);
            generate.procedurallyPrint(" What a odd na-", 20);
            std::cout << color.NC;
            return name;
        }
    }
}

void newGameSequence() {
    generate.procedurallyPrintSetter("As I enter this dungeon..", 20,
                                     color.BOLD_CYAN, false);
    chrono.seconds(2);
    doubleNewLine();
    generate.procedurallyPrint("I do not know what I will encounter..", 20);
    chrono.seconds(2);
    doubleNewLine();
    generate.procedurallyPrint("But anything for the ", 20);
    generate.procedurallyPrintSetter("kingdom...", 200, color.ITALICIZE, false);

    std::cout << color.NC << std::endl;

    textWall();
}

void displayCurrentExperience(PlayerEntity Player) {}

int gameChoice(PlayerEntity Player) {
    int choice;
    std::cout << color.PURPLE;
    std::cin >> choice;
    return choice;
}

void newGame() {
    // creating a player object upon initialization
    std::string name = nameSetter();
    PlayerEntity Player("test", 100.0, 0);  // creation of player entity
    clearScreen();
    newGameSequence();
    clearScreen();
    while (true) {
        // GAME SEQUENCE IN THIS WHILE TRUE BLOCK

        /*
        ‼️   THIS IS NOT THE FINAL VERSION. WILL BE ULTIMATELY REVAMPED
        */
        std::cout << std::fixed
                  << std::setprecision(1);  // precision @ 1 decimal
        int option = gameChoice(Player);

        switch (option) {
        case (1):  // new encounter
            // newEncounter();
            break;
        case (2):  // check inventory
            // checkInventory();
            break;
        case (3):  // encounter logbook
            // printLogBooK();
            break;
        case (4):  // save game
            saveGame();
            return;
            break;
        case (5):  // save and quit
            // Are you sure you want to quit?
            // if yes, save game and quit, else back to gamechoice
            // ensureExitGame();
            return;
            break;
        }
    }
}

int main() {
    // titleScreen();  // Initialize title screen
    clearScreen();
    try {
        while (true) {
            int option = startOptions();

            doubleNewLine();  // spacing

            switch (option) {
            case (1):  // New Game
                clearScreen();
                newGame();
                break;
            case (2):  // Load Game
                clearScreen();
                loadGame();
                break;
            case (3):  // Delete Saved Game
                clearScreen();
                deleteSavedGame();
                break;
            case (4):  // Exit
                clearScreen();
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
