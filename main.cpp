#include <iostream>
#include "playercharacter.hpp"
#include "cleric.hpp"

int main() {
    PlayerCharacter mister(new Cleric());
    std::cout << "Mister's stats: " << std::endl
    << "-HP: " << mister.getCurrentHp() << "/" << mister.getMaxHp() << std::endl
    << "-Strength: " << mister.getClass()->Str << std::endl
    << "-Intelligence: " << mister.getClass()->Int << std::endl
    << "-Dexterity: " << mister.getClass()->Dex << std::endl
    << "-Physical Armor: " << mister.getClass()->PhysArmor << std::endl
    << "-Magical Armor: " << mister.getClass()->MagicArmor << std::endl
    << "-Level: " << mister.getCurrentLevel() << std::endl
    << "-Exp: " << mister.getCurrentExp() << "/" << mister.getExpForNextLevel() << std::endl
    << "Abilities: " << std::endl;
    for(auto& ability : mister.getClass()->Abilites) {
        std::cout << "-" << ability.name << std::endl;
    }
    std::cout << "Effects: " << std::endl;
    for(auto& e: mister.getEffects()) {
        std::cout << "-" << e.name << std::endl;
    }

    Effect stony("Stone Shield", 1, 0, 0, 0, 10, 0);
    mister.applyEffect(stony);

    mister.gainExp(567);
    std::cout << "Mister's stats: " << std::endl
    << "-HP: " << mister.getCurrentHp() << "/" << mister.getMaxHp() << std::endl
    << "-Strength: " << mister.getClass()->Str << std::endl
    << "-Intelligence: " << mister.getClass()->Int << std::endl
    << "-Dexterity: " << mister.getClass()->Dex << std::endl
    << "-Physical Armor: " << mister.getClass()->PhysArmor << std::endl
    << "-Magical Armor: " << mister.getClass()->MagicArmor << std::endl
    << "-Level: " << mister.getCurrentLevel() << std::endl
    << "-Exp: " << mister.getCurrentExp() << "/" << mister.getExpForNextLevel() << std::endl
    << "Abilities: " << std::endl;
    for(auto& ability : mister.getClass()->Abilites) {
        std::cout << "-" << ability.name << std::endl;
    }
    std::cout << "Effects: " << std::endl;
    for(auto& e: mister.getEffects()) {
        std::cout << "-" << e.name << std::endl;
    }



    return 0;
}