#pragma once
#include "item.h"
#include "playercharacter.h"

class ItemManager {
    public:
        static Item* CreateArmor(std::string name, StatBlock stats, ARMORSLOT slot);
        static Item* CreateWeapon(std::string name, StatBlock stats, uint16_t min, uint16_t max, WEAPONSLOT slot, WEAPONTYPE type);
        static Item* CreatePotion(std::string name, Effect* effect, uint16_t quantity);
        static bool Equip(Item* item_to_equip, PlayerCharacter* p_char);
        static bool Use(Item* item_to_use, PlayerCharacter* p_char);
        static bool MoveToInventory(Item* item_to_move, PlayerCharacter* p_char);
        static void DeleteItem(Item*& item_to_delete);
};
static Item* HPPOT = ItemManager::CreatePotion("Healing Potion", new Effect(), 1);