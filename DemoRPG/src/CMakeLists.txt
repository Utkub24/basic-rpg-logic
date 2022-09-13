include_directories(${demo_rpg_SOURCE_DIR}/include)

set(SOURCE
    demorpg.cpp
    ability.cpp
    pointpool.cpp
    statblock.cpp
    levelsystem.cpp
    cleric.cpp
    effect.cpp
    item.cpp
    item_manager.cpp
    playercharacter.cpp
)

add_library(demo_rpg ${SOURCE})
