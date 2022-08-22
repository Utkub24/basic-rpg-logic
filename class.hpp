#pragma once
#include "pointpool.hpp"
#include "statblock.hpp"
#include "ability.hpp"
#include <memory>

class Class : public StatBlock {
    public:
        virtual void levelUp() = 0;

        PointPool HP;
        std::vector<Ability> Abilites;
};