# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "/Volumes/Sandisk Extreme SSD Media/Apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Volumes/Sandisk Extreme SSD Media/Apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/hw8_2020.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw8_2020.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw8_2020.dir/flags.make

CMakeFiles/hw8_2020.dir/testPolynomial.cpp.o: CMakeFiles/hw8_2020.dir/flags.make
CMakeFiles/hw8_2020.dir/testPolynomial.cpp.o: ../testPolynomial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw8_2020.dir/testPolynomial.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw8_2020.dir/testPolynomial.cpp.o -c "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/testPolynomial.cpp"

CMakeFiles/hw8_2020.dir/testPolynomial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw8_2020.dir/testPolynomial.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/testPolynomial.cpp" > CMakeFiles/hw8_2020.dir/testPolynomial.cpp.i

CMakeFiles/hw8_2020.dir/testPolynomial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw8_2020.dir/testPolynomial.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/testPolynomial.cpp" -o CMakeFiles/hw8_2020.dir/testPolynomial.cpp.s

CMakeFiles/hw8_2020.dir/Polynomial.cpp.o: CMakeFiles/hw8_2020.dir/flags.make
CMakeFiles/hw8_2020.dir/Polynomial.cpp.o: ../Polynomial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw8_2020.dir/Polynomial.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw8_2020.dir/Polynomial.cpp.o -c "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/Polynomial.cpp"

CMakeFiles/hw8_2020.dir/Polynomial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw8_2020.dir/Polynomial.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/Polynomial.cpp" > CMakeFiles/hw8_2020.dir/Polynomial.cpp.i

CMakeFiles/hw8_2020.dir/Polynomial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw8_2020.dir/Polynomial.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/Polynomial.cpp" -o CMakeFiles/hw8_2020.dir/Polynomial.cpp.s

# Object files for target hw8_2020
hw8_2020_OBJECTS = \
"CMakeFiles/hw8_2020.dir/testPolynomial.cpp.o" \
"CMakeFiles/hw8_2020.dir/Polynomial.cpp.o"

# External object files for target hw8_2020
hw8_2020_EXTERNAL_OBJECTS =

hw8_2020: CMakeFiles/hw8_2020.dir/testPolynomial.cpp.o
hw8_2020: CMakeFiles/hw8_2020.dir/Polynomial.cpp.o
hw8_2020: CMakeFiles/hw8_2020.dir/build.make
hw8_2020: CMakeFiles/hw8_2020.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable hw8_2020"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw8_2020.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw8_2020.dir/build: hw8_2020

.PHONY : CMakeFiles/hw8_2020.dir/build

CMakeFiles/hw8_2020.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw8_2020.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw8_2020.dir/clean

CMakeFiles/hw8_2020.dir/depend:
	cd "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/hw8_2020/cmake-build-debug/CMakeFiles/hw8_2020.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/hw8_2020.dir/depend

