#pragma once
#include "pointpool.h"

class Monster {
    public:
        Monster(uint16_t hp, uint16_t min, uint16_t max);
        PointPool HP;
        [[nodiscard]] const uint16_t getAttackVal() const noexcept;
        [[nodiscard]] const uint16_t getMinDamage() const noexcept;
        [[nodiscard]] const uint16_t getMaxDamage() const noexcept;
    private:
        uint16_t minDmg, maxDmg;
        Monster() = delete;
        Monster(const Monster&) = delete;
        Monster(const Monster&&) = delete;
};
