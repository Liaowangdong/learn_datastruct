# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\CLion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Project\learn_datastruct

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Project\learn_datastruct\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/learn_datastruct.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learn_datastruct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learn_datastruct.dir/flags.make

CMakeFiles/learn_datastruct.dir/main.cpp.obj: CMakeFiles/learn_datastruct.dir/flags.make
CMakeFiles/learn_datastruct.dir/main.cpp.obj: CMakeFiles/learn_datastruct.dir/includes_CXX.rsp
CMakeFiles/learn_datastruct.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\learn_datastruct\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/learn_datastruct.dir/main.cpp.obj"
	D:\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\learn_datastruct.dir\main.cpp.obj -c D:\Project\learn_datastruct\main.cpp

CMakeFiles/learn_datastruct.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn_datastruct.dir/main.cpp.i"
	D:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\learn_datastruct\main.cpp > CMakeFiles\learn_datastruct.dir\main.cpp.i

CMakeFiles/learn_datastruct.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn_datastruct.dir/main.cpp.s"
	D:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\learn_datastruct\main.cpp -o CMakeFiles\learn_datastruct.dir\main.cpp.s

# Object files for target learn_datastruct
learn_datastruct_OBJECTS = \
"CMakeFiles/learn_datastruct.dir/main.cpp.obj"

# External object files for target learn_datastruct
learn_datastruct_EXTERNAL_OBJECTS =

learn_datastruct.exe: CMakeFiles/learn_datastruct.dir/main.cpp.obj
learn_datastruct.exe: CMakeFiles/learn_datastruct.dir/build.make
learn_datastruct.exe: CMakeFiles/learn_datastruct.dir/linklibs.rsp
learn_datastruct.exe: CMakeFiles/learn_datastruct.dir/objects1.rsp
learn_datastruct.exe: CMakeFiles/learn_datastruct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Project\learn_datastruct\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable learn_datastruct.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\learn_datastruct.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learn_datastruct.dir/build: learn_datastruct.exe

.PHONY : CMakeFiles/learn_datastruct.dir/build

CMakeFiles/learn_datastruct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\learn_datastruct.dir\cmake_clean.cmake
.PHONY : CMakeFiles/learn_datastruct.dir/clean

CMakeFiles/learn_datastruct.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Project\learn_datastruct D:\Project\learn_datastruct D:\Project\learn_datastruct\cmake-build-debug D:\Project\learn_datastruct\cmake-build-debug D:\Project\learn_datastruct\cmake-build-debug\CMakeFiles\learn_datastruct.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learn_datastruct.dir/depend

