# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /snap/clion/209/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/209/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daniil/CLionProjects/os_lab_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniil/CLionProjects/os_lab_4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MeMager.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MeMager.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MeMager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MeMager.dir/flags.make

CMakeFiles/MeMager.dir/main.c.o: CMakeFiles/MeMager.dir/flags.make
CMakeFiles/MeMager.dir/main.c.o: ../main.c
CMakeFiles/MeMager.dir/main.c.o: CMakeFiles/MeMager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniil/CLionProjects/os_lab_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MeMager.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MeMager.dir/main.c.o -MF CMakeFiles/MeMager.dir/main.c.o.d -o CMakeFiles/MeMager.dir/main.c.o -c /home/daniil/CLionProjects/os_lab_4/main.c

CMakeFiles/MeMager.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MeMager.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daniil/CLionProjects/os_lab_4/main.c > CMakeFiles/MeMager.dir/main.c.i

CMakeFiles/MeMager.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MeMager.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daniil/CLionProjects/os_lab_4/main.c -o CMakeFiles/MeMager.dir/main.c.s

CMakeFiles/MeMager.dir/memager.c.o: CMakeFiles/MeMager.dir/flags.make
CMakeFiles/MeMager.dir/memager.c.o: ../memager.c
CMakeFiles/MeMager.dir/memager.c.o: CMakeFiles/MeMager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniil/CLionProjects/os_lab_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MeMager.dir/memager.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MeMager.dir/memager.c.o -MF CMakeFiles/MeMager.dir/memager.c.o.d -o CMakeFiles/MeMager.dir/memager.c.o -c /home/daniil/CLionProjects/os_lab_4/memager.c

CMakeFiles/MeMager.dir/memager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MeMager.dir/memager.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daniil/CLionProjects/os_lab_4/memager.c > CMakeFiles/MeMager.dir/memager.c.i

CMakeFiles/MeMager.dir/memager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MeMager.dir/memager.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daniil/CLionProjects/os_lab_4/memager.c -o CMakeFiles/MeMager.dir/memager.c.s

CMakeFiles/MeMager.dir/memager_tester.c.o: CMakeFiles/MeMager.dir/flags.make
CMakeFiles/MeMager.dir/memager_tester.c.o: ../memager_tester.c
CMakeFiles/MeMager.dir/memager_tester.c.o: CMakeFiles/MeMager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniil/CLionProjects/os_lab_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MeMager.dir/memager_tester.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MeMager.dir/memager_tester.c.o -MF CMakeFiles/MeMager.dir/memager_tester.c.o.d -o CMakeFiles/MeMager.dir/memager_tester.c.o -c /home/daniil/CLionProjects/os_lab_4/memager_tester.c

CMakeFiles/MeMager.dir/memager_tester.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MeMager.dir/memager_tester.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daniil/CLionProjects/os_lab_4/memager_tester.c > CMakeFiles/MeMager.dir/memager_tester.c.i

CMakeFiles/MeMager.dir/memager_tester.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MeMager.dir/memager_tester.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daniil/CLionProjects/os_lab_4/memager_tester.c -o CMakeFiles/MeMager.dir/memager_tester.c.s

CMakeFiles/MeMager.dir/benchmark.c.o: CMakeFiles/MeMager.dir/flags.make
CMakeFiles/MeMager.dir/benchmark.c.o: ../benchmark.c
CMakeFiles/MeMager.dir/benchmark.c.o: CMakeFiles/MeMager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniil/CLionProjects/os_lab_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MeMager.dir/benchmark.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MeMager.dir/benchmark.c.o -MF CMakeFiles/MeMager.dir/benchmark.c.o.d -o CMakeFiles/MeMager.dir/benchmark.c.o -c /home/daniil/CLionProjects/os_lab_4/benchmark.c

CMakeFiles/MeMager.dir/benchmark.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MeMager.dir/benchmark.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daniil/CLionProjects/os_lab_4/benchmark.c > CMakeFiles/MeMager.dir/benchmark.c.i

CMakeFiles/MeMager.dir/benchmark.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MeMager.dir/benchmark.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daniil/CLionProjects/os_lab_4/benchmark.c -o CMakeFiles/MeMager.dir/benchmark.c.s

# Object files for target MeMager
MeMager_OBJECTS = \
"CMakeFiles/MeMager.dir/main.c.o" \
"CMakeFiles/MeMager.dir/memager.c.o" \
"CMakeFiles/MeMager.dir/memager_tester.c.o" \
"CMakeFiles/MeMager.dir/benchmark.c.o"

# External object files for target MeMager
MeMager_EXTERNAL_OBJECTS =

MeMager: CMakeFiles/MeMager.dir/main.c.o
MeMager: CMakeFiles/MeMager.dir/memager.c.o
MeMager: CMakeFiles/MeMager.dir/memager_tester.c.o
MeMager: CMakeFiles/MeMager.dir/benchmark.c.o
MeMager: CMakeFiles/MeMager.dir/build.make
MeMager: CMakeFiles/MeMager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daniil/CLionProjects/os_lab_4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable MeMager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MeMager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MeMager.dir/build: MeMager
.PHONY : CMakeFiles/MeMager.dir/build

CMakeFiles/MeMager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MeMager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MeMager.dir/clean

CMakeFiles/MeMager.dir/depend:
	cd /home/daniil/CLionProjects/os_lab_4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniil/CLionProjects/os_lab_4 /home/daniil/CLionProjects/os_lab_4 /home/daniil/CLionProjects/os_lab_4/cmake-build-debug /home/daniil/CLionProjects/os_lab_4/cmake-build-debug /home/daniil/CLionProjects/os_lab_4/cmake-build-debug/CMakeFiles/MeMager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MeMager.dir/depend

