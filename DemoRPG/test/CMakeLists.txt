cmake_minimum_required(VERSION 3.14)

set(This demo_rpg_tests)

set(SOURCES
    test.cpp
)

add_executable(${This} ${SOURCES})
target_link_libraries(${This} PUBLIC
    gtest_main
    demo_rpg
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

target_include_directories(demo_rpg_tests PRIVATE ${demo_rpg_SOURCE_DIR}/include)