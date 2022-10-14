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

        [[nodiscard]] const uint16_t getMaxHp() const noexcept;
        [[nodiscard]] const uint16_t getCurrentHp() const noexcept;
        [[nodiscard]] const uint16_t getCurrentLevel() const noexcept;
        [[nodiscard]] const uint32_t getCurrentExp() const noexcept;
        [[nodiscard]] const uint32_t getExpForNextLevel() const noexcept;

        void gainExp(uint32_t i_exp);
        void checkLevel();

        void applyEffect(Effect* e);

        [[nodiscard]] const Armor* getEquippedArmorAt(unsigned long long i) const noexcept;
        [[nodiscard]] const Weapon* getEquippedWeaponAt(unsigned long long i) const noexcept;

        [[nodiscard]] const Class* getClass() const noexcept;
        [[nodiscard]] const std::vector<Effect> getEffects() const noexcept;
        [[nodiscard]] const std::vector<Item*> getInventory() const noexcept;

        [[nodiscard]] const uint16_t getAttackVal() const noexcept;

        void reduceHp(uint16_t i_hp) noexcept;
        void increaseHp(uint16_t i_hp) noexcept;
    
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