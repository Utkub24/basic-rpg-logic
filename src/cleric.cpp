#include "cleric.h"

const uint16_t Cleric::BASEHP = 16;
const uint16_t Cleric::BASESTR = 5;
const uint16_t Cleric::BASEINT = 5;
const uint16_t Cleric::BASEDEX = 2;
const uint16_t Cleric::BASEMP = 16;


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