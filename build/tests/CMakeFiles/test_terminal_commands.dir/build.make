# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/johnmper/Documents/gits/cpp_utilities

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johnmper/Documents/gits/cpp_utilities/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_terminal_commands.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_terminal_commands.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_terminal_commands.dir/flags.make

tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o: tests/CMakeFiles/test_terminal_commands.dir/flags.make
tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o: ../tests/terminal/commands/test_commands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnmper/Documents/gits/cpp_utilities/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o"
	cd /home/johnmper/Documents/gits/cpp_utilities/build/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o -c /home/johnmper/Documents/gits/cpp_utilities/tests/terminal/commands/test_commands.cpp

tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.i"
	cd /home/johnmper/Documents/gits/cpp_utilities/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnmper/Documents/gits/cpp_utilities/tests/terminal/commands/test_commands.cpp > CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.i

tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.s"
	cd /home/johnmper/Documents/gits/cpp_utilities/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnmper/Documents/gits/cpp_utilities/tests/terminal/commands/test_commands.cpp -o CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.s

tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o.requires:

.PHONY : tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o.requires

tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o.provides: tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/test_terminal_commands.dir/build.make tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o.provides.build
.PHONY : tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o.provides

tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o.provides.build: tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o


# Object files for target test_terminal_commands
test_terminal_commands_OBJECTS = \
"CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o"

# External object files for target test_terminal_commands
test_terminal_commands_EXTERNAL_OBJECTS =

tests/test_terminal_commands: tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o
tests/test_terminal_commands: tests/CMakeFiles/test_terminal_commands.dir/build.make
tests/test_terminal_commands: tests/CMakeFiles/test_terminal_commands.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johnmper/Documents/gits/cpp_utilities/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_terminal_commands"
	cd /home/johnmper/Documents/gits/cpp_utilities/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_terminal_commands.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_terminal_commands.dir/build: tests/test_terminal_commands

.PHONY : tests/CMakeFiles/test_terminal_commands.dir/build

tests/CMakeFiles/test_terminal_commands.dir/requires: tests/CMakeFiles/test_terminal_commands.dir/terminal/commands/test_commands.cpp.o.requires

.PHONY : tests/CMakeFiles/test_terminal_commands.dir/requires

tests/CMakeFiles/test_terminal_commands.dir/clean:
	cd /home/johnmper/Documents/gits/cpp_utilities/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_terminal_commands.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_terminal_commands.dir/clean

tests/CMakeFiles/test_terminal_commands.dir/depend:
	cd /home/johnmper/Documents/gits/cpp_utilities/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johnmper/Documents/gits/cpp_utilities /home/johnmper/Documents/gits/cpp_utilities/tests /home/johnmper/Documents/gits/cpp_utilities/build /home/johnmper/Documents/gits/cpp_utilities/build/tests /home/johnmper/Documents/gits/cpp_utilities/build/tests/CMakeFiles/test_terminal_commands.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_terminal_commands.dir/depend

