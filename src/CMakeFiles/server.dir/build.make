# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fozua/Desktop/ASIOTesting/asio-testing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fozua/Desktop/ASIOTesting/asio-testing

# Include any dependencies generated for this target.
include src/CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/server.dir/flags.make

src/CMakeFiles/server.dir/connection.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/connection.cpp.o: src/connection.cpp
src/CMakeFiles/server.dir/connection.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/ASIOTesting/asio-testing/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/server.dir/connection.cpp.o"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/connection.cpp.o -MF CMakeFiles/server.dir/connection.cpp.o.d -o CMakeFiles/server.dir/connection.cpp.o -c /Users/fozua/Desktop/ASIOTesting/asio-testing/src/connection.cpp

src/CMakeFiles/server.dir/connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/connection.cpp.i"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/ASIOTesting/asio-testing/src/connection.cpp > CMakeFiles/server.dir/connection.cpp.i

src/CMakeFiles/server.dir/connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/connection.cpp.s"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/ASIOTesting/asio-testing/src/connection.cpp -o CMakeFiles/server.dir/connection.cpp.s

src/CMakeFiles/server.dir/game_room.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/game_room.cpp.o: src/game_room.cpp
src/CMakeFiles/server.dir/game_room.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/ASIOTesting/asio-testing/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/server.dir/game_room.cpp.o"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/game_room.cpp.o -MF CMakeFiles/server.dir/game_room.cpp.o.d -o CMakeFiles/server.dir/game_room.cpp.o -c /Users/fozua/Desktop/ASIOTesting/asio-testing/src/game_room.cpp

src/CMakeFiles/server.dir/game_room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/game_room.cpp.i"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/ASIOTesting/asio-testing/src/game_room.cpp > CMakeFiles/server.dir/game_room.cpp.i

src/CMakeFiles/server.dir/game_room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/game_room.cpp.s"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/ASIOTesting/asio-testing/src/game_room.cpp -o CMakeFiles/server.dir/game_room.cpp.s

src/CMakeFiles/server.dir/server.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/server.cpp.o: src/server.cpp
src/CMakeFiles/server.dir/server.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/ASIOTesting/asio-testing/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/server.dir/server.cpp.o"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/server.cpp.o -MF CMakeFiles/server.dir/server.cpp.o.d -o CMakeFiles/server.dir/server.cpp.o -c /Users/fozua/Desktop/ASIOTesting/asio-testing/src/server.cpp

src/CMakeFiles/server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/server.cpp.i"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/ASIOTesting/asio-testing/src/server.cpp > CMakeFiles/server.dir/server.cpp.i

src/CMakeFiles/server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/server.cpp.s"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/ASIOTesting/asio-testing/src/server.cpp -o CMakeFiles/server.dir/server.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/connection.cpp.o" \
"CMakeFiles/server.dir/game_room.cpp.o" \
"CMakeFiles/server.dir/server.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

src/libserver.a: src/CMakeFiles/server.dir/connection.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/game_room.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/server.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/build.make
src/libserver.a: src/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/fozua/Desktop/ASIOTesting/asio-testing/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libserver.a"
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean_target.cmake
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/server.dir/build: src/libserver.a
.PHONY : src/CMakeFiles/server.dir/build

src/CMakeFiles/server.dir/clean:
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing/src && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/server.dir/clean

src/CMakeFiles/server.dir/depend:
	cd /Users/fozua/Desktop/ASIOTesting/asio-testing && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fozua/Desktop/ASIOTesting/asio-testing /Users/fozua/Desktop/ASIOTesting/asio-testing/src /Users/fozua/Desktop/ASIOTesting/asio-testing /Users/fozua/Desktop/ASIOTesting/asio-testing/src /Users/fozua/Desktop/ASIOTesting/asio-testing/src/CMakeFiles/server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/server.dir/depend
