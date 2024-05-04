#ifndef INCLUDE_PLAYERENTITY_H_
#define INCLUDE_PLAYERENTITY_H_

#include "AbstractEntity.h"
#include "Items.h"
#include <iostream>
#include <string>

class PlayerEntity : public AbstractEntity {
 private:
    Items *items;  // inventory
 public:
    // player entity constructor
    PlayerEntity(std::string name, double health, int experience)
        : AbstractEntity(health, name, experience), items(nullptr) {}
    Items getItems() { return *items; }
    // COMBAT SYSTEM WILL BE IMPROVED
    void attack() { std::cout << "hello"; }         // ADD ACTUAL IMPLEMENTATION
    void specialAttack() { std::cout << "hello"; }  // ADD ACTUAL IMPLEMENTATION
    ~PlayerEntity() { delete[] items; }
};

#endif  // INCLUDE_PLAYERENTITY_H_
