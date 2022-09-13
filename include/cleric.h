#pragma once
#include "class.h"
#include <map>
#include "macros.hpp"

static const std::map<std::string, Ability> ClericAbilites {
     {"Heal", Ability("Heal", 10, 4, 6, ABILITYTYPE::HEAL, ABILITYTARGET::ALLY, ABILITYSCALER::INT)},
     {"Smite", Ability("Smite", 6, 3, 5, ABILITYTYPE::TRUEDMG, ABILITYTARGET::ENEMY, ABILITYSCALER::STR)},
     {"Heal Self", Ability("Heal Self", 10, 4, 6, ABILITYTYPE::HEAL, ABILITYTARGET::SELF, ABILITYSCALER::INT)}
};

class Cleric : public Class {
    public:
        Cleric();
        void levelUp(LevelSystem* levelsys) override;
        ~Cleric() override;
        BASESTATS(16, 5, 5, 2);
        static const uint16_t BASEMP = 16;
    private:
        PointPool MP;
};