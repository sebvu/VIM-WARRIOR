#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
private:
    std::string name;
    int health;
    int attack;
    int defense;
    int speed;
    int level;
    int experience;
    int experienceToNextLevel;
public:
    Entity(std::string name, int health, int attack, int defense, int speed, int level, int experience, int experienceToNextLevel);
    std::string getName();
    int getHealth();
    int getAttack();
    int getDefense();
    int getSpeed();
    int getLevel();
    int getExperience();
    int getExperienceToNextLevel();
    void setName(std::string name);
    void setHealth(int health);
    void setAttack(int attack);
    void setDefense(int defense);
    void setSpeed(int speed);
    void setLevel(int level);
    void setExperience(int experience);
    void setExperienceToNextLevel(int experienceToNextLevel);
    void levelUp();
    void gainExperience(int experience);
    void takeDamage(int damage);
    void heal(int health);
    void attackEntity(Entity& entity);
    void printStats();
    void printStats(std::string color);
    void printStats(std::string color, std::string color2);
    void printStats(std::string color, std::string color2, std::string color3);
    void printStats(std::string color, std::string color2, std::string color3, std::string color4);
    void printStats(std::string color, std::string color2, std::string color3, std::string color4, std::string color5);
    void printStats(std::string color, std::string color2, std::string color3, std::string color4, std::string color5, std::string color6);
    void printStats(std::string color, std::string color2, std::string color3, std::string color4, std::string color5, std::string color6, std::string color7);
    void printStats(std::string color, std::string color2, std::string color3, std::string color4, std::string color5, std::string color6, std::string color7, std::string color8);
    void printStats(std::string color, std::string color2, std::string color3, std::string color4, std::string color5, std::string color6, std::string color7, std::string color8, std::string color9);
    void printStats(std::string color, std::string color2, std::string color3, std::string color4
};

#endif
