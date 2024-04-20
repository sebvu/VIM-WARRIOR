/*
    ABSTRACTENEMY.H

    All enemies will contain a health, variant, enchantment, items, and name.

    Health: Health is dependent on dungeon level, region, enchantment, and variant.
    Variant: Variant examples; Zombie, Demon, etc..
    Enchantment: A wildcard enchantment, buff, speed, demon, etc..
    Name: A given name, could be randomized or intentional.
*/

#ifndef ABSTRACTENEMY_H
#define ABSTRACTENEMY_H

#include <string>

    class AbstractEnemy {
    private:
        double health;
        double baseDamage;
        std::string name;     
        int numberOfItems;
        std::string* items = new std::string[numberOfItems];

    public:
        // setters
        void setHealth(double ); // set health
        
        // getters
        double getHealth(); // get health
        std::string getVariant(); // get variant
        std::string getName(); // get name
        

    };


#endif