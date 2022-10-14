#pragma once
#include "pointpool.h"
#include "statblock.h"
#include "levelsystem.h"
#include "ability.h"
#include <vector>

class Class : public StatBlock {
    public:
        virtual void levelUp(LevelSystem* levelsys) = 0;
        virtual ~Class();

        PointPool HP;
        std::vector<Ability> Abilities;
};