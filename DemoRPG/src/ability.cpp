#include "ability.h"

Ability::Ability(std::string a_name, uint16_t a_cost, uint16_t a_cd, uint16_t a_val, ABILITYTYPE a_type, ABILITYTARGET a_target, ABILITYSCALER a_scaler)
        : name(a_name), cost(a_cost), cooldown(a_cd), effectVal(a_val), abilityType(a_type), target(a_target), scaler(a_scaler) {}
Ability::~Ability(){} 
