#include "item_manager.h"
Item* ItemManager::CreateArmor(std::string name, StatBlock stats, ARMORSLOT slot) {
    Item* temp_item = new Item(new Armor(name, stats, slot));
    return temp_item;
}

Item* ItemManager::CreateWeapon(std::string name, StatBlock stats, uint16_t min, uint16_t max, WEAPONSLOT slot, WEAPONTYPE type) {
    Item* temp_item = new Item(new Weapon(name, stats, min, max, slot, type));
    return temp_item;
}

Item* ItemManager::CreatePotion(std::string name, Effect* effect, uint16_t quantity) {
    Item* temp_item = new Item(new Potion(name, effect, quantity));
    return temp_item;
}

bool ItemManager::Equip(Item* item_to_equip, PlayerCharacter* p_char) {
    if(!item_to_equip || !item_to_equip->getData())
        return false;

    Armor* armor = dynamic_cast<Armor*>(item_to_equip->_data);
    if(armor) {
        unsigned long long slot_num = (unsigned long long)armor->slot;
        if(p_char->Armors[slot_num]) {
            *p_char->playerClass -= ((Armor*)p_char->Armors[slot_num]->_data)->stats;
            MoveToInventory(p_char->Armors[slot_num], p_char);

            p_char->Armors[slot_num] = item_to_equip;
            *p_char->playerClass += armor->stats;
        } else {
            p_char->Armors[slot_num] = item_to_equip;
            *p_char->playerClass += armor->stats;
        }
        return true;
    }

    Weapon* weapon = dynamic_cast<Weapon*>(item_to_equip->_data);
    if(weapon) {
        unsigned long long slot_num = (unsigned long long)weapon->slot;
        if(p_char->Weapons[slot_num]) {
            *p_char->playerClass -= ((Weapon*)p_char->Weapons[slot_num]->_data)->stats; 
            MoveToInventory(p_char->Weapons[slot_num], p_char);

            *p_char->playerClass += weapon->stats;
            p_char->Weapons[slot_num] = item_to_equip;
        } else {
            p_char->Weapons[slot_num] = item_to_equip;
            *p_char->playerClass += weapon->stats;
        }
        return true;
    }

    return false;
}

bool ItemManager::Use(Item* item_to_use, PlayerCharacter* p_char) {
    if(!p_char || !item_to_use || !item_to_use->getData() || !item_to_use->_data->isConsumable) 
        return false;

    Potion* pot = dynamic_cast<Potion*>(item_to_use->_data);
    if(pot && pot->effect) { p_char->applyEffect(pot->effect); }

    if(item_to_use->_data->quantity == 1) {
        item_to_use->marked_for_deletion = true;
        p_char->cleanInventory();
    } else {
        item_to_use->_data->quantity--;
    }
    return true;
}

bool ItemManager::MoveToInventory(Item* item_to_move, PlayerCharacter* p_char) {
        if(!p_char || !item_to_move || !item_to_move->getData()) {
            return false;
        }

        p_char->Inventory.push_back(item_to_move);
        return true;
    }

void ItemManager::DeleteItem(Item*& item_to_delete) {
    delete item_to_delete;
    item_to_delete = nullptr;
}

