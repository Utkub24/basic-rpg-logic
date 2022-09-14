cmake_minimum_required(VERSION 3.14)

set(This demo_rpg_test)
set(SOURCES test.cpp)

add_executable(${This} ${SOURCES})

target_link_libraries(${This} PUBLIC
    gtest_main
    demo_rpg
)

add_test(
    NAME ${This}
    COMMAND ${This}
)