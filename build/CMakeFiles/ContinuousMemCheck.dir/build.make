# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/build

# Utility rule file for ContinuousMemCheck.

# Include the progress variables for this target.
include CMakeFiles/ContinuousMemCheck.dir/progress.make

CMakeFiles/ContinuousMemCheck:
	/usr/local/Cellar/cmake/3.14.1/bin/ctest -D ContinuousMemCheck

ContinuousMemCheck: CMakeFiles/ContinuousMemCheck
ContinuousMemCheck: CMakeFiles/ContinuousMemCheck.dir/build.make

.PHONY : ContinuousMemCheck

# Rule to build all files generated by this target.
CMakeFiles/ContinuousMemCheck.dir/build: ContinuousMemCheck

.PHONY : CMakeFiles/ContinuousMemCheck.dir/build

CMakeFiles/ContinuousMemCheck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ContinuousMemCheck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousMemCheck.dir/clean

CMakeFiles/ContinuousMemCheck.dir/depend:
	cd /Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM /Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM /Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/build /Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/build /Users/chenzhuo/Documents/ZJU/Courses/Grade2b/DBS/DM/build/CMakeFiles/ContinuousMemCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousMemCheck.dir/depend

