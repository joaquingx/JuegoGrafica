# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/joaquin/Documents/Universidad/JuegoGrafica

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joaquin/Documents/Universidad/JuegoGrafica/build

# Include any dependencies generated for this target.
include CMakeFiles/myArt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myArt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myArt.dir/flags.make

CMakeFiles/myArt.dir/Framework/myArt.cpp.o: CMakeFiles/myArt.dir/flags.make
CMakeFiles/myArt.dir/Framework/myArt.cpp.o: ../Framework/myArt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joaquin/Documents/Universidad/JuegoGrafica/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myArt.dir/Framework/myArt.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myArt.dir/Framework/myArt.cpp.o -c /home/joaquin/Documents/Universidad/JuegoGrafica/Framework/myArt.cpp

CMakeFiles/myArt.dir/Framework/myArt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myArt.dir/Framework/myArt.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joaquin/Documents/Universidad/JuegoGrafica/Framework/myArt.cpp > CMakeFiles/myArt.dir/Framework/myArt.cpp.i

CMakeFiles/myArt.dir/Framework/myArt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myArt.dir/Framework/myArt.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joaquin/Documents/Universidad/JuegoGrafica/Framework/myArt.cpp -o CMakeFiles/myArt.dir/Framework/myArt.cpp.s

CMakeFiles/myArt.dir/Framework/myArt.cpp.o.requires:

.PHONY : CMakeFiles/myArt.dir/Framework/myArt.cpp.o.requires

CMakeFiles/myArt.dir/Framework/myArt.cpp.o.provides: CMakeFiles/myArt.dir/Framework/myArt.cpp.o.requires
	$(MAKE) -f CMakeFiles/myArt.dir/build.make CMakeFiles/myArt.dir/Framework/myArt.cpp.o.provides.build
.PHONY : CMakeFiles/myArt.dir/Framework/myArt.cpp.o.provides

CMakeFiles/myArt.dir/Framework/myArt.cpp.o.provides.build: CMakeFiles/myArt.dir/Framework/myArt.cpp.o


# Object files for target myArt
myArt_OBJECTS = \
"CMakeFiles/myArt.dir/Framework/myArt.cpp.o"

# External object files for target myArt
myArt_EXTERNAL_OBJECTS =

libmyArt.so: CMakeFiles/myArt.dir/Framework/myArt.cpp.o
libmyArt.so: CMakeFiles/myArt.dir/build.make
libmyArt.so: CMakeFiles/myArt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joaquin/Documents/Universidad/JuegoGrafica/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmyArt.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myArt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myArt.dir/build: libmyArt.so

.PHONY : CMakeFiles/myArt.dir/build

CMakeFiles/myArt.dir/requires: CMakeFiles/myArt.dir/Framework/myArt.cpp.o.requires

.PHONY : CMakeFiles/myArt.dir/requires

CMakeFiles/myArt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myArt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myArt.dir/clean

CMakeFiles/myArt.dir/depend:
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joaquin/Documents/Universidad/JuegoGrafica /home/joaquin/Documents/Universidad/JuegoGrafica /home/joaquin/Documents/Universidad/JuegoGrafica/build /home/joaquin/Documents/Universidad/JuegoGrafica/build /home/joaquin/Documents/Universidad/JuegoGrafica/build/CMakeFiles/myArt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myArt.dir/depend

