#pragma once
#include <cstdint>

class StatBlock {
    public:
        uint16_t Str;
        uint16_t Int;
        uint16_t Dex;
        uint16_t PhysArmor;
        uint16_t MagicArmor;

        StatBlock(uint16_t n_str = 0, 
            uint16_t n_int = 0,
            uint16_t n_dex = 0,
            uint16_t n_physarm = 0,
            uint16_t n_magicarm = 0);

        void setStats(uint16_t n_str, uint16_t n_int, uint16_t n_dex, uint16_t n_physarm = 0, uint16_t n_magicarm = 0);
        void incStats(int i_str = 0, int i_int = 0, int i_dex = 0, int i_physarm = 0, int i_magicarm = 0);

        StatBlock operator+(const StatBlock& other) const;
        StatBlock operator-(const StatBlock& other) const;
        void operator+=(const StatBlock& other);
        void operator-=(const StatBlock& other);
};