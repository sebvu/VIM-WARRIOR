#ifndef INCLUDE_BOSSENTITY_H_
#define INCLUDE_BOSSENTITY_H_

#include "EnemyEntity.h"

class BossEntity : public EnemyEntity {
 private:
 public:
    BossEntity();
    void asciiArt();
    void encounterMessage();
    void printStats();
    void attack();
    void specialAttack();
};

#endif  // INCLUDE_BOSSENTITY_H_
