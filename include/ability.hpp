#pragma once
#include <string>

enum class ABILITYTARGET { NONE, SELF, ENEMY, ALLY, ENEMYALL, ALLYALL, GLOBAL};
enum class ABILITYTYPE { NONE, HEAL, TRUEDMG, PHYSDMG, MAGICDMG};
enum class ABILITYSCALER { NONE, STR, INT, DEX };

struct Ability {
    Ability(std::string a_name = "unnamed", uint16_t a_cost = 0, uint16_t a_cd = 1, uint16_t a_val = 0, ABILITYTYPE a_type = ABILITYTYPE::NONE, ABILITYTARGET a_target = ABILITYTARGET::NONE, ABILITYSCALER a_scaler = ABILITYSCALER::NONE)
        : name(a_name), cost(a_cost), cooldown(a_cd), effectVal(a_val), abilityType(a_type), target(a_target), scaler(a_scaler) {}
    std::string name;
    uint16_t cost;
    uint16_t cooldown; // number of turns
    uint16_t effectVal;
    ABILITYTYPE abilityType;
    ABILITYTARGET target;
    ABILITYSCALER scaler;
};