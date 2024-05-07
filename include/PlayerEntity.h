#ifndef INCLUDE_PLAYERENTITY_H_
#define INCLUDE_PLAYERENTITY_H_

#include "AbstractEntity.h"
#include "Items.h"
#include <iostream>
#include <string>

class PlayerEntity : public AbstractEntity {
 private:
    Items *items;  // inventory
    int experience;

 public:
    // player entity constructor
    PlayerEntity(std::string name, double health, int experience, int level)
        : AbstractEntity(health, name, level), items(nullptr),
          experience(experience) {}
    Items getItems() { return *items; }
    // COMBAT SYSTEM WILL BE IMPROVED
    void attack() { std::cout << "hello"; }         // ADD ACTUAL IMPLEMENTATION
    void specialAttack() { std::cout << "hello"; }  // ADD ACTUAL IMPLEMENTATION
    ~PlayerEntity() { delete[] items; }
    // implementation
    void displayCurrentExperience();
    // will display current experience in the form of a progress bar

    void displayCurrentHealth();
    // will display current experience in the form of a progress bar
};

#endif  // INCLUDE_PLAYERENTITY_H_
