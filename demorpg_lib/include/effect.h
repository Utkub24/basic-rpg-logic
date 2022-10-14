#pragma once
#include "statblock.h"
#include <string>

struct Effect {
    Effect(std::string a_name = "unnamed", 
    uint16_t a_dur = 1,
    int i_str = 0,
    int i_int = 0,
    int i_dex = 0,
    int i_physarm = 0,
    int i_magarm = 0);

    std::string name;
    uint16_t duration;
    int strEff;
    int intEff;
    int dexEff;
    int physArmEff;
    int magicArmEff;

   
};
