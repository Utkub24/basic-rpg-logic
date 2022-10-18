#include "playercharacter.h"
#include "item_manager.h"
#include "random.h"

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
        if(Armors[i]) { ItemManager::DeleteItem(Armors[i]); }
    }
    for(int i = 0; i < 2; i++) {
        if(Weapons[i]) { ItemManager::DeleteItem(Weapons[i]); }
    }
}

const uint16_t PlayerCharacter::getMaxHp() const noexcept { return playerClass->HP.getMax(); }
const uint16_t PlayerCharacter::getCurrentHp()  const noexcept { return playerClass->HP.getCurrent(); }
const uint16_t PlayerCharacter::getCurrentLevel() const noexcept { return playerLevel->get(); }
const uint32_t PlayerCharacter::getCurrentExp() const noexcept { return playerLevel->getCurrentExp(); }
const uint32_t PlayerCharacter::getExpForNextLevel() const noexcept { return playerLevel->getExpForNextLevel(); }
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




const Armor* PlayerCharacter::getEquippedArmorAt(unsigned long long i) const noexcept {
    if(!Armors[i]) return nullptr;
    return dynamic_cast<const Armor*>(Armors[i]->getData());
}
const Weapon* PlayerCharacter::getEquippedWeaponAt(unsigned long long i) const noexcept {
    if(!Weapons[i]) return nullptr;
    return dynamic_cast<const Weapon*>(Weapons[i]->getData());
}

// Either use a normal ptr to access stats directly
// or use a unique ptr and make getters for stats
const Class* PlayerCharacter::getClass() const noexcept { return playerClass; }
const std::vector<Effect> PlayerCharacter::getEffects() const noexcept { return Effects; }
const std::vector<Item*> PlayerCharacter::getInventory() const noexcept { return Inventory; }

const uint16_t PlayerCharacter::getAttackVal() const noexcept {
    uint16_t tmp_dmg_done;

    const Weapon* equipped_weapon = getEquippedWeaponAt((unsigned long long)WEAPONSLOT::ONEHAND);
    if(equipped_weapon) {
        tmp_dmg_done = Random::NTK(equipped_weapon->minDmg, equipped_weapon->maxDmg);
    } else {
        tmp_dmg_done = Random::NTK(1, 4); // unarmed attack
    }

    // add 1/4 of the weapon's scaling stat
    uint16_t tmp_dmg_modifier;
    switch(equipped_weapon->type) {
        case WEAPONTYPE::MAGIC:
            tmp_dmg_modifier = playerClass->Int/4.f;
        case WEAPONTYPE::MELEE:
            tmp_dmg_modifier = playerClass->Str/4.f;
        case WEAPONTYPE::RANGED:
            tmp_dmg_modifier = playerClass->Dex/4.f;
    }

    tmp_dmg_done += tmp_dmg_modifier;
    return tmp_dmg_done;
}

const bool PlayerCharacter::isAlive() const noexcept { return getCurrentHp() > 0; }

void PlayerCharacter::reduceHp(uint16_t i_hp) noexcept { playerClass->HP.reduce(i_hp); }
void PlayerCharacter::increaseHp(uint16_t i_hp) noexcept { playerClass->HP.increase(i_hp); }


void PlayerCharacter::cleanInventory() {
    const auto to_remove = std::stable_partition(Inventory.begin(), Inventory.end(),
        [](const Item* i) -> bool { return !i->isMarkedForDeletion(); });
    std::for_each(to_remove, Inventory.end(), [](Item* i) { ItemManager::DeleteItem(i); });
    Inventory.erase(to_remove, Inventory.end()); 
}