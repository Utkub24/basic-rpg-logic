#include "playercharacter.h"

PlayerCharacter::PlayerCharacter(Class* a_class)
    : playerClass(a_class), playerLevel(new LevelSystem()) {
        for(int i = 0; i < (int)ARMORSLOT::NUM_SLOTS; i++) { Armors[i] = nullptr; }
        for(int i = 0; i < 2; i++) { Weapons[i] = nullptr; }
} 

PlayerCharacter::~PlayerCharacter() {
    delete playerClass;    
    playerClass = nullptr; 
    delete playerLevel;
    playerLevel = nullptr;

    for(int i = 0; i < (int)ARMORSLOT::NUM_SLOTS; i++) {
        if(Armors[i]) { delete Armors[i]; Armors[i] = nullptr; }
    }
    for(int i = 0; i < 2; i++) {
        if(Weapons[i]) { delete Weapons[i]; Weapons[i] = nullptr; }
    }
}

const uint16_t PlayerCharacter::getMaxHp() const { return playerClass->HP.getMax(); }
const uint16_t PlayerCharacter::getCurrentHp()  const { return playerClass->HP.getCurrent(); }
const uint16_t PlayerCharacter::getCurrentLevel() const { return playerLevel->get(); }
const uint32_t PlayerCharacter::getCurrentExp() const { return playerLevel->getCurrentExp(); }
const uint32_t PlayerCharacter::getExpForNextLevel() const { return playerLevel->getExpForNextLevel(); }
void PlayerCharacter::gainExp(uint32_t i_exp ) { 
    playerLevel->gainExp(i_exp);
    checkLevel();
}

void PlayerCharacter::checkLevel() {
    while (playerLevel->getCurrentExp() >= playerLevel->getExpForNextLevel()) {
        playerLevel->incLevel();
        playerClass->levelUp(playerLevel);
        playerLevel->incLevelLimit();
    }
}

void PlayerCharacter::applyEffect(Effect* e) {
    for(auto& effect : Effects) {
        if(e->name == effect.name) {
            effect.duration = e->duration;
            return;
        }
    }
    Effects.push_back(*e);
    playerClass->incStats(e->strEff, e->intEff, e->dexEff, e->physArmEff, e->magicArmEff);
}




const Armor* PlayerCharacter::getEquippedArmorAt(unsigned long long i) const {
    if(!Armors[i]) return nullptr;
    return dynamic_cast<const Armor*>(Armors[i]->getData());
}
const Weapon* PlayerCharacter::getEquippedWeaponAt(unsigned long long i) const {
    if(!Weapons[i]) return nullptr;
    return dynamic_cast<const Weapon*>(Weapons[i]->getData());
}

// Either use a normal ptr to access stats directly
// or use a unique ptr and make getters for stats
const Class* PlayerCharacter::getClass() const { return playerClass; }
const std::vector<Effect> PlayerCharacter::getEffects() const { return Effects; }
const std::vector<Item*> PlayerCharacter::getInventory() const { return Inventory; }

void PlayerCharacter::cleanInventory() {
    const auto to_remove = std::stable_partition(Inventory.begin(), Inventory.end(),
        [](const Item* i) -> bool { return !i->isMarkedForDeletion(); });
    std::for_each(to_remove, Inventory.end(), [](Item* i) { delete i; });
    Inventory.erase(to_remove, Inventory.end()); 
}