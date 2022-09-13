#pragma once
#include "class.h"
#include "effect.h"
#include "item.h"
#include <algorithm>

class PlayerCharacter {
    public:
        PlayerCharacter() = delete;
        PlayerCharacter(Class* a_class);
        ~PlayerCharacter();

        const uint16_t getMaxHp() const;
        const uint16_t getCurrentHp() const;
        const uint16_t getCurrentLevel() const;
        const uint32_t getCurrentExp() const;
        const uint32_t getExpForNextLevel() const;

        void gainExp(uint32_t i_exp);
        void checkLevel();

        void applyEffect(Effect* e);

        const Armor* getEquippedArmorAt(unsigned long long i) const;
        const Weapon* getEquippedWeaponAt(unsigned long long i) const;

        const Class* getClass() const;
        const std::vector<Effect> getEffects() const;
        const std::vector<Item*> getInventory() const;
    
    private:
        Class* playerClass;
        LevelSystem* playerLevel;
        std::vector<Effect> Effects;
        Item* Armors[(unsigned long long)ARMORSLOT::NUM_SLOTS];
        Item* Weapons[2];
        std::vector<Item*> Inventory;

        void cleanInventory();

        friend class ItemManager;
};