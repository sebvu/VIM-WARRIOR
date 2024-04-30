#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class essentialFileNotOpen {
 private:
    std::string fileName;
 public:
    // explicit for unintended conversions
    explicit essentialFileNotOpen(std::string fileName) : fileName(fileName) {}

    const std::string getFileName() { return fileName; }
};

#endif
