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
CMAKE_COMMAND = /home/bozhidar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/bozhidar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bozhidar/Desktop/Travellers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bozhidar/Desktop/Travellers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Travellers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Travellers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Travellers.dir/flags.make

CMakeFiles/Travellers.dir/main.cpp.o: CMakeFiles/Travellers.dir/flags.make
CMakeFiles/Travellers.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bozhidar/Desktop/Travellers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Travellers.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Travellers.dir/main.cpp.o -c /home/bozhidar/Desktop/Travellers/main.cpp

CMakeFiles/Travellers.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Travellers.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bozhidar/Desktop/Travellers/main.cpp > CMakeFiles/Travellers.dir/main.cpp.i

CMakeFiles/Travellers.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Travellers.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bozhidar/Desktop/Travellers/main.cpp -o CMakeFiles/Travellers.dir/main.cpp.s

CMakeFiles/Travellers.dir/user.cpp.o: CMakeFiles/Travellers.dir/flags.make
CMakeFiles/Travellers.dir/user.cpp.o: ../user.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bozhidar/Desktop/Travellers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Travellers.dir/user.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Travellers.dir/user.cpp.o -c /home/bozhidar/Desktop/Travellers/user.cpp

CMakeFiles/Travellers.dir/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Travellers.dir/user.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bozhidar/Desktop/Travellers/user.cpp > CMakeFiles/Travellers.dir/user.cpp.i

CMakeFiles/Travellers.dir/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Travellers.dir/user.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bozhidar/Desktop/Travellers/user.cpp -o CMakeFiles/Travellers.dir/user.cpp.s

CMakeFiles/Travellers.dir/destination.cpp.o: CMakeFiles/Travellers.dir/flags.make
CMakeFiles/Travellers.dir/destination.cpp.o: ../destination.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bozhidar/Desktop/Travellers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Travellers.dir/destination.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Travellers.dir/destination.cpp.o -c /home/bozhidar/Desktop/Travellers/destination.cpp

CMakeFiles/Travellers.dir/destination.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Travellers.dir/destination.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bozhidar/Desktop/Travellers/destination.cpp > CMakeFiles/Travellers.dir/destination.cpp.i

CMakeFiles/Travellers.dir/destination.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Travellers.dir/destination.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bozhidar/Desktop/Travellers/destination.cpp -o CMakeFiles/Travellers.dir/destination.cpp.s

CMakeFiles/Travellers.dir/date.cpp.o: CMakeFiles/Travellers.dir/flags.make
CMakeFiles/Travellers.dir/date.cpp.o: ../date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bozhidar/Desktop/Travellers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Travellers.dir/date.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Travellers.dir/date.cpp.o -c /home/bozhidar/Desktop/Travellers/date.cpp

CMakeFiles/Travellers.dir/date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Travellers.dir/date.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bozhidar/Desktop/Travellers/date.cpp > CMakeFiles/Travellers.dir/date.cpp.i

CMakeFiles/Travellers.dir/date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Travellers.dir/date.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bozhidar/Desktop/Travellers/date.cpp -o CMakeFiles/Travellers.dir/date.cpp.s

# Object files for target Travellers
Travellers_OBJECTS = \
"CMakeFiles/Travellers.dir/main.cpp.o" \
"CMakeFiles/Travellers.dir/user.cpp.o" \
"CMakeFiles/Travellers.dir/destination.cpp.o" \
"CMakeFiles/Travellers.dir/date.cpp.o"

# External object files for target Travellers
Travellers_EXTERNAL_OBJECTS =

Travellers: CMakeFiles/Travellers.dir/main.cpp.o
Travellers: CMakeFiles/Travellers.dir/user.cpp.o
Travellers: CMakeFiles/Travellers.dir/destination.cpp.o
Travellers: CMakeFiles/Travellers.dir/date.cpp.o
Travellers: CMakeFiles/Travellers.dir/build.make
Travellers: CMakeFiles/Travellers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bozhidar/Desktop/Travellers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Travellers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Travellers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Travellers.dir/build: Travellers

.PHONY : CMakeFiles/Travellers.dir/build

CMakeFiles/Travellers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Travellers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Travellers.dir/clean

CMakeFiles/Travellers.dir/depend:
	cd /home/bozhidar/Desktop/Travellers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bozhidar/Desktop/Travellers /home/bozhidar/Desktop/Travellers /home/bozhidar/Desktop/Travellers/cmake-build-debug /home/bozhidar/Desktop/Travellers/cmake-build-debug /home/bozhidar/Desktop/Travellers/cmake-build-debug/CMakeFiles/Travellers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Travellers.dir/depend

