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
include external/glfw-3.1.2/examples/CMakeFiles/particles.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/examples/CMakeFiles/particles.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/examples/CMakeFiles/particles.dir/flags.make

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/flags.make
external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o: ../external/glfw-3.1.2/examples/particles.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zafiron/JuegoGrafica/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/particles.dir/particles.c.o   -c /home/zafiron/JuegoGrafica/external/glfw-3.1.2/examples/particles.c

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/particles.c.i"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zafiron/JuegoGrafica/external/glfw-3.1.2/examples/particles.c > CMakeFiles/particles.dir/particles.c.i

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/particles.c.s"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zafiron/JuegoGrafica/external/glfw-3.1.2/examples/particles.c -o CMakeFiles/particles.dir/particles.c.s

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o.requires:

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o.requires

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o.provides: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o.requires
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/particles.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o.provides.build
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o.provides

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o.provides.build: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o


external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/flags.make
external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o: ../external/glfw-3.1.2/deps/tinycthread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zafiron/JuegoGrafica/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/particles.dir/__/deps/tinycthread.c.o   -c /home/zafiron/JuegoGrafica/external/glfw-3.1.2/deps/tinycthread.c

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/tinycthread.c.i"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zafiron/JuegoGrafica/external/glfw-3.1.2/deps/tinycthread.c > CMakeFiles/particles.dir/__/deps/tinycthread.c.i

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/tinycthread.c.s"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zafiron/JuegoGrafica/external/glfw-3.1.2/deps/tinycthread.c -o CMakeFiles/particles.dir/__/deps/tinycthread.c.s

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o.requires:

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o.requires

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o.provides: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o.requires
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/particles.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o.provides.build
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o.provides

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o.provides.build: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o


external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/flags.make
external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o: ../external/glfw-3.1.2/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zafiron/JuegoGrafica/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/particles.dir/__/deps/getopt.c.o   -c /home/zafiron/JuegoGrafica/external/glfw-3.1.2/deps/getopt.c

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/particles.dir/__/deps/getopt.c.i"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zafiron/JuegoGrafica/external/glfw-3.1.2/deps/getopt.c > CMakeFiles/particles.dir/__/deps/getopt.c.i

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/particles.dir/__/deps/getopt.c.s"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zafiron/JuegoGrafica/external/glfw-3.1.2/deps/getopt.c -o CMakeFiles/particles.dir/__/deps/getopt.c.s

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o.requires:

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o.requires

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o.provides: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/particles.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o.provides.build
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o.provides

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o.provides.build: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o


# Object files for target particles
particles_OBJECTS = \
"CMakeFiles/particles.dir/particles.c.o" \
"CMakeFiles/particles.dir/__/deps/tinycthread.c.o" \
"CMakeFiles/particles.dir/__/deps/getopt.c.o"

# External object files for target particles
particles_EXTERNAL_OBJECTS =

external/glfw-3.1.2/examples/particles: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o
external/glfw-3.1.2/examples/particles: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o
external/glfw-3.1.2/examples/particles: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o
external/glfw-3.1.2/examples/particles: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/build.make
external/glfw-3.1.2/examples/particles: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/examples/particles: /usr/lib64/librt.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libm.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libX11.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXrandr.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXinerama.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXi.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXxf86vm.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXcursor.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libGL.so
external/glfw-3.1.2/examples/particles: /usr/lib64/librt.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libm.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libX11.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXrandr.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXinerama.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXi.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXxf86vm.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libXcursor.so
external/glfw-3.1.2/examples/particles: /usr/lib64/libGL.so
external/glfw-3.1.2/examples/particles: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zafiron/JuegoGrafica/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable particles"
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/particles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/examples/CMakeFiles/particles.dir/build: external/glfw-3.1.2/examples/particles

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/build

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/requires: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/particles.c.o.requires
external/glfw-3.1.2/examples/CMakeFiles/particles.dir/requires: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/tinycthread.c.o.requires
external/glfw-3.1.2/examples/CMakeFiles/particles.dir/requires: external/glfw-3.1.2/examples/CMakeFiles/particles.dir/__/deps/getopt.c.o.requires

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/requires

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/clean:
	cd /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples && $(CMAKE_COMMAND) -P CMakeFiles/particles.dir/cmake_clean.cmake
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/clean

external/glfw-3.1.2/examples/CMakeFiles/particles.dir/depend:
	cd /home/zafiron/JuegoGrafica/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zafiron/JuegoGrafica /home/zafiron/JuegoGrafica/external/glfw-3.1.2/examples /home/zafiron/JuegoGrafica/cmake-build-debug /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples /home/zafiron/JuegoGrafica/cmake-build-debug/external/glfw-3.1.2/examples/CMakeFiles/particles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/particles.dir/depend

