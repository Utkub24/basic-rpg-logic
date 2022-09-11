#pragma once
#include "item.hpp"

class ItemManager {
    public:
        static Item* CreateArmor(std::string name, StatBlock stats, ARMORSLOT slot) {
            Item* temp_item = new Item(new Armor(name, stats, slot));
            return temp_item;
        }

        static Item* CreateWeapon(std::string name, StatBlock stats, uint16_t min, uint16_t max, WEAPONSLOT slot, WEAPONTYPE type) {
            Item* temp_item = new Item(new Weapon(name, stats, min, max, slot, type));
            return temp_item;
        }

        static Item* CreatePotion(std::string name, Effect* effect) {

        }


};