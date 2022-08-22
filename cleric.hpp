#pragma once
#include "class.hpp"
#include "ability.hpp"
#include "macros.hpp"
#include <vector>
#include <map>

static const std::map<std::string, Ability> ClericAbilites {
     {"Heal", Ability("Heal", 10, 4, 6, ABILITYTYPE::HEAL, ABILITYTARGET::ALLY, ABILITYSCALER::INT)},
     {"Smite", Ability("Smite", 6, 3, 5, ABILITYTYPE::TRUEDMG, ABILITYTARGET::ENEMY, ABILITYSCALER::STR)},
     {"Heal Self", Ability("Heal Self", 10, 4, 6, ABILITYTYPE::HEAL, ABILITYTARGET::SELF, ABILITYSCALER::STR)}
};

class Cleric : public Class { 
    public:
        Cleric() { 
                SETHPANDSTATS;
                MP.setMax(BASEMP);
                MP.setVal(BASEMP); 
                Abilites.push_back(ClericAbilites.at("Heal"));
                Abilites.push_back(ClericAbilites.at("Smite"));
            } 
        void levelUp(LevelSystem* levelsys) override { 
            LEVELUP;
            switch (levelsys->get()) {
                case 2:
                    Abilites.push_back(ClericAbilites.at("Heal Self"));
                    break;
                case 3:
                    Str++;
                    break;
            }
        }
    private:
        BASESTATS(16, 5, 5, 2);
        static const uint16_t BASEMP = 16;
        PointPool MP;
};


 /*
 Using maps is fine for now
 Try using a struct ClericAbilities with static const members
 when seperating hpp and cpp files
 */
