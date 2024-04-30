/*
    ABSTRACTENEMY.H

    All enemies will contain a health, variant, enchantment, items, and name.

    Health: Health is dependent on dungeon level, region, enchantment, and
   variant. Variant: Variant examples; Zombie, Demon, etc.. Enchantment: A
   wildcard enchantment, buff, speed, demon, etc.. Name: A given name, could be
   randomized or intentional.
*/

#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {  // await more implementation
 private:
    double health;
    std::string name;
    double attackDmg;
    std::string modifier;

 public:
    double getHealth();
    void setHealth(double);

    std::string getModifier();
    std::string getName();
    void setAttackDmg(double);
    double getAttackDmg();

    virtual void encounterMessage() = 0;  // encounterMessage
    virtual void printStats() = 0;        // stat printout
};

#endif
