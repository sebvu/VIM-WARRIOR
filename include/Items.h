#ifndef INCLUDE_ITEMS_H_
#define INCLUDE_ITEMS_H_

// - name
// - durability
// - rarity
// - enchantment
// - damage
// - defense
// - type
// - value
// - weight
// - description

#include <string>

// class for all items in game
// items are pre-defined in ItemsGenerator.h, please check!
class Items {
 private:
    double durability;
    double damage;
    int itemLevelReq;
    std::string itemName;
    std::string itemRarity;
    std::string itemEnchantment;
    std::string itemType;
    std::string itemDescription;

 public:
    // all necessary parts of a items
    Items(double durability, double damage, int itemLevelReq,
          std::string itemName, std::string itemRarity,
          std::string itemEnchantment, std::string itemType,
          std::string itemDescription)
        : durability(durability), damage(damage), itemLevelReq(itemLevelReq),
          itemName(itemName), itemRarity(itemRarity),
          itemEnchantment(itemEnchantment), itemType(itemType),
          itemDescription(itemDescription) {}

    double getDurability() { return durability; }
    void setDurability(double newDurability) { durability = newDurability; }

    double getDamage() { return damage; }
    void setDamage(double newDamage) { damage = newDamage; }
};

#endif  // INCLUDE_ITEMS_H_
