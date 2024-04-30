#include "../include/Entity.h"

// health handling
double Entity::getHealth() {
    return health; // return current health
}

void Entity::setHealth(double newHealth) {
    health = newHealth;
}

// modifier handling
std::string Entity::getModifier() {
    return modifier;
}

// name handling
std::string Entity::getName() {
    return name;
}

// damage handling
double Entity::getAttackDmg() {
    return attackDmg; 
}

void Entity::setAttackDmg(double newAttackDmg) {
    attackDmg = newAttackDmg; 
}

// item handling
