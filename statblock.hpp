#pragma once

class StatBlock {
    public:
        uint16_t Str;
        uint16_t Int;
        uint16_t Dex;
        uint16_t PhysArmor;
        uint16_t MagicArmor;

        StatBlock(uint16_t n_str = 1, uint16_t n_int = 1, uint16_t n_dex = 1, uint16_t n_physarm = 0, uint16_t n_magicarm = 0)
            : Str(n_str), Int(n_int), Dex(n_dex), PhysArmor(n_physarm), MagicArmor(n_magicarm) {} 

        void setStats(uint16_t n_str, uint16_t n_int, uint16_t n_dex) {
            Str = n_str;
            Int = n_int;
            Dex = n_dex;
        }

        void incStats(int i_str = 0, int i_int = 0, int i_dex = 0) {
            Str += i_str;
            Int += i_int;
            Dex += i_dex;
        }

    private:

};
