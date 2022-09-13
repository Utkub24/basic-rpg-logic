#pragma once
#include <string>
#include "statblock.hpp"
#include <typeinfo>
#include "effect.hpp"
#include <iostream> //for testing

class ItemDelegate {
    public:
        std::string name;
        bool isConsumable;
        bool isStackable;
        uint16_t quantity;
        virtual const char* getType() = 0;
        virtual ~ItemDelegate() {}
    protected:
        ItemDelegate(std::string name, bool isConsumable = false, bool isStackable = false, uint16_t quantity = 1)
            : name(name), isConsumable(isConsumable), isStackable(isStackable), quantity(quantity) { if(quantity == 0) this->quantity = 1; } 
};

class Potion : public ItemDelegate {
    public:
        Effect* effect;
        const char* getType() override { return typeid(*this).name(); }

        ~Potion() {
            if(effect) {
                delete effect;
                effect = nullptr;
            }
        }

    private:
        Potion(std::string name, Effect* effect, uint16_t quantity = 1)
         :  ItemDelegate(name, true, true, quantity), effect(effect) {}

        friend class ItemManager;
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

class Item {
    public:
        const ItemDelegate* getData() { return _data; }
        ~Item() {
            if(_data) {
                delete _data;
                _data = nullptr;
            }
        }
        const bool isMarkedForDeletion() const { return marked_for_deletion; }
    private:
        ItemDelegate* _data;
        Item(ItemDelegate* item)
            : _data(item) {}
        bool marked_for_deletion = false;
        friend class ItemManager;

        friend std::ostream& operator<<(std::ostream& os, const Item& t) {
            Armor* armor = dynamic_cast<Armor*>(t._data);
            if(armor)
                return os << "-" << armor->name << "(Physical Armor: " << armor->stats.PhysArmor << ", Magic Armor: " << armor->stats.MagicArmor << ")" << std::endl;

            Weapon* weapon = dynamic_cast<Weapon*>(t._data);
            if(weapon)
                return os << "-" << weapon->name << "(Damage: " << weapon->minDmg << "-" << weapon->maxDmg << ")" << std::endl;

            Potion* pot = dynamic_cast<Potion*>(t._data);
            if(pot)
                return os << "-" << pot->name << "(" << pot->quantity << ")" << std::endl;

            return os;
        }
};
