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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zafiron/JuegoGrafica

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zafiron/JuegoGrafica/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/myTexture.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myTexture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myTexture.dir/flags.make

CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o: CMakeFiles/myTexture.dir/flags.make
CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o: ../Framework/myTexture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zafiron/JuegoGrafica/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o -c /home/zafiron/JuegoGrafica/Framework/myTexture.cpp

CMakeFiles/myTexture.dir/Framework/myTexture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myTexture.dir/Framework/myTexture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zafiron/JuegoGrafica/Framework/myTexture.cpp > CMakeFiles/myTexture.dir/Framework/myTexture.cpp.i

CMakeFiles/myTexture.dir/Framework/myTexture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myTexture.dir/Framework/myTexture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zafiron/JuegoGrafica/Framework/myTexture.cpp -o CMakeFiles/myTexture.dir/Framework/myTexture.cpp.s

CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o.requires:

.PHONY : CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o.requires

CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o.provides: CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o.requires
	$(MAKE) -f CMakeFiles/myTexture.dir/build.make CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o.provides.build
.PHONY : CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o.provides

CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o.provides.build: CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o


# Object files for target myTexture
myTexture_OBJECTS = \
"CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o"

# External object files for target myTexture
myTexture_EXTERNAL_OBJECTS =

libmyTexture.so: CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o
libmyTexture.so: CMakeFiles/myTexture.dir/build.make
libmyTexture.so: CMakeFiles/myTexture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zafiron/JuegoGrafica/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmyTexture.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myTexture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myTexture.dir/build: libmyTexture.so

.PHONY : CMakeFiles/myTexture.dir/build

CMakeFiles/myTexture.dir/requires: CMakeFiles/myTexture.dir/Framework/myTexture.cpp.o.requires

.PHONY : CMakeFiles/myTexture.dir/requires

CMakeFiles/myTexture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myTexture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myTexture.dir/clean

CMakeFiles/myTexture.dir/depend:
	cd /home/zafiron/JuegoGrafica/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zafiron/JuegoGrafica /home/zafiron/JuegoGrafica /home/zafiron/JuegoGrafica/cmake-build-debug /home/zafiron/JuegoGrafica/cmake-build-debug /home/zafiron/JuegoGrafica/cmake-build-debug/CMakeFiles/myTexture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myTexture.dir/depend
