# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/antek/Videos/zad5_3-AntoniJeziorski

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antek/Videos/zad5_3-AntoniJeziorski/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/unit_tests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/unit_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/unit_tests.dir/flags.make

tests/CMakeFiles/unit_tests.dir/main.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/main.cpp.o: ../tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/unit_tests.dir/main.cpp.o"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/main.cpp.o -c /home/antek/Videos/zad5_3-AntoniJeziorski/tests/main.cpp

tests/CMakeFiles/unit_tests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/main.cpp.i"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Videos/zad5_3-AntoniJeziorski/tests/main.cpp > CMakeFiles/unit_tests.dir/main.cpp.i

tests/CMakeFiles/unit_tests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/main.cpp.s"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Videos/zad5_3-AntoniJeziorski/tests/main.cpp -o CMakeFiles/unit_tests.dir/main.cpp.s

tests/CMakeFiles/unit_tests.dir/test_matrix3D.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/test_matrix3D.cpp.o: ../tests/test_matrix3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/unit_tests.dir/test_matrix3D.cpp.o"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/test_matrix3D.cpp.o -c /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_matrix3D.cpp

tests/CMakeFiles/unit_tests.dir/test_matrix3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/test_matrix3D.cpp.i"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_matrix3D.cpp > CMakeFiles/unit_tests.dir/test_matrix3D.cpp.i

tests/CMakeFiles/unit_tests.dir/test_matrix3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/test_matrix3D.cpp.s"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_matrix3D.cpp -o CMakeFiles/unit_tests.dir/test_matrix3D.cpp.s

tests/CMakeFiles/unit_tests.dir/test_vector3D.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/test_vector3D.cpp.o: ../tests/test_vector3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/unit_tests.dir/test_vector3D.cpp.o"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/test_vector3D.cpp.o -c /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_vector3D.cpp

tests/CMakeFiles/unit_tests.dir/test_vector3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/test_vector3D.cpp.i"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_vector3D.cpp > CMakeFiles/unit_tests.dir/test_vector3D.cpp.i

tests/CMakeFiles/unit_tests.dir/test_vector3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/test_vector3D.cpp.s"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_vector3D.cpp -o CMakeFiles/unit_tests.dir/test_vector3D.cpp.s

tests/CMakeFiles/unit_tests.dir/test_solid.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/test_solid.cpp.o: ../tests/test_solid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/unit_tests.dir/test_solid.cpp.o"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/test_solid.cpp.o -c /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_solid.cpp

tests/CMakeFiles/unit_tests.dir/test_solid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/test_solid.cpp.i"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_solid.cpp > CMakeFiles/unit_tests.dir/test_solid.cpp.i

tests/CMakeFiles/unit_tests.dir/test_solid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/test_solid.cpp.s"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_solid.cpp -o CMakeFiles/unit_tests.dir/test_solid.cpp.s

tests/CMakeFiles/unit_tests.dir/test_cuboid.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/test_cuboid.cpp.o: ../tests/test_cuboid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object tests/CMakeFiles/unit_tests.dir/test_cuboid.cpp.o"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/test_cuboid.cpp.o -c /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_cuboid.cpp

tests/CMakeFiles/unit_tests.dir/test_cuboid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/test_cuboid.cpp.i"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_cuboid.cpp > CMakeFiles/unit_tests.dir/test_cuboid.cpp.i

tests/CMakeFiles/unit_tests.dir/test_cuboid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/test_cuboid.cpp.s"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_cuboid.cpp -o CMakeFiles/unit_tests.dir/test_cuboid.cpp.s

tests/CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.o: ../tests/test_hexagonal_prism.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object tests/CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.o"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.o -c /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_hexagonal_prism.cpp

tests/CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.i"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_hexagonal_prism.cpp > CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.i

tests/CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.s"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_hexagonal_prism.cpp -o CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.s

tests/CMakeFiles/unit_tests.dir/test_drone.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/test_drone.cpp.o: ../tests/test_drone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object tests/CMakeFiles/unit_tests.dir/test_drone.cpp.o"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/test_drone.cpp.o -c /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_drone.cpp

tests/CMakeFiles/unit_tests.dir/test_drone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/test_drone.cpp.i"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_drone.cpp > CMakeFiles/unit_tests.dir/test_drone.cpp.i

tests/CMakeFiles/unit_tests.dir/test_drone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/test_drone.cpp.s"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antek/Videos/zad5_3-AntoniJeziorski/tests/test_drone.cpp -o CMakeFiles/unit_tests.dir/test_drone.cpp.s

# Object files for target unit_tests
unit_tests_OBJECTS = \
"CMakeFiles/unit_tests.dir/main.cpp.o" \
"CMakeFiles/unit_tests.dir/test_matrix3D.cpp.o" \
"CMakeFiles/unit_tests.dir/test_vector3D.cpp.o" \
"CMakeFiles/unit_tests.dir/test_solid.cpp.o" \
"CMakeFiles/unit_tests.dir/test_cuboid.cpp.o" \
"CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.o" \
"CMakeFiles/unit_tests.dir/test_drone.cpp.o"

# External object files for target unit_tests
unit_tests_EXTERNAL_OBJECTS = \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/example.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/cuboid.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/drone.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/matrix3D.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/solid.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/scene.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/hexagonal_prism.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/scene_object.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/plateau.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/slope.cpp.o" \
"/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles/program.dir/src/mount.cpp.o"

unit_tests: tests/CMakeFiles/unit_tests.dir/main.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/test_matrix3D.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/test_vector3D.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/test_solid.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/test_cuboid.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/test_hexagonal_prism.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/test_drone.cpp.o
unit_tests: CMakeFiles/program.dir/src/example.cpp.o
unit_tests: CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o
unit_tests: CMakeFiles/program.dir/src/cuboid.cpp.o
unit_tests: CMakeFiles/program.dir/src/drone.cpp.o
unit_tests: CMakeFiles/program.dir/src/matrix3D.cpp.o
unit_tests: CMakeFiles/program.dir/src/solid.cpp.o
unit_tests: CMakeFiles/program.dir/src/scene.cpp.o
unit_tests: CMakeFiles/program.dir/src/hexagonal_prism.cpp.o
unit_tests: CMakeFiles/program.dir/src/scene_object.cpp.o
unit_tests: CMakeFiles/program.dir/src/plateau.cpp.o
unit_tests: CMakeFiles/program.dir/src/slope.cpp.o
unit_tests: CMakeFiles/program.dir/src/mount.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/build.make
unit_tests: tests/CMakeFiles/unit_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/antek/Videos/zad5_3-AntoniJeziorski/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../unit_tests"
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/unit_tests.dir/build: unit_tests

.PHONY : tests/CMakeFiles/unit_tests.dir/build

tests/CMakeFiles/unit_tests.dir/clean:
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/unit_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/unit_tests.dir/clean

tests/CMakeFiles/unit_tests.dir/depend:
	cd /home/antek/Videos/zad5_3-AntoniJeziorski/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antek/Videos/zad5_3-AntoniJeziorski /home/antek/Videos/zad5_3-AntoniJeziorski/tests /home/antek/Videos/zad5_3-AntoniJeziorski/build /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests /home/antek/Videos/zad5_3-AntoniJeziorski/build/tests/CMakeFiles/unit_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/unit_tests.dir/depend

