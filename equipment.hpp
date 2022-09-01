#pragma once
#include <string>
#include "statblock.hpp"
#include <typeinfo>

class Equipment {
    public:
        std::string name;
        StatBlock stats;
        virtual const char* getType() = 0;

    protected:
        Equipment(std::string name, StatBlock stats) 
            : name(name), stats(stats) {}

    private:
};

enum class ARMORSLOT { HELMET, CHEST, LEGS, BOOTS, GLOVES, RING1, RING2, NECK, NUM_SLOTS };

class Armor final : public Equipment {
    public:
        ARMORSLOT slot;

        Armor() = delete;
        Armor(const Armor&) = delete;
        Armor(const Armor&&) = delete;

        Armor(std::string name, StatBlock stats, ARMORSLOT slot)
            : Equipment(name, stats), slot(slot) {}

        const char* getType() override { return typeid(*this).name(); }

    private:

};

enum class WEAPONSLOT { ONEHAND, TWOHAND, OFFHAND, NUM_SLOTS };
enum class WEAPONTYPE { MELEE, RANGED, MAGIC, SHIELD, NUM_SLOTS };

class Weapon final : public Equipment {
    public:
        WEAPONSLOT slot;
        WEAPONTYPE type;
        uint16_t minDmg;
        uint16_t maxDmg;

        Weapon() = delete;
        Weapon(const Weapon&) = delete;
        Weapon(const Weapon&&) = delete;

        Weapon(std::string name, StatBlock stats, uint16_t min, uint16_t max, WEAPONSLOT slot, WEAPONTYPE type)
            : Equipment(name, stats), slot(slot), type(type), minDmg(min), maxDmg(max) {}

        const char* getType() override { return typeid(*this).name(); }


    private:
};