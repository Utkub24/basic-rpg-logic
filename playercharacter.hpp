#pragma once
#include <cstdint>
#include <vector>
#include "class.hpp"
#include "macros.hpp"
#include "abilty.hpp"

class PlayerCharacter {
    public:
        PlayerCharacter() = delete;
        PlayerCharacter(Class* p_class)
            : level(1), exp(0), nextLevelLimit(EXPTO2), playerClass(p_class) {} 
        ~PlayerCharacter() { playerClass = nullptr; }

        void checkLevel() {
            while(exp >= nextLevelLimit) {
                level++;
                playerClass->levelUp();
                incLevelLimit();
            }
        }

        void gainExp(uint32_t i_exp) {
            exp += i_exp;
            checkLevel();
        }

        uint16_t getCurrentLevel() { return level; }
        uint32_t getCurrentExp() { return exp; }
        uint32_t getExpForNextLevel() { return nextLevelLimit; }

        uint16_t getMaxHp() { return playerClass->HP.getMax(); }
        uint16_t getCurrentHp() { return playerClass->HP.getCurrent(); }
        
        // Either use a normal ptr to access stats directly
        // or use a unique ptr and make getters for stats
        Class* getClass() { return playerClass; }

   protected:
        uint16_t level;
        uint32_t exp;  
        uint32_t nextLevelLimit;
        Class* playerClass;

    private:
        static const uint16_t EXPMULTIPLIER = 2;
        static const uint32_t EXPTO2 = 100;
        void incLevelLimit() { nextLevelLimit *= EXPMULTIPLIER; }

 
};

//CHARACTERCLASS(Warrior, 20, 6, 2, 4);
//CHARACTERCLASS(Rogue, 10, 3, 1, 8);
//CHARACTERCLASS(Wizard, 8, 2, 8, 2);
//CHARACTERCLASS(Cleric, 16, 5, 5, 2);

/*
Have 3 starting abilities
Get a new ability each level up to level 8 (Total of 10 with starter abilities)
Get powerful abilities at levels: 10, 15, 20. (Max level maybe?)

All abilites, unlocked or not, are stored in a vector*
They belong to the class, not the player directly

Somehow mark abilities unlocked/locked (keep track of their cd's in the battle system)
Maybe add a new property (bool unlocked) to each ability and change it when leveling up
Push abilities in order to the vector so that unlocking is easier to implement

Case switch statements for each class 
Allows for bonuses at certain levels (e.g Extra Int for the Wizard at level 3)
This will also solve the ability unlocking problem by:
a) Constructing each ability only once it's unlocked (naa don't) * 
b) Simply mark the wanted abilites unlocked (might require some pointer action)

yea do case switch b

Find a logical way to declare all abilities for a class (Preferably not in the class constructor)
Where you can see all of them at once 
Perhaps by dedicating a header file to declare the abilities and then adding them to the ability list in the class constructor

Take a look at lookup tables, switch statements, maps, dictionaries
Something close to a lookup table would be:
Store leveling mechanisms for level L in an array(?) with index L-2 (Level 2 goes to index 0)

...
level++;
levelUp(level);
...

But how do you store these "mechanisms" in an array???????

*/

class Cleric : public Class { 
    public:
        Cleric() { 
                SETHPANDSTATS;
                MP.setMax(BASEMP);
                MP.setVal(BASEMP); 
            } 
        void levelUp() override { LEVELUP; }
    private:
        BASESTATS(16, 5, 5, 2);
        static const uint16_t BASEMP = 16;

        PointPool MP;
};