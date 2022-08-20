#pragma once
#include <cstdint>
#include "class.hpp"
#include "macros.hpp"

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