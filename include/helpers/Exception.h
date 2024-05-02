#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

// contains all necessary defined exceptions

class essentialFileNotOpen {
 private:
    std::string fileName;
 public:
    // explicit for unintended conversions
    explicit essentialFileNotOpen(std::string fileName) : fileName(fileName) {}

    const std::string getFileName() { return fileName; }
};

#endif
