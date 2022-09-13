#pragma once
#include <cstdint>

class LevelSystem {
    public:
        LevelSystem() 
            : level(1), exp(0), nextLevelLimit(EXPTO2) {}

        uint16_t get() { return level; }
        void set(uint16_t n_lvl) { level = n_lvl; }
        void incLevel(uint16_t i_lvl = 1) { level += i_lvl; }

        uint32_t getCurrentExp() { return exp; }
        void gainExp(uint32_t i_exp) { exp += i_exp; }
        void setExp(uint32_t n_exp) { exp = n_exp; }

        uint32_t getExpForNextLevel() { return nextLevelLimit; }
        void incLevelLimit() { nextLevelLimit *= EXPMULTIPLIER; }

    private:
        uint16_t level;
        uint32_t exp;  
        uint32_t nextLevelLimit;
        static const uint16_t EXPMULTIPLIER = 2;
        static const uint32_t EXPTO2 = 100;


};