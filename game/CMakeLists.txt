cmake_minimum_required(VERSION 3.14)

set(This demo_rpg_game)
set(SOURCES main.cpp)

add_executable(${This} ${SOURCES})

target_link_libraries(${This} PUBLIC
    demo_rpg
)