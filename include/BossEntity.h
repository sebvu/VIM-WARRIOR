#ifndef BOSSENTITY_H
#define BOSSENTITY_H

#include "EnemyEntity.h"

class BossEntity : public EnemyEntity {
 private:
        
 public:
    BossEntity();
    void asciiArt(); 
    void encounterMessage(); 
    void printStats(); 
};

#endif
