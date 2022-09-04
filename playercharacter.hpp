#pragma once
#include <cstdint>
#include <vector>
#include "class.hpp"
#include "macros.hpp"
#include "ability.hpp"
#include "levelsystem.hpp"
#include "effect.hpp"
#include "item.hpp"

class PlayerCharacter {
    public:
        PlayerCharacter() = delete;
        PlayerCharacter(Class* a_class)
            : playerClass(a_class), playerLevel(new LevelSystem()) {
                for(int i = 0; i < (int)ARMORSLOT::NUM_SLOTS; i++) { Armors[i] = nullptr; }
                for(int i = 0; i < 2; i++) { Weapons[i] = nullptr; }
            } 
        ~PlayerCharacter() {
            delete playerClass;    
            playerClass = nullptr; 
            delete playerLevel;
            playerLevel = nullptr;

            for(int i = 0; i < (int)ARMORSLOT::NUM_SLOTS; i++) {
                if(Armors[i]) { delete Armors[i]; Armors[i] = nullptr; }
            }
            for(int i = 0; i < 2; i++) {
                if(Weapons[i]) { delete Weapons[i]; Weapons[i] = nullptr; }
            }
        }

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
            playerClass->incStats(e.strEff, e.intEff, e.dexEff, e.physArmEff, e.magicArmEff);
        }

        // don't destroy item once inventory is added
        bool equip(Item* e_item) {
            if(!e_item || !e_item->getData())
                return false;

            Armor* armor = dynamic_cast<Armor*>(e_item->_data);
            if(armor) {
                unsigned long long slot_num = (unsigned long long)armor->slot;
                if(Armors[slot_num]) {
                    *this->playerClass -= Armors[slot_num]->stats;
                    delete Armors[slot_num];
                    Armors[slot_num] = nullptr;

                    Armors[slot_num] = armor;
                    *this->playerClass += armor->stats;
                } else {
                    Armors[slot_num] = armor;
                    *this->playerClass += armor->stats;
                }
                return true;
            }

            Weapon* weapon = dynamic_cast<Weapon*>(e_item->_data);
            if(weapon) {
                unsigned long long slot_num = (unsigned long long)weapon->slot;
                if(Weapons[slot_num]) {
                    *this->playerClass -= Weapons[slot_num]->stats; 
                    delete Weapons[slot_num];
                    Weapons[slot_num] = nullptr;

                    *this->playerClass += weapon->stats;
                    Weapons[slot_num] = weapon;
                } else {
                    Weapons[slot_num] = weapon;
                    *this->playerClass += weapon->stats;
                }
                return true;
            }

            return false;
        }

        const EquipmentDelegate* getEquippedArmorAt(unsigned long long i) { return dynamic_cast<Armor*>(Armors[i]); }
        const EquipmentDelegate* getEquippedWeaponAt(unsigned long long i) { return dynamic_cast<Weapon*>(Weapons[i]); }

        // Either use a normal ptr to access stats directly
        // or use a unique ptr and make getters for stats
        Class* getClass() { return playerClass; }
        std::vector<Effect> getEffects() { return Effects; }

    private:
        Class* playerClass;
        LevelSystem* playerLevel;
        std::vector<Effect> Effects;
        EquipmentDelegate* Armors[(unsigned long long)ARMORSLOT::NUM_SLOTS];
        EquipmentDelegate* Weapons[2];
};