#pragma once
#include <string>
#include "statblock.h"
#include "effect.h"

class ItemDelegate {
    public:
        std::string name;
        bool isConsumable;
        bool isStackable;
        uint16_t quantity;

    protected:
        virtual ~ItemDelegate();
        ItemDelegate(std::string name, bool isConsumable = false, bool isStackable = false, uint16_t quantity = 1);
        friend class Item;
};

class Potion : public ItemDelegate {
    public:
        Effect* effect;
        ~Potion();
    
    private:
        Potion(std::string name, Effect* effect, uint16_t quantity = 1);
        friend class ItemManager;
};

class EquipmentDelegate : public ItemDelegate {
    public:
        const uint32_t UniqueID;
        StatBlock stats;
        virtual ~EquipmentDelegate();
    protected:
        EquipmentDelegate(std::string name, StatBlock stats);

};

enum class ARMORSLOT { HELMET, CHEST, LEGS, BOOTS, GLOVES, RING1, RING2, NECK, NUM_SLOTS };

class Armor final : public EquipmentDelegate {
    public:
        ARMORSLOT slot;
        ~Armor() override;

    private:
        Armor() = delete;
        Armor(const Armor&) = delete;
        Armor(const Armor&&) = delete;

        Armor(std::string name, StatBlock stats, ARMORSLOT slot);
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
        ~Weapon() override;

    private:
        Weapon() = delete;
        Weapon(const Weapon&) = delete;
        Weapon(const Weapon&&) = delete;

        Weapon(std::string name, StatBlock stats, uint16_t min, uint16_t max, WEAPONSLOT slot, WEAPONTYPE type);
        friend class ItemManager;
};

class Item {
    public:
        const ItemDelegate* getData() const;
        ~Item();
        const bool isMarkedForDeletion() const;
    
    private:
        ItemDelegate* _data;
        Item(ItemDelegate* item);
        bool marked_for_deletion = false;
        friend class ItemManager;


};