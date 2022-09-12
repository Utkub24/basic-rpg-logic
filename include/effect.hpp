#pragma once
#include "statblock.hpp"
#include <string>

struct Effect {
    Effect(std::string a_name, uint16_t a_dur, int i_str, int i_int, int i_dex, int i_physarm, int i_magarm) 
        : name(a_name), duration(a_dur), strEff(i_str), intEff(i_int), dexEff(i_dex), physArmEff(i_physarm), magicArmEff(i_magarm) {}

    std::string name = "unnamed";
    uint16_t duration = 1;
    int strEff = 0;
    int intEff = 0;
    int dexEff = 0;
    int physArmEff = 0;
    int magicArmEff = 0;

};