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
CMAKE_SOURCE_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/rec07_2020.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rec07_2020.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rec07_2020.dir/flags.make

CMakeFiles/rec07_2020.dir/rec07_2020.cpp.o: CMakeFiles/rec07_2020.dir/flags.make
CMakeFiles/rec07_2020.dir/rec07_2020.cpp.o: ../rec07_2020.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rec07_2020.dir/rec07_2020.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rec07_2020.dir/rec07_2020.cpp.o -c "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/rec07_2020.cpp"

CMakeFiles/rec07_2020.dir/rec07_2020.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rec07_2020.dir/rec07_2020.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/rec07_2020.cpp" > CMakeFiles/rec07_2020.dir/rec07_2020.cpp.i

CMakeFiles/rec07_2020.dir/rec07_2020.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rec07_2020.dir/rec07_2020.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/rec07_2020.cpp" -o CMakeFiles/rec07_2020.dir/rec07_2020.cpp.s

# Object files for target rec07_2020
rec07_2020_OBJECTS = \
"CMakeFiles/rec07_2020.dir/rec07_2020.cpp.o"

# External object files for target rec07_2020
rec07_2020_EXTERNAL_OBJECTS =

rec07_2020: CMakeFiles/rec07_2020.dir/rec07_2020.cpp.o
rec07_2020: CMakeFiles/rec07_2020.dir/build.make
rec07_2020: CMakeFiles/rec07_2020.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rec07_2020"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rec07_2020.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rec07_2020.dir/build: rec07_2020

.PHONY : CMakeFiles/rec07_2020.dir/build

CMakeFiles/rec07_2020.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rec07_2020.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rec07_2020.dir/clean

CMakeFiles/rec07_2020.dir/depend:
	cd "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/rec07_2020/cmake-build-debug/CMakeFiles/rec07_2020.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/rec07_2020.dir/depend

