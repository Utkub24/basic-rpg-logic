#pragma once
#include <cstdint>
#include <vector>
#include "class.hpp"
#include "macros.hpp"
#include "ability.hpp"
#include "levelsystem.hpp"
#include "effect.hpp"

class PlayerCharacter {
    public:
        PlayerCharacter() = delete;
        PlayerCharacter(Class* a_class)
            : playerClass(a_class), playerLevel(new LevelSystem()) {} 
        ~PlayerCharacter() { playerClass = nullptr; playerLevel = nullptr; }

        uint16_t getMaxHp() { return playerClass->HP.getMax(); }
        uint16_t getCurrentHp() { return playerClass->HP.getCurrent(); }
        uint16_t getCurrentLevel() { return playerLevel->get(); }
        uint32_t getCurrentExp() { return playerLevel->getCurrentExp(); }
        uint32_t getExpForNextLevel() { return playerLevel->getExpForNextLevel(); }
        void gainExp(uint32_t i_exp ) { 
            playerLevel->gainExp(i_exp);
            checkLevel();
        }
        
        void checkLevel() {
            while (playerLevel->getCurrentExp() >= playerLevel->getExpForNextLevel()) {
                playerLevel->incLevel();
                playerClass->levelUp(playerLevel);
                playerLevel->incLevelLimit();
            }
        }

        void applyEffect(Effect e) {
            for(auto& effect : Effects) {
                if(e.name == effect.name) {
                    effect.duration = e.duration;
                    return;
                }
            }
            Effects.push_back(e);
            playerClass->incStats(e.strEff, e.intEff, e.dexEff);
        }


        // Either use a normal ptr to access stats directly
        // or use a unique ptr and make getters for stats
        Class* getClass() { return playerClass; }
        std::vector<Effect> getEffects() { return Effects; }

    private:
        Class* playerClass;
        LevelSystem* playerLevel;
        std::vector<Effect> Effects;
};