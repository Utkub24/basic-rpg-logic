#include "item.h"

static uint32_t EQUIPMENTUNIQUEIDITERATOR = 0u;


ItemDelegate::~ItemDelegate() {}
ItemDelegate::ItemDelegate(std::string name, bool isConsumable, bool isStackable, uint16_t quantity)
    : name(name), isConsumable(isConsumable), isStackable(isStackable), quantity(quantity) { if(quantity == 0) this->quantity = 1; } 


Potion::~Potion() {
    if(effect) {
        delete effect;
        effect = nullptr;
    }
}

Potion::Potion(std::string name, Effect* effect, uint16_t quantity)
    :  ItemDelegate(name, true, true, quantity), effect(effect) {}


EquipmentDelegate::~EquipmentDelegate() {}
EquipmentDelegate::EquipmentDelegate(std::string name, StatBlock stats)
    : ItemDelegate(name), stats(stats), UniqueID(EQUIPMENTUNIQUEIDITERATOR++) {}


Armor::~Armor() {}
Armor::Armor(std::string name, StatBlock stats, ARMORSLOT slot)
    : EquipmentDelegate(name, stats), slot(slot) {}

Weapon::~Weapon() {}
Weapon::Weapon(std::string name, StatBlock stats, uint16_t min, uint16_t max, WEAPONSLOT slot, WEAPONTYPE type)
    : EquipmentDelegate(name, stats), slot(slot), type(type), minDmg(min), maxDmg(max) {}

const ItemDelegate* Item::getData() const { return _data; }
Item::~Item() {
    if(_data) {
        delete _data;
        _data = nullptr;
    }
}
const bool Item::isMarkedForDeletion() const { return marked_for_deletion; }
Item::Item(ItemDelegate* item) 
    : _data(item) {}