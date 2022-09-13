cmake_minimum_required(VERSION 3.14)

project(demo_rpg CXX)

set(This demo_rpg)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(googletest)
#add_subdirectory(include)
add_subdirectory(src)


set(SOURCES
    demorpg.cpp
    item.cpp
)


set(HEADERS

)

#add_library(demo_rpg STATIC ${SOURCES})

add_subdirectory(test)