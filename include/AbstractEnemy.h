/*
    ABSTRACTENEMY.H

    All enemies will contain a health, variant, enchantment, items, and name.

    Health: Health is dependent on dungeon level, region, enchantment, and
   variant. Variant: Variant examples; Zombie, Demon, etc.. Enchantment: A
   wildcard enchantment, buff, speed, demon, etc.. Name: A given name, could be
   randomized or intentional.
*/

#ifndef ABSTRACTENEMY_H
#define ABSTRACTENEMY_H

#include <string>

class AbstractEnemy {
 private:
    int health;

 public:
    int getHealth();
    void setHealth(int);

    virtual std::string encounterMessage() = 0;
};
#endif
