# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/seokjun/kubig2025

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seokjun/kubig2025

# Include any dependencies generated for this target.
include c_example/part3/CMakeFiles/void.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include c_example/part3/CMakeFiles/void.dir/compiler_depend.make

# Include the progress variables for this target.
include c_example/part3/CMakeFiles/void.dir/progress.make

# Include the compile flags for this target's objects.
include c_example/part3/CMakeFiles/void.dir/flags.make

c_example/part3/CMakeFiles/void.dir/void.c.o: c_example/part3/CMakeFiles/void.dir/flags.make
c_example/part3/CMakeFiles/void.dir/void.c.o: c_example/part3/void.c
c_example/part3/CMakeFiles/void.dir/void.c.o: c_example/part3/CMakeFiles/void.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seokjun/kubig2025/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object c_example/part3/CMakeFiles/void.dir/void.c.o"
	cd /home/seokjun/kubig2025/c_example/part3 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT c_example/part3/CMakeFiles/void.dir/void.c.o -MF CMakeFiles/void.dir/void.c.o.d -o CMakeFiles/void.dir/void.c.o -c /home/seokjun/kubig2025/c_example/part3/void.c

c_example/part3/CMakeFiles/void.dir/void.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/void.dir/void.c.i"
	cd /home/seokjun/kubig2025/c_example/part3 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/seokjun/kubig2025/c_example/part3/void.c > CMakeFiles/void.dir/void.c.i

c_example/part3/CMakeFiles/void.dir/void.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/void.dir/void.c.s"
	cd /home/seokjun/kubig2025/c_example/part3 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/seokjun/kubig2025/c_example/part3/void.c -o CMakeFiles/void.dir/void.c.s

# Object files for target void
void_OBJECTS = \
"CMakeFiles/void.dir/void.c.o"

# External object files for target void
void_EXTERNAL_OBJECTS =

c_example/part3/void: c_example/part3/CMakeFiles/void.dir/void.c.o
c_example/part3/void: c_example/part3/CMakeFiles/void.dir/build.make
c_example/part3/void: c_example/part3/CMakeFiles/void.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seokjun/kubig2025/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable void"
	cd /home/seokjun/kubig2025/c_example/part3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/void.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
c_example/part3/CMakeFiles/void.dir/build: c_example/part3/void
.PHONY : c_example/part3/CMakeFiles/void.dir/build

c_example/part3/CMakeFiles/void.dir/clean:
	cd /home/seokjun/kubig2025/c_example/part3 && $(CMAKE_COMMAND) -P CMakeFiles/void.dir/cmake_clean.cmake
.PHONY : c_example/part3/CMakeFiles/void.dir/clean

c_example/part3/CMakeFiles/void.dir/depend:
	cd /home/seokjun/kubig2025 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seokjun/kubig2025 /home/seokjun/kubig2025/c_example/part3 /home/seokjun/kubig2025 /home/seokjun/kubig2025/c_example/part3 /home/seokjun/kubig2025/c_example/part3/CMakeFiles/void.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : c_example/part3/CMakeFiles/void.dir/depend

