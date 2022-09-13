#include "levelsystem.h"

LevelSystem::LevelSystem()
    : level(1), exp(0), nextLevelLimit(EXPTO2) {}

uint16_t LevelSystem::get() const { return level; }
void LevelSystem::set(uint16_t n_lvl) { level = n_lvl; }
void LevelSystem::incLevel(uint16_t i_lvl) { level += i_lvl; }

uint32_t LevelSystem::getCurrentExp() const { return exp; }
void LevelSystem::gainExp(uint32_t i_exp) { exp += i_exp; }
void LevelSystem::setExp(uint32_t n_exp) { exp = n_exp; }

uint32_t LevelSystem::getExpForNextLevel() const { return nextLevelLimit; }
void LevelSystem::incLevelLimit() { nextLevelLimit *= EXPMULTIPLIER; }