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
CMAKE_COMMAND = C:\Users\rochg\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.5233.144\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\rochg\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.5233.144\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\rochg\dev\C++\CodingMasters

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rochg\dev\C++\CodingMasters\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CodingMasters.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CodingMasters.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CodingMasters.dir/flags.make

CMakeFiles/CodingMasters.dir/main.cpp.obj: CMakeFiles/CodingMasters.dir/flags.make
CMakeFiles/CodingMasters.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rochg\dev\C++\CodingMasters\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CodingMasters.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CodingMasters.dir\main.cpp.obj -c C:\Users\rochg\dev\C++\CodingMasters\main.cpp

CMakeFiles/CodingMasters.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodingMasters.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rochg\dev\C++\CodingMasters\main.cpp > CMakeFiles\CodingMasters.dir\main.cpp.i

CMakeFiles/CodingMasters.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodingMasters.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rochg\dev\C++\CodingMasters\main.cpp -o CMakeFiles\CodingMasters.dir\main.cpp.s

CMakeFiles/CodingMasters.dir/UniqueSequencesCounter.cpp.obj: CMakeFiles/CodingMasters.dir/flags.make
CMakeFiles/CodingMasters.dir/UniqueSequencesCounter.cpp.obj: ../UniqueSequencesCounter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rochg\dev\C++\CodingMasters\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CodingMasters.dir/UniqueSequencesCounter.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CodingMasters.dir\UniqueSequencesCounter.cpp.obj -c C:\Users\rochg\dev\C++\CodingMasters\UniqueSequencesCounter.cpp

CMakeFiles/CodingMasters.dir/UniqueSequencesCounter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodingMasters.dir/UniqueSequencesCounter.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rochg\dev\C++\CodingMasters\UniqueSequencesCounter.cpp > CMakeFiles\CodingMasters.dir\UniqueSequencesCounter.cpp.i

CMakeFiles/CodingMasters.dir/UniqueSequencesCounter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodingMasters.dir/UniqueSequencesCounter.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rochg\dev\C++\CodingMasters\UniqueSequencesCounter.cpp -o CMakeFiles\CodingMasters.dir\UniqueSequencesCounter.cpp.s

# Object files for target CodingMasters
CodingMasters_OBJECTS = \
"CMakeFiles/CodingMasters.dir/main.cpp.obj" \
"CMakeFiles/CodingMasters.dir/UniqueSequencesCounter.cpp.obj"

# External object files for target CodingMasters
CodingMasters_EXTERNAL_OBJECTS =

CodingMasters.exe: CMakeFiles/CodingMasters.dir/main.cpp.obj
CodingMasters.exe: CMakeFiles/CodingMasters.dir/UniqueSequencesCounter.cpp.obj
CodingMasters.exe: CMakeFiles/CodingMasters.dir/build.make
CodingMasters.exe: CMakeFiles/CodingMasters.dir/linklibs.rsp
CodingMasters.exe: CMakeFiles/CodingMasters.dir/objects1.rsp
CodingMasters.exe: CMakeFiles/CodingMasters.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\rochg\dev\C++\CodingMasters\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CodingMasters.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CodingMasters.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CodingMasters.dir/build: CodingMasters.exe

.PHONY : CMakeFiles/CodingMasters.dir/build

CMakeFiles/CodingMasters.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CodingMasters.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CodingMasters.dir/clean

CMakeFiles/CodingMasters.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rochg\dev\C++\CodingMasters C:\Users\rochg\dev\C++\CodingMasters C:\Users\rochg\dev\C++\CodingMasters\cmake-build-debug C:\Users\rochg\dev\C++\CodingMasters\cmake-build-debug C:\Users\rochg\dev\C++\CodingMasters\cmake-build-debug\CMakeFiles\CodingMasters.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CodingMasters.dir/depend
