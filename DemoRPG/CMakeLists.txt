cmake_minimum_required(VERSION 3.14)

project(demo_rpg CXX)

set(This demo_rpg)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg

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