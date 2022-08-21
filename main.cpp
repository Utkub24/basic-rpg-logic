#include <iostream>
#include "playercharacter.hpp"

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
    << "-Exp: " << mister.getCurrentExp() << "/" << mister.getExpForNextLevel() << std::endl;

    mister.gainExp(567);
    std::cout << "Mister's stats: " << std::endl
    << "-HP: " << mister.getCurrentHp() << "/" << mister.getMaxHp() << std::endl
    << "-Strength: " << mister.getClass()->Str << std::endl
    << "-Intelligence: " << mister.getClass()->Int << std::endl
    << "-Dexterity: " << mister.getClass()->Dex << std::endl
    << "-Physical Armor: " << mister.getClass()->PhysArmor << std::endl
    << "-Magical Armor: " << mister.getClass()->MagicArmor << std::endl
    << "-Level: " << mister.getCurrentLevel() << std::endl
    << "-Exp: " << mister.getCurrentExp() << "/" << mister.getExpForNextLevel() << std::endl;

    return 0;
}