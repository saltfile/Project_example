# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/CLion-2020.2.4/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/CLion-2020.2.4/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/Cpro/ServerLab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/Cpro/ServerLab/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ServerLab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ServerLab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ServerLab.dir/flags.make

CMakeFiles/ServerLab.dir/main.cpp.o: CMakeFiles/ServerLab.dir/flags.make
CMakeFiles/ServerLab.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/Cpro/ServerLab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ServerLab.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerLab.dir/main.cpp.o -c /opt/Cpro/ServerLab/main.cpp

CMakeFiles/ServerLab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerLab.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/Cpro/ServerLab/main.cpp > CMakeFiles/ServerLab.dir/main.cpp.i

CMakeFiles/ServerLab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerLab.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/Cpro/ServerLab/main.cpp -o CMakeFiles/ServerLab.dir/main.cpp.s

CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.o: CMakeFiles/ServerLab.dir/flags.make
CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.o: ../ser_lab/ser_one.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/Cpro/ServerLab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.o -c /opt/Cpro/ServerLab/ser_lab/ser_one.cpp

CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/Cpro/ServerLab/ser_lab/ser_one.cpp > CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.i

CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/Cpro/ServerLab/ser_lab/ser_one.cpp -o CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.s

CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.o: CMakeFiles/ServerLab.dir/flags.make
CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.o: ../lab_byte/fun_bytes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/Cpro/ServerLab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.o -c /opt/Cpro/ServerLab/lab_byte/fun_bytes.cpp

CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/Cpro/ServerLab/lab_byte/fun_bytes.cpp > CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.i

CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/Cpro/ServerLab/lab_byte/fun_bytes.cpp -o CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.s

CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.o: CMakeFiles/ServerLab.dir/flags.make
CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.o: ../lab_crc/crc_lab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/Cpro/ServerLab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.o -c /opt/Cpro/ServerLab/lab_crc/crc_lab.cpp

CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/Cpro/ServerLab/lab_crc/crc_lab.cpp > CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.i

CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/Cpro/ServerLab/lab_crc/crc_lab.cpp -o CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.s

# Object files for target ServerLab
ServerLab_OBJECTS = \
"CMakeFiles/ServerLab.dir/main.cpp.o" \
"CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.o" \
"CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.o" \
"CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.o"

# External object files for target ServerLab
ServerLab_EXTERNAL_OBJECTS =

ServerLab: CMakeFiles/ServerLab.dir/main.cpp.o
ServerLab: CMakeFiles/ServerLab.dir/ser_lab/ser_one.cpp.o
ServerLab: CMakeFiles/ServerLab.dir/lab_byte/fun_bytes.cpp.o
ServerLab: CMakeFiles/ServerLab.dir/lab_crc/crc_lab.cpp.o
ServerLab: CMakeFiles/ServerLab.dir/build.make
ServerLab: CMakeFiles/ServerLab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/Cpro/ServerLab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ServerLab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ServerLab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ServerLab.dir/build: ServerLab

.PHONY : CMakeFiles/ServerLab.dir/build

CMakeFiles/ServerLab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ServerLab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ServerLab.dir/clean

CMakeFiles/ServerLab.dir/depend:
	cd /opt/Cpro/ServerLab/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/Cpro/ServerLab /opt/Cpro/ServerLab /opt/Cpro/ServerLab/cmake-build-debug /opt/Cpro/ServerLab/cmake-build-debug /opt/Cpro/ServerLab/cmake-build-debug/CMakeFiles/ServerLab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ServerLab.dir/depend

