#pragma once
#include <cstdint>
#include <vector>
#include "class.hpp"
#include "macros.hpp"
#include "ability.hpp"
#include "levelsystem.hpp"
#include "effect.hpp"
#include "item.hpp"
#include <algorithm>

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

        uint16_t getMaxHp() const { return playerClass->HP.getMax(); }
        uint16_t getCurrentHp()  const { return playerClass->HP.getCurrent(); }
        uint16_t getCurrentLevel() const { return playerLevel->get(); }
        uint32_t getCurrentExp() const { return playerLevel->getCurrentExp(); }
        uint32_t getExpForNextLevel() const { return playerLevel->getExpForNextLevel(); }
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

        void applyEffect(Effect* e) {
            for(auto& effect : Effects) {
                if(e->name == effect.name) {
                    effect.duration = e->duration;
                    return;
                }
            }
            Effects.push_back(*e);
            playerClass->incStats(e->strEff, e->intEff, e->dexEff, e->physArmEff, e->magicArmEff);
        }


      

        const Armor* getEquippedArmorAt(unsigned long long i) const {
            if(!Armors[i]) return nullptr;
            return dynamic_cast<const Armor*>(Armors[i]->getData());
        }
        const Weapon* getEquippedWeaponAt(unsigned long long i) const {
            if(!Weapons[i]) return nullptr;
            return dynamic_cast<const Weapon*>(Weapons[i]->getData());
        }

        // Either use a normal ptr to access stats directly
        // or use a unique ptr and make getters for stats
        const Class* getClass() const { return playerClass; }
        const std::vector<Effect> getEffects() const { return Effects; }
        const std::vector<Item*> getInventoryList() const { return Inventory; }

    private:
        Class* playerClass;
        LevelSystem* playerLevel;
        std::vector<Effect> Effects;
        Item* Armors[(unsigned long long)ARMORSLOT::NUM_SLOTS];
        Item* Weapons[2];
        std::vector<Item*> Inventory;

        void cleanInventory() {
            const auto to_remove = std::stable_partition(Inventory.begin(), Inventory.end(),
             [](const Item* i) -> bool { return !i->isMarkedForDeletion(); });
            std::for_each(to_remove, Inventory.end(), [](Item* i) { delete i; });
            Inventory.erase(to_remove, Inventory.end()); 
        }

        friend class ItemManager;
};