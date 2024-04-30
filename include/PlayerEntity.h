#ifndef PLAYER_H
#define PLAYER_H

#include "AbstractEntity.h"
#include <string>

class PlayerEntity : AbstractEntity {
 private:
    std::string *items; // inventory
 public:

    void displayInventory();
    void attack();
    void specialAttack();
    ~PlayerEntity();
};

#endif
