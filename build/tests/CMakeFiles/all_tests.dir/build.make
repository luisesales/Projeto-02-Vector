# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/all_tests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/all_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/all_tests.dir/flags.make

tests/CMakeFiles/all_tests.dir/main.cpp.o: tests/CMakeFiles/all_tests.dir/flags.make
tests/CMakeFiles/all_tests.dir/main.cpp.o: /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source/tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/all_tests.dir/main.cpp.o"
	cd /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/all_tests.dir/main.cpp.o -c /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source/tests/main.cpp

tests/CMakeFiles/all_tests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/all_tests.dir/main.cpp.i"
	cd /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source/tests/main.cpp > CMakeFiles/all_tests.dir/main.cpp.i

tests/CMakeFiles/all_tests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/all_tests.dir/main.cpp.s"
	cd /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source/tests/main.cpp -o CMakeFiles/all_tests.dir/main.cpp.s

tests/CMakeFiles/all_tests.dir/main.cpp.o.requires:

.PHONY : tests/CMakeFiles/all_tests.dir/main.cpp.o.requires

tests/CMakeFiles/all_tests.dir/main.cpp.o.provides: tests/CMakeFiles/all_tests.dir/main.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/all_tests.dir/build.make tests/CMakeFiles/all_tests.dir/main.cpp.o.provides.build
.PHONY : tests/CMakeFiles/all_tests.dir/main.cpp.o.provides

tests/CMakeFiles/all_tests.dir/main.cpp.o.provides.build: tests/CMakeFiles/all_tests.dir/main.cpp.o


tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o: tests/CMakeFiles/all_tests.dir/flags.make
tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o: /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source/tests/iterator_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o"
	cd /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/all_tests.dir/iterator_tests.cpp.o -c /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source/tests/iterator_tests.cpp

tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/all_tests.dir/iterator_tests.cpp.i"
	cd /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source/tests/iterator_tests.cpp > CMakeFiles/all_tests.dir/iterator_tests.cpp.i

tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/all_tests.dir/iterator_tests.cpp.s"
	cd /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source/tests/iterator_tests.cpp -o CMakeFiles/all_tests.dir/iterator_tests.cpp.s

tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o.requires:

.PHONY : tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o.requires

tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o.provides: tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/all_tests.dir/build.make tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o.provides.build
.PHONY : tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o.provides

tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o.provides.build: tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o


# Object files for target all_tests
all_tests_OBJECTS = \
"CMakeFiles/all_tests.dir/main.cpp.o" \
"CMakeFiles/all_tests.dir/iterator_tests.cpp.o"

# External object files for target all_tests
all_tests_EXTERNAL_OBJECTS =

tests/all_tests: tests/CMakeFiles/all_tests.dir/main.cpp.o
tests/all_tests: tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o
tests/all_tests: tests/CMakeFiles/all_tests.dir/build.make
tests/all_tests: tests/libTM.a
tests/all_tests: tests/CMakeFiles/all_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable all_tests"
	cd /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/all_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/all_tests.dir/build: tests/all_tests

.PHONY : tests/CMakeFiles/all_tests.dir/build

tests/CMakeFiles/all_tests.dir/requires: tests/CMakeFiles/all_tests.dir/main.cpp.o.requires
tests/CMakeFiles/all_tests.dir/requires: tests/CMakeFiles/all_tests.dir/iterator_tests.cpp.o.requires

.PHONY : tests/CMakeFiles/all_tests.dir/requires

tests/CMakeFiles/all_tests.dir/clean:
	cd /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/all_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/all_tests.dir/clean

tests/CMakeFiles/all_tests.dir/depend:
	cd /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/source/tests /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests /home/luis/Documentos/Programas/LP1/vector/T02-vector-individual-luisesales/build/tests/CMakeFiles/all_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/all_tests.dir/depend

