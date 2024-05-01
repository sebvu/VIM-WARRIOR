#ifndef PLAYER_H
#define PLAYER_H

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
    void displayInventory() { std::cout << "hello"; }
    void attack() { std::cout << "hello"; }
    void specialAttack() { std::cout << "hello"; }
    ~PlayerEntity() { delete[] items; }
};

#endif
