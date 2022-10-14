#pragma once
#include "class.h"
#include <map>
#include "macros.hpp"

class Cleric final : public Class {
    public:
        Cleric();
        void levelUp(LevelSystem* levelsys) override;
        ~Cleric() override;
        BASESTATS_H;
        static const uint16_t BASEMP;
        PointPool MP;
        static const std::map<std::string, Ability> ClericAbilities;
    private:
};