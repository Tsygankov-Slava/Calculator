# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tv/Desktop/Calc/Calc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tv/Desktop/Calc/Calc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Calc.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Calc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Calc.dir/flags.make

CMakeFiles/Calc.dir/src/main.cpp.o: CMakeFiles/Calc.dir/flags.make
CMakeFiles/Calc.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tv/Desktop/Calc/Calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Calc.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Calc.dir/src/main.cpp.o -c /Users/tv/Desktop/Calc/Calc/src/main.cpp

CMakeFiles/Calc.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calc.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tv/Desktop/Calc/Calc/src/main.cpp > CMakeFiles/Calc.dir/src/main.cpp.i

CMakeFiles/Calc.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calc.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tv/Desktop/Calc/Calc/src/main.cpp -o CMakeFiles/Calc.dir/src/main.cpp.s

CMakeFiles/Calc.dir/src/File/File.cpp.o: CMakeFiles/Calc.dir/flags.make
CMakeFiles/Calc.dir/src/File/File.cpp.o: ../src/File/File.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tv/Desktop/Calc/Calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Calc.dir/src/File/File.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Calc.dir/src/File/File.cpp.o -c /Users/tv/Desktop/Calc/Calc/src/File/File.cpp

CMakeFiles/Calc.dir/src/File/File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calc.dir/src/File/File.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tv/Desktop/Calc/Calc/src/File/File.cpp > CMakeFiles/Calc.dir/src/File/File.cpp.i

CMakeFiles/Calc.dir/src/File/File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calc.dir/src/File/File.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tv/Desktop/Calc/Calc/src/File/File.cpp -o CMakeFiles/Calc.dir/src/File/File.cpp.s

CMakeFiles/Calc.dir/src/Variables/Variables.cpp.o: CMakeFiles/Calc.dir/flags.make
CMakeFiles/Calc.dir/src/Variables/Variables.cpp.o: ../src/Variables/Variables.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tv/Desktop/Calc/Calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Calc.dir/src/Variables/Variables.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Calc.dir/src/Variables/Variables.cpp.o -c /Users/tv/Desktop/Calc/Calc/src/Variables/Variables.cpp

CMakeFiles/Calc.dir/src/Variables/Variables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calc.dir/src/Variables/Variables.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tv/Desktop/Calc/Calc/src/Variables/Variables.cpp > CMakeFiles/Calc.dir/src/Variables/Variables.cpp.i

CMakeFiles/Calc.dir/src/Variables/Variables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calc.dir/src/Variables/Variables.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tv/Desktop/Calc/Calc/src/Variables/Variables.cpp -o CMakeFiles/Calc.dir/src/Variables/Variables.cpp.s

CMakeFiles/Calc.dir/src/Token/Token.cpp.o: CMakeFiles/Calc.dir/flags.make
CMakeFiles/Calc.dir/src/Token/Token.cpp.o: ../src/Token/Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tv/Desktop/Calc/Calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Calc.dir/src/Token/Token.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Calc.dir/src/Token/Token.cpp.o -c /Users/tv/Desktop/Calc/Calc/src/Token/Token.cpp

CMakeFiles/Calc.dir/src/Token/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calc.dir/src/Token/Token.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tv/Desktop/Calc/Calc/src/Token/Token.cpp > CMakeFiles/Calc.dir/src/Token/Token.cpp.i

CMakeFiles/Calc.dir/src/Token/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calc.dir/src/Token/Token.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tv/Desktop/Calc/Calc/src/Token/Token.cpp -o CMakeFiles/Calc.dir/src/Token/Token.cpp.s

CMakeFiles/Calc.dir/src/RPN/RPN.cpp.o: CMakeFiles/Calc.dir/flags.make
CMakeFiles/Calc.dir/src/RPN/RPN.cpp.o: ../src/RPN/RPN.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tv/Desktop/Calc/Calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Calc.dir/src/RPN/RPN.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Calc.dir/src/RPN/RPN.cpp.o -c /Users/tv/Desktop/Calc/Calc/src/RPN/RPN.cpp

CMakeFiles/Calc.dir/src/RPN/RPN.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calc.dir/src/RPN/RPN.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tv/Desktop/Calc/Calc/src/RPN/RPN.cpp > CMakeFiles/Calc.dir/src/RPN/RPN.cpp.i

CMakeFiles/Calc.dir/src/RPN/RPN.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calc.dir/src/RPN/RPN.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tv/Desktop/Calc/Calc/src/RPN/RPN.cpp -o CMakeFiles/Calc.dir/src/RPN/RPN.cpp.s

# Object files for target Calc
Calc_OBJECTS = \
"CMakeFiles/Calc.dir/src/main.cpp.o" \
"CMakeFiles/Calc.dir/src/File/File.cpp.o" \
"CMakeFiles/Calc.dir/src/Variables/Variables.cpp.o" \
"CMakeFiles/Calc.dir/src/Token/Token.cpp.o" \
"CMakeFiles/Calc.dir/src/RPN/RPN.cpp.o"

# External object files for target Calc
Calc_EXTERNAL_OBJECTS =

Calc: CMakeFiles/Calc.dir/src/main.cpp.o
Calc: CMakeFiles/Calc.dir/src/File/File.cpp.o
Calc: CMakeFiles/Calc.dir/src/Variables/Variables.cpp.o
Calc: CMakeFiles/Calc.dir/src/Token/Token.cpp.o
Calc: CMakeFiles/Calc.dir/src/RPN/RPN.cpp.o
Calc: CMakeFiles/Calc.dir/build.make
Calc: CMakeFiles/Calc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tv/Desktop/Calc/Calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Calc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Calc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Calc.dir/build: Calc
.PHONY : CMakeFiles/Calc.dir/build

CMakeFiles/Calc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Calc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Calc.dir/clean

CMakeFiles/Calc.dir/depend:
	cd /Users/tv/Desktop/Calc/Calc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tv/Desktop/Calc/Calc /Users/tv/Desktop/Calc/Calc /Users/tv/Desktop/Calc/Calc/cmake-build-debug /Users/tv/Desktop/Calc/Calc/cmake-build-debug /Users/tv/Desktop/Calc/Calc/cmake-build-debug/CMakeFiles/Calc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Calc.dir/depend
