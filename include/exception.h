#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class fileNotOpen {
 private:
    std::string fileName;
 public:
    // explicit for unintended conversions
    explicit fileNotOpen(std::string fileName) : fileName(fileName) {}

    const std::string getFileName() { return fileName; }
};

#endif
