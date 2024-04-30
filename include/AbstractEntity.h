#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H

// base implementation for all entities

#include <string>

class AbstractEntity {
 private:
    double health;
    std::string name;
    double attackDmg;
    int experience;

 public:
    void setHealth(double newHealth) { health = newHealth; }
    void setAttackDmg(double newAttackDmg) { attackDmg = newAttackDmg; }
    double getAttackDmg() { return attackDmg; }
    double getHealth() { return health; }
    std::string getName() { return name; }

    virtual void attack();
    virtual void specialAttack();
};

#endif
