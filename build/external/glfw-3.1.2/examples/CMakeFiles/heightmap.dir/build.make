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
include external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/flags.make

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/flags.make
external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o: ../external/glfw-3.1.2/examples/heightmap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joaquin/Documents/Universidad/JuegoGrafica/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o"
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/heightmap.dir/heightmap.c.o   -c /home/joaquin/Documents/Universidad/JuegoGrafica/external/glfw-3.1.2/examples/heightmap.c

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heightmap.dir/heightmap.c.i"
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joaquin/Documents/Universidad/JuegoGrafica/external/glfw-3.1.2/examples/heightmap.c > CMakeFiles/heightmap.dir/heightmap.c.i

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heightmap.dir/heightmap.c.s"
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joaquin/Documents/Universidad/JuegoGrafica/external/glfw-3.1.2/examples/heightmap.c -o CMakeFiles/heightmap.dir/heightmap.c.s

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o.requires:

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o.requires

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o.provides: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o.requires
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o.provides.build
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o.provides

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o.provides.build: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o


external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/flags.make
external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o: ../external/glfw-3.1.2/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joaquin/Documents/Universidad/JuegoGrafica/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o"
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/heightmap.dir/__/deps/glad.c.o   -c /home/joaquin/Documents/Universidad/JuegoGrafica/external/glfw-3.1.2/deps/glad.c

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heightmap.dir/__/deps/glad.c.i"
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joaquin/Documents/Universidad/JuegoGrafica/external/glfw-3.1.2/deps/glad.c > CMakeFiles/heightmap.dir/__/deps/glad.c.i

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heightmap.dir/__/deps/glad.c.s"
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joaquin/Documents/Universidad/JuegoGrafica/external/glfw-3.1.2/deps/glad.c -o CMakeFiles/heightmap.dir/__/deps/glad.c.s

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o.requires:

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o.requires

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o.provides: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o.requires
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o.provides.build
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o.provides

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o.provides.build: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o


# Object files for target heightmap
heightmap_OBJECTS = \
"CMakeFiles/heightmap.dir/heightmap.c.o" \
"CMakeFiles/heightmap.dir/__/deps/glad.c.o"

# External object files for target heightmap
heightmap_EXTERNAL_OBJECTS =

external/glfw-3.1.2/examples/heightmap: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o
external/glfw-3.1.2/examples/heightmap: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o
external/glfw-3.1.2/examples/heightmap: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/build.make
external/glfw-3.1.2/examples/heightmap: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/examples/heightmap: /usr/lib64/librt.so
external/glfw-3.1.2/examples/heightmap: /usr/lib64/libm.so
external/glfw-3.1.2/examples/heightmap: /usr/lib64/libX11.so
external/glfw-3.1.2/examples/heightmap: /usr/lib64/libXrandr.so
external/glfw-3.1.2/examples/heightmap: /usr/lib64/libXinerama.so
external/glfw-3.1.2/examples/heightmap: /usr/lib64/libXi.so
external/glfw-3.1.2/examples/heightmap: /usr/lib64/libXxf86vm.so
external/glfw-3.1.2/examples/heightmap: /usr/lib64/libXcursor.so
external/glfw-3.1.2/examples/heightmap: /usr/lib64/libGL.so
external/glfw-3.1.2/examples/heightmap: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joaquin/Documents/Universidad/JuegoGrafica/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable heightmap"
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heightmap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/build: external/glfw-3.1.2/examples/heightmap

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/build

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/requires: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o.requires
external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/requires: external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/__/deps/glad.c.o.requires

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/requires

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/clean:
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples && $(CMAKE_COMMAND) -P CMakeFiles/heightmap.dir/cmake_clean.cmake
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/clean

external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/depend:
	cd /home/joaquin/Documents/Universidad/JuegoGrafica/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joaquin/Documents/Universidad/JuegoGrafica /home/joaquin/Documents/Universidad/JuegoGrafica/external/glfw-3.1.2/examples /home/joaquin/Documents/Universidad/JuegoGrafica/build /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples /home/joaquin/Documents/Universidad/JuegoGrafica/build/external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/depend

