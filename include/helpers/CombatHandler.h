#ifndef INCLUDE_HELPERS_COMBATHANDLER_H_
#define INCLUDE_HELPERS_COMBATHANDLER_H_

#include "../Items.h"
#include "Randomizer.h"
#include "Times.h"

struct CombatHandler {

    // Generate random item(s) within a set of given parameters.
    // Will ONLY be used in the context of enemy entities, as our player
    // will not be able to generate items and only take items from the dungeon.

    // Each item has pre-defined stats which will be scaled depending on
    // stats listed above.

    // Pull a random item within the set parameters, provide random enchanatment
    // and rarity, returns Items object.
    Items generateItemsForEnemy();

    // insert operators
};

#endif  // INCLUDE_HELPERS_COMBATHANDLER_H_
