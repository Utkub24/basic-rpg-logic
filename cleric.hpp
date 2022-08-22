#pragma once
#include "class.hpp"
#include "ability.hpp"
#include "macros.hpp"
#include <vector>

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

struct ClericAbilites {
    Ability Heal = Ability("Heal", 10, 4, 6, ABILITYTYPE::HEAL, ABILITYTARGET::ALLY, ABILITYSCALER::INT);
    Ability Smite = Ability("Smite", 6, 3, 5, ABILITYTYPE::TRUEDMG, ABILITYTARGET::ENEMY, ABILITYSCALER::STR);
    Ability HealSelf = Ability("Heal Self", 10, 4, 6, ABILITYTYPE::HEAL, ABILITYTARGET::SELF, ABILITYSCALER::INT);
};