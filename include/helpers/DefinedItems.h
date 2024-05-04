#ifndef INCLUDE_HELPERS_DEFINEDITEMS_H_
#define INCLUDE_HELPERS_DEFINEDITEMS_H_

/*
a list of items that can be generated

items will contain the following attributes:
- name
- durability
- rarity
- enchantment
- damage
- speed
- defense
- type
- ID
- value
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
        { Reflective - Reflects a portion of incoming damage back at the
attacker.

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
Weight: Will affect dodge chance, and damage affect.
Description: All items will have a unique description
*/

// provide definition for all existing game items

#include <string>

// ---- WEAPONS
// type
// level requirement
// damage
// weight
// speed
// durability
// durability chipper
// special attack hit modifier
// special attack miss modifier
// special attack punishment key
// special attack punishment modifier
// description
// normal attack dialogue
// normal attack hit
// normal attack miss
// special attack dialogue
// special attack hit
// special attack miss

/*
 design
 levels: 1 - 20
 weight:
 145 (default)
 145 - 200 (light) 201 - 300 (medium) 301 - 500 (heavy)
 speed:
 10 (default)
 10 - 40 (slow) 40 - 70 (medium) 70 - 100 (fast)

modifiers/dmg should deviate about 10% naturally

chance to hit always scales from 1 - 100.

ultimately EVERYTHING else calculates the chance to hit.

LIST OF KEYS:

"Durability"
"Damage"
"Health"
"Weight" (chance of getting hit)
"Speed" (less chance to hit)

some rarities/enchantments will modify this ^

*/

struct DefinedItems {

    std::string WEAPONS_GENERAL[2][100] = {
        {
            // ID
            "1",
            // type
            "Stick",  // stick will serve as reference item
                      // level requirement
            "1",
            // damage
            "5.4",
            // weight
            "5",
            // durability
            "60",
            // durability chipper
            "4",
            // Special Swing Hit Modifier
            "1.2",
            // Special Swing Miss Modifier
            "0.6",
            // Special Swing Punishment Key
            "Durability",
            // Special Swing Punishment Modifier
            "2",
            // description
            "A surprisingly sturdy stick, you are quite effective wielding it "
            "from "
            "your service as a dungeon warrior for the empire!",
            // normal attack dialogue
            "Stick Lunge!\n\nYou lunge your stick forward with intent.",
            // normal attack hit
            "You stuck the enemy with your trusty stick!",
            // normal attack miss
            "The stick sadly misses its mark..",
            // special attack dialogue
            "Mighty Stick Swing!\n\nYou power up, and swing your stick with "
            "all your warrior might!",
            // special attack hit
            "Your swing strikes your enemy with all of its might.",
            // special attack miss
            "Your swing tragically smashes in to the floor in shame.",
        },
        {
            // ID
            "2",
            // type
            "dagger",
            // level requirement
            "2",
            // damage
            "10.2",
            // weight
            "8",
            // durability
            "100",
            // durability chipper
            "6",
            // special attack hit modifier
            "1.1",
            // special attack miss modifier
            "0.7",
            // special attack punishment key
            "Health",
            // special attack punishment modifier
            "1.7",
            // description
            "A dagger possibly dropped by a passer-byer, you wonder how it "
            "ended up here..",
            // normal attack dialogue
            "Aggressive Lunge!\n\nYou perform a quick lunge with your dagger.",
            // normal attack hit
            "You successfuly stab your enemy with your dagger!",
            // normal attack miss
            "Your dagger decides to take another path...",
            // special attack dialogue
            "Dagger Dance!\n\nYou perform a quick dance dagger dance, ready to "
            "strike your enemy.",
            // special attack hit
            "Your enemy, caught off guard, is struck by your dagger dance!",
            // special attack miss
            "Your tripped over your own feet, and missed your dagger dance.",
        },
    };
};

#endif  // INCLUDE_HELPERS_DEFINEDITEMS_H_
