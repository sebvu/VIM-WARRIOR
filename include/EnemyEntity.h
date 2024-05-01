/*
    ABSTRACTENEMY.H

    All enemies will contain a health, variant, enchantment, items, and name.

    Health: Health is dependent on dungeon level, region, enchantment, and
   variant. Variant: Variant examples; Zombie, Demon, etc.. Enchantment: A
   wildcard enchantment, buff, speed, demon, etc.. Name: A given name, could be
   randomized or intentional.
*/

#ifndef ENEMYENTITY_H
#define ENEMYENTITY_H

#include "AbstractEntity.h"
#include <string>

class EnemyEntity : public AbstractEntity {  // await more implementation
 private:
    int threatLevel;
    std::string modifier;

 public:
    int getThreatLevel() { return threatLevel; }
    std::string getModifier() { return modifier; }

    virtual void asciiArt() = 0;          // ascii art
    virtual void encounterMessage() = 0;  // encounterMessage
    virtual void printStats() = 0;        // stat printout
    virtual void attack() = 0;
    virtual void specialAttack() = 0;
};

#endif
