# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/orka/Projects/demorpg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/orka/Projects/demorpg/build

# Include any dependencies generated for this target.
include src/CMakeFiles/demo_rpg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/demo_rpg.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/demo_rpg.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/demo_rpg.dir/flags.make

src/CMakeFiles/demo_rpg.dir/demorpg.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/demorpg.cpp.o: /home/orka/Projects/demorpg/src/demorpg.cpp
src/CMakeFiles/demo_rpg.dir/demorpg.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/demo_rpg.dir/demorpg.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/demorpg.cpp.o -MF CMakeFiles/demo_rpg.dir/demorpg.cpp.o.d -o CMakeFiles/demo_rpg.dir/demorpg.cpp.o -c /home/orka/Projects/demorpg/src/demorpg.cpp

src/CMakeFiles/demo_rpg.dir/demorpg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/demorpg.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/demorpg.cpp > CMakeFiles/demo_rpg.dir/demorpg.cpp.i

src/CMakeFiles/demo_rpg.dir/demorpg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/demorpg.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/demorpg.cpp -o CMakeFiles/demo_rpg.dir/demorpg.cpp.s

src/CMakeFiles/demo_rpg.dir/ability.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/ability.cpp.o: /home/orka/Projects/demorpg/src/ability.cpp
src/CMakeFiles/demo_rpg.dir/ability.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/demo_rpg.dir/ability.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/ability.cpp.o -MF CMakeFiles/demo_rpg.dir/ability.cpp.o.d -o CMakeFiles/demo_rpg.dir/ability.cpp.o -c /home/orka/Projects/demorpg/src/ability.cpp

src/CMakeFiles/demo_rpg.dir/ability.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/ability.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/ability.cpp > CMakeFiles/demo_rpg.dir/ability.cpp.i

src/CMakeFiles/demo_rpg.dir/ability.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/ability.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/ability.cpp -o CMakeFiles/demo_rpg.dir/ability.cpp.s

src/CMakeFiles/demo_rpg.dir/pointpool.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/pointpool.cpp.o: /home/orka/Projects/demorpg/src/pointpool.cpp
src/CMakeFiles/demo_rpg.dir/pointpool.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/demo_rpg.dir/pointpool.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/pointpool.cpp.o -MF CMakeFiles/demo_rpg.dir/pointpool.cpp.o.d -o CMakeFiles/demo_rpg.dir/pointpool.cpp.o -c /home/orka/Projects/demorpg/src/pointpool.cpp

src/CMakeFiles/demo_rpg.dir/pointpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/pointpool.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/pointpool.cpp > CMakeFiles/demo_rpg.dir/pointpool.cpp.i

src/CMakeFiles/demo_rpg.dir/pointpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/pointpool.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/pointpool.cpp -o CMakeFiles/demo_rpg.dir/pointpool.cpp.s

src/CMakeFiles/demo_rpg.dir/statblock.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/statblock.cpp.o: /home/orka/Projects/demorpg/src/statblock.cpp
src/CMakeFiles/demo_rpg.dir/statblock.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/demo_rpg.dir/statblock.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/statblock.cpp.o -MF CMakeFiles/demo_rpg.dir/statblock.cpp.o.d -o CMakeFiles/demo_rpg.dir/statblock.cpp.o -c /home/orka/Projects/demorpg/src/statblock.cpp

src/CMakeFiles/demo_rpg.dir/statblock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/statblock.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/statblock.cpp > CMakeFiles/demo_rpg.dir/statblock.cpp.i

src/CMakeFiles/demo_rpg.dir/statblock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/statblock.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/statblock.cpp -o CMakeFiles/demo_rpg.dir/statblock.cpp.s

src/CMakeFiles/demo_rpg.dir/levelsystem.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/levelsystem.cpp.o: /home/orka/Projects/demorpg/src/levelsystem.cpp
src/CMakeFiles/demo_rpg.dir/levelsystem.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/demo_rpg.dir/levelsystem.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/levelsystem.cpp.o -MF CMakeFiles/demo_rpg.dir/levelsystem.cpp.o.d -o CMakeFiles/demo_rpg.dir/levelsystem.cpp.o -c /home/orka/Projects/demorpg/src/levelsystem.cpp

src/CMakeFiles/demo_rpg.dir/levelsystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/levelsystem.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/levelsystem.cpp > CMakeFiles/demo_rpg.dir/levelsystem.cpp.i

src/CMakeFiles/demo_rpg.dir/levelsystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/levelsystem.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/levelsystem.cpp -o CMakeFiles/demo_rpg.dir/levelsystem.cpp.s

src/CMakeFiles/demo_rpg.dir/cleric.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/cleric.cpp.o: /home/orka/Projects/demorpg/src/cleric.cpp
src/CMakeFiles/demo_rpg.dir/cleric.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/demo_rpg.dir/cleric.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/cleric.cpp.o -MF CMakeFiles/demo_rpg.dir/cleric.cpp.o.d -o CMakeFiles/demo_rpg.dir/cleric.cpp.o -c /home/orka/Projects/demorpg/src/cleric.cpp

src/CMakeFiles/demo_rpg.dir/cleric.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/cleric.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/cleric.cpp > CMakeFiles/demo_rpg.dir/cleric.cpp.i

src/CMakeFiles/demo_rpg.dir/cleric.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/cleric.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/cleric.cpp -o CMakeFiles/demo_rpg.dir/cleric.cpp.s

src/CMakeFiles/demo_rpg.dir/effect.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/effect.cpp.o: /home/orka/Projects/demorpg/src/effect.cpp
src/CMakeFiles/demo_rpg.dir/effect.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/demo_rpg.dir/effect.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/effect.cpp.o -MF CMakeFiles/demo_rpg.dir/effect.cpp.o.d -o CMakeFiles/demo_rpg.dir/effect.cpp.o -c /home/orka/Projects/demorpg/src/effect.cpp

src/CMakeFiles/demo_rpg.dir/effect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/effect.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/effect.cpp > CMakeFiles/demo_rpg.dir/effect.cpp.i

src/CMakeFiles/demo_rpg.dir/effect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/effect.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/effect.cpp -o CMakeFiles/demo_rpg.dir/effect.cpp.s

src/CMakeFiles/demo_rpg.dir/item.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/item.cpp.o: /home/orka/Projects/demorpg/src/item.cpp
src/CMakeFiles/demo_rpg.dir/item.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/demo_rpg.dir/item.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/item.cpp.o -MF CMakeFiles/demo_rpg.dir/item.cpp.o.d -o CMakeFiles/demo_rpg.dir/item.cpp.o -c /home/orka/Projects/demorpg/src/item.cpp

src/CMakeFiles/demo_rpg.dir/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/item.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/item.cpp > CMakeFiles/demo_rpg.dir/item.cpp.i

src/CMakeFiles/demo_rpg.dir/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/item.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/item.cpp -o CMakeFiles/demo_rpg.dir/item.cpp.s

src/CMakeFiles/demo_rpg.dir/item_manager.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/item_manager.cpp.o: /home/orka/Projects/demorpg/src/item_manager.cpp
src/CMakeFiles/demo_rpg.dir/item_manager.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/demo_rpg.dir/item_manager.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/item_manager.cpp.o -MF CMakeFiles/demo_rpg.dir/item_manager.cpp.o.d -o CMakeFiles/demo_rpg.dir/item_manager.cpp.o -c /home/orka/Projects/demorpg/src/item_manager.cpp

src/CMakeFiles/demo_rpg.dir/item_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/item_manager.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/item_manager.cpp > CMakeFiles/demo_rpg.dir/item_manager.cpp.i

src/CMakeFiles/demo_rpg.dir/item_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/item_manager.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/item_manager.cpp -o CMakeFiles/demo_rpg.dir/item_manager.cpp.s

src/CMakeFiles/demo_rpg.dir/playercharacter.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/playercharacter.cpp.o: /home/orka/Projects/demorpg/src/playercharacter.cpp
src/CMakeFiles/demo_rpg.dir/playercharacter.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/demo_rpg.dir/playercharacter.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/playercharacter.cpp.o -MF CMakeFiles/demo_rpg.dir/playercharacter.cpp.o.d -o CMakeFiles/demo_rpg.dir/playercharacter.cpp.o -c /home/orka/Projects/demorpg/src/playercharacter.cpp

src/CMakeFiles/demo_rpg.dir/playercharacter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/playercharacter.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/playercharacter.cpp > CMakeFiles/demo_rpg.dir/playercharacter.cpp.i

src/CMakeFiles/demo_rpg.dir/playercharacter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/playercharacter.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/playercharacter.cpp -o CMakeFiles/demo_rpg.dir/playercharacter.cpp.s

src/CMakeFiles/demo_rpg.dir/class.cpp.o: src/CMakeFiles/demo_rpg.dir/flags.make
src/CMakeFiles/demo_rpg.dir/class.cpp.o: /home/orka/Projects/demorpg/src/class.cpp
src/CMakeFiles/demo_rpg.dir/class.cpp.o: src/CMakeFiles/demo_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/demo_rpg.dir/class.cpp.o"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo_rpg.dir/class.cpp.o -MF CMakeFiles/demo_rpg.dir/class.cpp.o.d -o CMakeFiles/demo_rpg.dir/class.cpp.o -c /home/orka/Projects/demorpg/src/class.cpp

src/CMakeFiles/demo_rpg.dir/class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_rpg.dir/class.cpp.i"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orka/Projects/demorpg/src/class.cpp > CMakeFiles/demo_rpg.dir/class.cpp.i

src/CMakeFiles/demo_rpg.dir/class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_rpg.dir/class.cpp.s"
	cd /home/orka/Projects/demorpg/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orka/Projects/demorpg/src/class.cpp -o CMakeFiles/demo_rpg.dir/class.cpp.s

# Object files for target demo_rpg
demo_rpg_OBJECTS = \
"CMakeFiles/demo_rpg.dir/demorpg.cpp.o" \
"CMakeFiles/demo_rpg.dir/ability.cpp.o" \
"CMakeFiles/demo_rpg.dir/pointpool.cpp.o" \
"CMakeFiles/demo_rpg.dir/statblock.cpp.o" \
"CMakeFiles/demo_rpg.dir/levelsystem.cpp.o" \
"CMakeFiles/demo_rpg.dir/cleric.cpp.o" \
"CMakeFiles/demo_rpg.dir/effect.cpp.o" \
"CMakeFiles/demo_rpg.dir/item.cpp.o" \
"CMakeFiles/demo_rpg.dir/item_manager.cpp.o" \
"CMakeFiles/demo_rpg.dir/playercharacter.cpp.o" \
"CMakeFiles/demo_rpg.dir/class.cpp.o"

# External object files for target demo_rpg
demo_rpg_EXTERNAL_OBJECTS =

src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/demorpg.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/ability.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/pointpool.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/statblock.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/levelsystem.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/cleric.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/effect.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/item.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/item_manager.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/playercharacter.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/class.cpp.o
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/build.make
src/libdemo_rpg.a: src/CMakeFiles/demo_rpg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/orka/Projects/demorpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX static library libdemo_rpg.a"
	cd /home/orka/Projects/demorpg/build/src && $(CMAKE_COMMAND) -P CMakeFiles/demo_rpg.dir/cmake_clean_target.cmake
	cd /home/orka/Projects/demorpg/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo_rpg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/demo_rpg.dir/build: src/libdemo_rpg.a
.PHONY : src/CMakeFiles/demo_rpg.dir/build

src/CMakeFiles/demo_rpg.dir/clean:
	cd /home/orka/Projects/demorpg/build/src && $(CMAKE_COMMAND) -P CMakeFiles/demo_rpg.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/demo_rpg.dir/clean

src/CMakeFiles/demo_rpg.dir/depend:
	cd /home/orka/Projects/demorpg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orka/Projects/demorpg /home/orka/Projects/demorpg/src /home/orka/Projects/demorpg/build /home/orka/Projects/demorpg/build/src /home/orka/Projects/demorpg/build/src/CMakeFiles/demo_rpg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/demo_rpg.dir/depend
