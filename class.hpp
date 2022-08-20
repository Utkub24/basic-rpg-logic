#pragma once
#include "pointpool.hpp"
#include "statblock.hpp"

class Class : public StatBlock {
    public:
        Class() = delete;
        Class(uint16_t n_mhp) { HP.setMax(n_mhp); HP.setVal(n_mhp); }
        virtual void levelUp() = 0;

        PointPool HP;
};