#pragma once
#include "pointpool.hpp"
#include "statblock.hpp"
#include "ability.hpp"
#include <memory>
#include "levelsystem.hpp"

class Class : public StatBlock {
    public:
        virtual void levelUp(LevelSystem* levelsys) = 0;

        PointPool HP;
        std::vector<Ability> Abilites;

};