#include "monster.h"
#include "random.h"

Monster::Monster(uint16_t hp, uint16_t min, uint16_t max)
    : HP(hp ,hp), minDmg(min), maxDmg(max) {}

const uint16_t Monster::getAttackVal() const noexcept { return Random::NTK(minDmg, maxDmg); }
const uint16_t Monster::getMinDamage() const noexcept { return minDmg; }
const uint16_t Monster::getMaxDamage() const noexcept { return maxDmg; }



