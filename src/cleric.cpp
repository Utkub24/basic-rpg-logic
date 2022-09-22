#include "cleric.h"

const uint16_t Cleric::BASEHP = 16;
const uint16_t Cleric::BASESTR = 5;
const uint16_t Cleric::BASEINT = 5;
const uint16_t Cleric::BASEDEX = 2;
const uint16_t Cleric::BASEMP = 16;

const std::map<std::string, Ability> Cleric::ClericAbilities {
     {"Heal", Ability("Heal", 10, 4, 6, ABILITYTYPE::HEAL, ABILITYTARGET::ALLY, ABILITYSCALER::INT)},
     {"Smite", Ability("Smite", 6, 3, 5, ABILITYTYPE::TRUEDMG, ABILITYTARGET::ENEMY, ABILITYSCALER::STR)},
     {"Heal Self", Ability("Heal Self", 10, 4, 6, ABILITYTYPE::HEAL, ABILITYTARGET::SELF, ABILITYSCALER::INT)}
};

Cleric::Cleric() {
    SETHPANDSTATS;
    MP.setMax(BASEMP);
    MP.setVal(BASEMP);
    Abilities.push_back(ClericAbilities.at("Heal"));
    Abilities.push_back(ClericAbilities.at("Smite"));
}

void Cleric::levelUp(LevelSystem* levelsys) {
    LEVELUP;
    MP.setMax( MP.getMax() + (uint16_t)((BASEMP+1)/2.f) );
    MP.setVal(MP.getMax());
    switch(levelsys->get()) {
        case 2:
            Abilities.push_back(ClericAbilities.at("Heal Self"));
            break;
        case 3:
            Str++;
            break;
    }
}

Cleric::~Cleric() {}