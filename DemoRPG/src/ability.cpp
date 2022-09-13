#include "ability.h"

Ability::Ability(std::string a_name = "unnamed", uint16_t a_cost = 0, uint16_t a_cd = 1, uint16_t a_val = 0, ABILITYTYPE a_type = ABILITYTYPE::NONE, ABILITYTARGET a_target = ABILITYTARGET::NONE, ABILITYSCALER a_scaler = ABILITYSCALER::NONE)
        : name(a_name), cost(a_cost), cooldown(a_cd), effectVal(a_val), abilityType(a_type), target(a_target), scaler(a_scaler) {}
Ability::~Ability(){} 
