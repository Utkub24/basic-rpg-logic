#include "item.hpp"

// only the EquipmentDelegate constructor should change this
static std::uint32_t EQUIPMENTUNIQUEIDITERATOR = 0u;

EquipmentDelegate::EquipmentDelegate(std::string name, StatBlock stats)
    : ItemDelegate(name), stats(stats), uniqueId(++EQUIPMENTUNIQUEIDITERATOR) {}