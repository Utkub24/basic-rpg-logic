#pragma once
#include <string>

enum class ABILITYTARGET { NONE, SELF, ENEMY, ALLY, ENEMYALL, ALLYALL, GLOBAL};
enum class ABILITYTYPE { NONE, HEAL, TRUEDMG, PHYSDMG, MAGICDMG};

struct Ability {
    Ability(std::string a_name, uint16_t a_cost, uint16_t a_cd, uint16_t a_val, ABILITYTYPE a_type, ABILITYTARGET a_target)
        : name(a_name), cost(a_cost), cooldown(a_cd), effectVal(a_val), abilityType(a_type), target(a_target) {}
    std::string name = "unnamed";
    uint16_t cost = 0;
    uint16_t cooldown = 1; // number of turns
    uint16_t effectVal = 0;
    ABILITYTARGET target = ABILITYTARGET::NONE;
    ABILITYTYPE abilityType = ABILITYTYPE::NONE;

};