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
include CMakeFiles/myObjectLoader.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myObjectLoader.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myObjectLoader.dir/flags.make

CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o: CMakeFiles/myObjectLoader.dir/flags.make
CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o: ../Framework/myObjectLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joaquin/Documents/Universidad/JuegoGrafica/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o -c /home/joaquin/Documents/Universidad/JuegoGrafica/Framework/myObjectLoader.cpp

CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joaquin/Documents/Universidad/JuegoGrafica/Framework/myObjectLoader.cpp > CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.i

CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joaquin/Documents/Universidad/JuegoGrafica/Framework/myObjectLoader.cpp -o CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.s

CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o.requires:

.PHONY : CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o.requires

CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o.provides: CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o.requires
	$(MAKE) -f CMakeFiles/myObjectLoader.dir/build.make CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o.provides.build
.PHONY : CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o.provides

CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o.provides.build: CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o


# Object files for target myObjectLoader
myObjectLoader_OBJECTS = \
"CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o"

# External object files for target myObjectLoader
myObjectLoader_EXTERNAL_OBJECTS =

libmyObjectLoader.so: CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o
libmyObjectLoader.so: CMakeFiles/myObjectLoader.dir/build.make
libmyObjectLoader.so: CMakeFiles/myObjectLoader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joaquin/Documents/Universidad/JuegoGrafica/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmyObjectLoader.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myObjectLoader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myObjectLoader.dir/build: libmyObjectLoader.so

.PHONY : CMakeFiles/myObjectLoader.dir/build

CMakeFiles/myObjectLoader.dir/requires: CMakeFiles/myObjectLoader.dir/Framework/myObjectLoader.cpp.o.requires

.PHONY : CMakeFiles/myObjectLoader.dir/requires

CMakeFiles/myObjectLoader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myObjectLoader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myObjectLoader.dir/clean

CMakeFiles/myObjectLoader.dir/depend:
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joaquin/Documents/Universidad/JuegoGrafica /home/joaquin/Documents/Universidad/JuegoGrafica /home/joaquin/Documents/Universidad/JuegoGrafica/build /home/joaquin/Documents/Universidad/JuegoGrafica/build /home/joaquin/Documents/Universidad/JuegoGrafica/build/CMakeFiles/myObjectLoader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myObjectLoader.dir/depend

