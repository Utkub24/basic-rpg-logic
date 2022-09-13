#pragma once
#include <cstdint>

class LevelSystem {
    public:
        LevelSystem();

        uint16_t get() const;
        void set(uint16_t n_lvl);
        void incLevel(uint16_t i_lvl = 1);

        uint32_t getCurrentExp() const;
        void gainExp(uint32_t i_exp);
        void setExp(uint32_t n_exp);

        uint32_t getExpForNextLevel() const;
        void incLevelLimit();
        


    private:
        uint16_t level;
        uint32_t exp;
        uint32_t nextLevelLimit;
        static const uint16_t EXPMULTIPLIER = 2;
        static const uint32_t EXPTO2 = 100;
};