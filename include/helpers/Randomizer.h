#ifndef INCLUDE_HELPERS_RANDOMIZER_H_
#define INCLUDE_HELPERS_RANDOMIZER_H_

#include <random>

struct Randomizer {
    // generate a random int between specified lowerbound upperbound
    // inclusive, exclusive
    int getRandomDistribution(const int &lowerbound, const int &upperbound) {
        std::random_device rd;

        std::uniform_int_distribution<int> dist(lowerbound, upperbound);

        return dist(rd);
    }
};

#endif  // INCLUDE_HELPERS_RANDOMIZER_H_
