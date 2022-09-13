#include "statblock.h"

StatBlock::StatBlock(uint16_t n_str = 0, uint16_t n_int = 0, uint16_t n_dex = 0, uint16_t n_physarm = 0, uint16_t n_magicarm = 0)
    : Str(n_str), Int(n_int), Dex(n_dex), PhysArmor(n_physarm), MagicArmor(n_magicarm) {} 

void StatBlock::setStats(uint16_t n_str, uint16_t n_int, uint16_t n_dex, uint16_t n_physarm, uint16_t n_magicarm) {
    Str = n_str;
    Int = n_int;
    Dex = n_dex;
    PhysArmor = n_physarm;
    MagicArmor = n_magicarm;
}

void StatBlock::incStats(int i_str = 0, int i_int = 0, int i_dex = 0, int i_physarm = 0, int i_magarm = 0) {
    Str += i_str;
    Int += i_int;
    Dex += i_dex;
    PhysArmor += i_physarm;
    MagicArmor += i_magarm;
}

StatBlock StatBlock::operator+(const StatBlock& other) const {
    return StatBlock(Str + other.Str, Int + other.Int, Dex + other.Dex, PhysArmor + other.PhysArmor, MagicArmor + other.MagicArmor);
}

StatBlock StatBlock::operator-(const StatBlock& other) const {
    return StatBlock(Str - other.Str, Int - other.Int, Dex - other.Dex, PhysArmor - other.PhysArmor, MagicArmor - other.MagicArmor);
}

void StatBlock::operator+=(const StatBlock& other) {
    this->Str += other.Str;
    this->Int += other.Int;
    this->Dex += other.Dex;
    this->PhysArmor += other.PhysArmor;
    this->MagicArmor += other.MagicArmor;
}

void StatBlock::operator-=(const StatBlock& other) {
    this->Str -= other.Str;
    this->Int -= other.Int;
    this->Dex -= other.Dex;
    this->PhysArmor -= other.PhysArmor;
    this->MagicArmor -= other.MagicArmor;
}



