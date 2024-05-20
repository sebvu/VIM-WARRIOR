#ifndef INCLUDE_HELPERS_TIMES_H_
#define INCLUDE_HELPERS_TIMES_H_

#include <thread>

// helper struct to define all time related functions

struct Times {
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
};

#endif  // INCLUDE_HELPERS_TIMES_H_
