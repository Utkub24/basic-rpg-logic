#include "cleric.h"

Cleric::Cleric() {
    SETHPANDSTATS;
    MP.setMax(BASEMP);
    MP.setVal(BASEMP);
    Abilities.push_back(ClericAbilites.at("Heal"));
    Abilities.push_back(ClericAbilites.at("Smite"));
}

void Cleric::levelUp(LevelSystem* levelsys) {
    LEVELUP;
    switch(levelsys->get()) {
        case 2:
            Abilities.push_back(ClericAbilites.at("Heal Self"));
            break;
        case 3:
            Str++;
            break;
    }
}

Cleric::~Cleric() {}