#pragma once
#include <string>
#include "statblock.hpp"
#include <typeinfo>

class ItemDelegate {
    public:
        std::string name;
        virtual const char* getType() = 0;
        virtual ~ItemDelegate() {}
    protected:
        ItemDelegate(std::string name)
            : name(name) {} 
};

class Item {
    public:
        const ItemDelegate* getData() { return _data; }
        ~Item() {
            delete _data;
            _data = nullptr;
        }
    private:
        ItemDelegate* _data;
        Item(ItemDelegate* item)
            : _data(item) {}
        friend class ItemManager;
        friend class PlayerCharacter;
};





class EquipmentDelegate : public ItemDelegate {
    public:
        StatBlock stats;
        const std::uint32_t uniqueId;
        virtual ~EquipmentDelegate() {}
    protected:
        EquipmentDelegate(std::string name, StatBlock stats);
};

enum class ARMORSLOT { HELMET, CHEST, LEGS, BOOTS, GLOVES, RING1, RING2, NECK, NUM_SLOTS };

class Armor final : public EquipmentDelegate {
    public:
        ARMORSLOT slot;
        const char* getType() override { return typeid(*this).name(); }
        ~Armor() override {}

    private:
        Armor() = delete;
        Armor(const Armor&) = delete;
        Armor(const Armor&&) = delete;

        Armor(std::string name, StatBlock stats, ARMORSLOT slot)
            : EquipmentDelegate(name, stats), slot(slot) {}
    friend class ItemManager; 
    
};

enum class WEAPONSLOT { ONEHAND, TWOHAND, OFFHAND, NUM_SLOTS };
enum class WEAPONTYPE { MELEE, RANGED, MAGIC, SHIELD, NUM_SLOTS };

class Weapon final : public EquipmentDelegate {
    public:
        WEAPONSLOT slot;
        WEAPONTYPE type;
        uint16_t minDmg;
        uint16_t maxDmg;
        const char* getType() override { return typeid(*this).name(); }
        ~Weapon() override {}

    private:
        Weapon() = delete;
        Weapon(const Weapon&) = delete;
        Weapon(const Weapon&&) = delete;
        Weapon(std::string name, StatBlock stats, uint16_t min, uint16_t max, WEAPONSLOT slot, WEAPONTYPE type)
            : EquipmentDelegate(name, stats), slot(slot), type(type), minDmg(min), maxDmg(max) {}
        friend class ItemManager; 
};
