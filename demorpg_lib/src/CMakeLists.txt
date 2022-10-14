include_directories(${demo_rpg_SOURCE_DIR}/demorpg_lib/include)

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
    class.cpp
    monster.cpp
    random.cpp
)

add_library(demo_rpg_lib ${SOURCE})