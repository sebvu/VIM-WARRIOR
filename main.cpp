/*
    EXIT CODE GUIDE:
    0 - Successful exit
    1 - Fatal program error
*/
#include "./include/colors.h"
#include "./include/exception.h"
#include <ctime>
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
                  << "(3) Save Game" << std::endl
                  << "(4) Exit" << std::endl
                  << std::endl
                  << "Enter your choice: ";
        if (std::cin >> choice) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
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

bool is_empty_file(std::ifstream &pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}

std::string appendFileDirectory(const std::string fileInput) {
    // append directory and .txt
    std::string saveGameDirectory = "./savedGames/";

    saveGameDirectory.append(fileInput).append(".txt");

    return saveGameDirectory;
}

void fileToTrackerFormat(std::ofstream &outputTracker, std::string fileName) {
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

void addFileToTracker(std::string fileName) {

    std::string fileTracker = "trackedGameFiles.txt";  // root proj. directory
    // appending to file
    std::ifstream inputTracker(fileTracker);
    try {
        if (!inputTracker.is_open()) {
            throw fileNotOpen(fileTracker);
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
                std::string tempFile = "temporaryStorage.txt";
                std::cout << "MATCH FOUND" << std::endl;
                std::cout << oldFileName << " == " << fileName << std::endl;
                // rewrite file without specific saved file
                // create temporary file to rewrite old content in,
                // then write temporary in to original fileTracker
                // delete temporary file in the end
                std::ofstream tempWriteFile(tempFile);
                if (!tempWriteFile.is_open()) {
                    throw fileNotOpen(tempFile);
                }
                std::ifstream newInputTracker(fileTracker);
                if (!newInputTracker.is_open()) {
                    throw fileNotOpen(fileTracker);
                }
                while (getline(newInputTracker, fileLine)) {
                    std::cout << "CURRENT FILENAME: " << fileName << std::endl;
                    oldFileName =
                        fileLine.substr(delimeter + 2, fileLine.size());
                    std::cout << "CURRENT OLDFILENAME: " << oldFileName
                              << std::endl;
                    if (fileName != oldFileName) {
                        std::cout << "OLD FILE NAME HAS BEEN ADDED"
                                  << std::endl;
                        tempWriteFile << fileLine << std::endl;
                    }
                }
                std::ifstream readTempWriteFile("temporaryStorage.txt");
                if (!readTempWriteFile.is_open()) {
                    throw fileNotOpen(tempFile);
                }
                std::ofstream overWriteFile(fileTracker);
                if (!overWriteFile.is_open()) {
                    throw fileNotOpen(fileTracker);
                }
                while (getline(readTempWriteFile, fileLine)) {
                    overWriteFile << fileLine << std::endl;
                }
                tempWriteFile.close();
                readTempWriteFile.close();
                overWriteFile.close();
                break;
            }
        }
        inputTracker.close();
        // append newFile
        std::ofstream outputTracker(fileTracker, std::ios::app);
        if (!outputTracker.is_open()) {
            throw fileNotOpen(fileTracker);
        }
        // add original file to end
        fileToTrackerFormat(outputTracker, fileName);
        outputTracker.close();
    } catch (fileNotOpen &exec) {
        std::cerr << std::endl
                  << std::endl
                  << "FATAL ERROR: " << exec.getFileName() << " NOT FOUND"
                  << std::endl
                  << "TERMINATING PROGRAM." << std::endl
                  << std::endl;
        exit(1);  // Fatal Program Error
    }
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
    std::string fileTracker = "trackedGameFiles.txt";  // root proj. directory
    std::ifstream tracker(fileTracker);

    try {
        if (!tracker.is_open()) {
            throw fileNotOpen(fileTracker);
        }
    } catch (fileNotOpen &exec) {
        std::cerr << std::endl
                  << std::endl
                  << "FATAL ERROR: " << exec.getFileName() << " NOT FOUND"
                  << std::endl
                  << "TERMINATING PROGRAM." << std::endl
                  << std::endl;
        exit(1);  // Fatal Program Error
    }

    std::cout << "==========LIST OF SAVED FILES==========" << std::endl
              << std::endl
              << "MM/DD/YYYY" << std::endl
              << std::endl;
    // print out all current saved files
    std::string savedFile = "";
    while (getline(tracker, savedFile)) {  // file, string
        std::cout << savedFile << std::endl;
    }
    std::cout << std::endl;
    std::cout << "=======================================" << std::endl
              << std::endl;
}

void saveGame() {
    // prompt user for save file name
    std::string savedFileName = "";
    printCurrentSaveFiles();
    std::cout << ">> SAVE GAME << " << std::endl;
    std::cout << "- Naming over an existing file will overwrite the file."
              << std::endl
              << "- Save files are stored in the 'savedGames' directory."
              << std::endl
              << "- Cannot contain . or /" << std::endl
              << "- Must be 3 - 10 characters" << std::endl;
    std::cout << "(Enter 'exit' to return to main menu)" << std::endl;
    std::cout << "Enter a name for your save file: ";
    std::cin >> savedFileName;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        if (savedFileName == "exit") {
            return;
        } else if (savedFileName.find(".") != std::string::npos ||
                   savedFileName.find("/") != std::string::npos ||
                   savedFileName.size() < 3 || savedFileName.size() > 10) {
            throw invalidFileName(savedFileName);
        }
        std::string saveGameDirectory = appendFileDirectory(savedFileName);
        // create a save file in savedGames directory
        std::ofstream saveFile(saveGameDirectory);

        if (!saveFile.is_open()) {  // verify if file is open
            throw fileNotOpen(saveGameDirectory);
        }

        // track current file
        addFileToTracker(savedFileName);
        /*
           ‼️  IMPLEMENT SAVE DATA HERE
            DELETE ONCE IMPLEMENTED
        */
        saveFile.close();
    } catch (fileNotOpen &exec) {
        std::cerr << std::endl
                  << std::endl
                  << "Error: File could not be saved at (" << exec.getFileName()
                  << "). Please try again." << std::endl
                  << std::endl;
        saveGame();
    } catch (invalidFileName &exec) {
        std::cerr << std::endl
                  << std::endl
                  << "Error: Invalid file name (" << exec.getFileName()
                  << "). Please try again." << std::endl
                  << std::endl;
        saveGame();
    }
}

void loadGame() {
    // Receive saveFile from user
    std::string loadedSaveFile = "";
    std::ifstream tracker("trackedGameFiles.txt");
    if (is_empty_file(tracker)) {
        std::cout << "==========LIST OF SAVED FILES==========" << std::endl
                  << std::endl
                  << "No saved files found." << std::endl
                  << std::endl
                  << "=======================================" << std::endl;
        tracker.close();
        return;
    }
    tracker.close();
    printCurrentSaveFiles();  // load current save files
    std::cout << "(Enter 'exit' to return to main menu)" << std::endl;
    std::cout << "Enter the name of the save file you wish to load: ";
    std::cin >> loadedSaveFile;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (loadedSaveFile == "exit") {
        return;
    }

    std::string saveGameDirectory = appendFileDirectory(loadedSaveFile);

    // load file save below
    std::ifstream loadFile(saveGameDirectory);

    try {
        if (!loadFile.is_open()) {
            throw fileNotOpen(saveGameDirectory);
        }
    } catch (fileNotOpen exec) {
        std::cerr << std::endl
                  << std::endl
                  << "Error: File not opened at (" << exec.getFileName()
                  << "). Please try again." << std::endl
                  << std::endl;
        loadGame();
    }
    /*
       ‼️  IMPLEMENT LOAD DATA HERE
        DELETE ONCE IMPLEMENTED
    */
    loadFile.close();
}

void deleteSavedGame() {}

void newGame() {
    /*
        ‼️  IMPLEMENT NEW GAME HERE
            DELETE ONCE IMPLEMENTED
    */
}

int main() {
    // titleScreen();  // Initialize title screen

    while (true) {
        int option = startOptions();

        std::cout << std::endl << std::endl;  // spacing

        switch (option) {
        case (1):  // New Game
            std::cout << "Switch case 1: New Game" << std::endl;
            // newGame();
            break;
        case (2):  // Load Game
            std::cout << "Switch case 2: Load Game" << std::endl;
            loadGame();
            break;
        case (3):  // Save Game
            std::cout << "Switch case 3: Save Game" << std::endl;
            saveGame();
            break;
        case (4):  // Delete Saved Game
            std::cout << "Switch case 4: Delete Saved Game" << std::endl;
            deleteSavedGame();
            break;
        case (5):  // Exit
            std::cout << "Switch case 4: Exit Game" << std::endl;
            /*
               ‼️  FOR EXITING, IMPLEMENT A 'BUFFER'
               IN WHICH A BUFFER BASICALLY CHECKS IF THERE IS STILL DATA
               NEEDED TO BE SAVED. IF SO, PROMPT USER TO SAVE GAME
            */
            programExit();
            break;
        }
    }
}
