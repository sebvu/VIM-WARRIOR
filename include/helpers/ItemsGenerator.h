#ifndef ITEMSLIST_H
#define ITEMSLIST_H

/*
a list of items that can be generated

items will contain the following attributes:
- name
- durability
- rarity
- enchantment
- damage
- defense
- type
- ID
- value
- weight
- description

pre-defined

Name: RARITY ENCHANTMENT NAME
Durability: Rarity will initially set, along with enchantment modifier
Rarity: Rarity will include;
{ Worthless, Common, Uncommon, Rare, Legendary, Mythical, Blessed }

Enchantment:
    ALL:
        { Broken - Everything is nullified to zero
        { Cursed - Inflicts negative effects on you and enemy
        { Damaged - Everything is badly negatively nullified
        { Godly - Everything is boosted
        { Wild - Unknown randomizer
    WEAPONS:
        { Nimble - better chance to hit, less damage
        { Heavy - less chance to hit, more weight aka more damage
        { Precise - Higher chance to hit
        { Serrated - Higher damage
        { Painfully-Dull - Slight debuff on all
        { Blinding - Chance to temporarily blind opponents with each strike.
    ARMOR:
        { Swift - better chance to dodge, more damage taken
        { Brawny - less chance to dodge, higher defense
        { Shrouding - Better chance to dodge
        { Cumbersome - Less chance to dodge
        { Uncomfortable - Slight debuff on all
        { Reflective - Reflects a portion of incoming damage back at the attacker.

Damage and Defense:
Each item has a base, will be scaled depending on rarity and enchantment.

Type:
    WEAPONS:
        General:
            { Stick
            { Dagger
            { Sword
            { Mace
            { War Hammer
            { Club
            { Halberd
            { Man Catcher
            { Ethereal Longsword
            { Crystal Sword
            { Diamond Dagger
        Specific:
            Dungeon:
                { Ul'Nuk Rapier
                { Ul'Nuk Family's Dagger
                { Ul'Nuk Pet Collar
                { Ul'Nuk Hard Pillow
                { Ul'Nuk Diary
                { Ul'Nuk Concocted Mace
                { Ul'Nuk Quartz Staff
                { Ul'Nuk Non-Functional Orb
                { Ul'Nuk War Sword
                { Ul'Nuk War Dagger
            Biblical:
                { Celestial Lance
                { Shadow Blade
                { Angel's Last Tear
                { Judgement Blade
                { Demonic Soul Reaper
                { Sword of Celestial Wrath
                { Fallen Angel's Bane Maul
            Vaktovian:
                { Vaktovian Shadowbane Mace
                { Vaktovian Vanguard Pike
                { Vaktovian Blade
                { Vaktovian Dominion Maul
                { Vaktovian Subjugator's Whip
                { Imperial Obliterator Gauntlets
                { Legionary's Glaive
                { Obsidian Shadowblade
                { Dreadnaught's First
        Boss:
            { Vaktovian Retribution's End
            { Archangels Last Tear
            { Dungeon Warrior's Last Stand
            { Ul'Nuks Divine Champion Blade
            { ...boss specific items

        ULTRA Rare:
            { Chankla
            { Bobby's Left Slipper
            { Imperial Soul Reaper

    ARMOR:
        General:
            Head:
                General:
                    { Steel Helmet
                    { Copper Helmet
                    { Metal Bucket
                    { Chainmail Helmet
                    { Cloth Helmet
                    { Diamond Helmet
                    { Unnecessarily Oversized Wooden Bowl
                Dungeon:
                    { Ul'Nuk Wedding Veil
                    { Ul'Nuk Top Hat
                    { Ul'Nuk Goggles
                    { Ul'Nuk Tiara
                    { Ul'Nuk Helmet
                    { Ul'Nuk Wizard Hat
                Biblical:
                    { Fallen Angel's Halo
                    { Demonic Worshipping Head Tiara
                    { Celestial Earrings
                    { Horned Helm
                    { Seraphic Crown
                    { Angel's Tiara
                Vaktovian:
                    { Vaktovian Centurion Helmet
                    { Imperial Gas Mask
                    { Vaktovian Montefortino
                    { Vaktovian Subjugator Helmet
                    { Vaktovian Executioner's Cap
                Boss:
                    { Archangel's Eyes 
                    { Vaktovian Tyrant's Visage
                    { Ul'Nuks Destined Warrior's Crown
                    { Dungeon Warrior's Crown

                Ultra Rare:
                    { Cat Ears
                    { Beanie
            Armor:
                General:
                    { Steel Pauldron
                    { Cloth 
                    { Steel Breastplate
                    { Leather Tunic
                    { Reinforced Chain Shirt
                    { Silver Mail
                    { Gold Plated Cuirass
                Dungeon:
                { Ul'Nuk Concocted Armor
                { Ul'Nuk Summoning Robe
                { Ul'Nuk Arbiter Armor
                { Ul'Nuk Casual Leather Shirt
                Biblical:
                    { Fallen Angel's Wings
                    { Angel's Robe
                Vaktovian:
                    { Vaktovian Mk. 1 Armor
                    { Vaktovian Coalition Armor
                    { Obsidian Order's Trench Coat
                    { Vaktovian Executioners Regalia
                    { Vaktovian Centurion Mark 1 Armor
                Boss:
                    { Archangel's Pauldrons
                    { Vaktovian's Legate General MK. X
                    { Ul'Nuk Divine Champion Plate
                    { Dungeon Warrior's Crest
                Ultra Rare:
                    { Maid Outfit
                    { Signed Limp Bizkit Palladium Armor
ID: All items will have a unique ID
Description: All items will have a unique description
*/

#include "Randomizer.h"
#include "Times.h"

class ItemsGenerator {
 private:
 public:
    void generateItem();
};
#endif
