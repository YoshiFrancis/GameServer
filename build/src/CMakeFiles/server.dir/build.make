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
CMAKE_SOURCE_DIR = /Users/fozua/Desktop/GameServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fozua/Desktop/GameServer/build

# Include any dependencies generated for this target.
include src/CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/server.dir/flags.make

src/CMakeFiles/server.dir/connection.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/connection.cpp.o: /Users/fozua/Desktop/GameServer/src/connection.cpp
src/CMakeFiles/server.dir/connection.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/GameServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/server.dir/connection.cpp.o"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/connection.cpp.o -MF CMakeFiles/server.dir/connection.cpp.o.d -o CMakeFiles/server.dir/connection.cpp.o -c /Users/fozua/Desktop/GameServer/src/connection.cpp

src/CMakeFiles/server.dir/connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/connection.cpp.i"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/GameServer/src/connection.cpp > CMakeFiles/server.dir/connection.cpp.i

src/CMakeFiles/server.dir/connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/connection.cpp.s"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/GameServer/src/connection.cpp -o CMakeFiles/server.dir/connection.cpp.s

src/CMakeFiles/server.dir/room.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/room.cpp.o: /Users/fozua/Desktop/GameServer/src/room.cpp
src/CMakeFiles/server.dir/room.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/GameServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/server.dir/room.cpp.o"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/room.cpp.o -MF CMakeFiles/server.dir/room.cpp.o.d -o CMakeFiles/server.dir/room.cpp.o -c /Users/fozua/Desktop/GameServer/src/room.cpp

src/CMakeFiles/server.dir/room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/room.cpp.i"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/GameServer/src/room.cpp > CMakeFiles/server.dir/room.cpp.i

src/CMakeFiles/server.dir/room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/room.cpp.s"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/GameServer/src/room.cpp -o CMakeFiles/server.dir/room.cpp.s

src/CMakeFiles/server.dir/server.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/server.cpp.o: /Users/fozua/Desktop/GameServer/src/server.cpp
src/CMakeFiles/server.dir/server.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/GameServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/server.dir/server.cpp.o"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/server.cpp.o -MF CMakeFiles/server.dir/server.cpp.o.d -o CMakeFiles/server.dir/server.cpp.o -c /Users/fozua/Desktop/GameServer/src/server.cpp

src/CMakeFiles/server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/server.cpp.i"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/GameServer/src/server.cpp > CMakeFiles/server.dir/server.cpp.i

src/CMakeFiles/server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/server.cpp.s"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/GameServer/src/server.cpp -o CMakeFiles/server.dir/server.cpp.s

src/CMakeFiles/server.dir/message.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/message.cpp.o: /Users/fozua/Desktop/GameServer/src/message.cpp
src/CMakeFiles/server.dir/message.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/GameServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/server.dir/message.cpp.o"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/message.cpp.o -MF CMakeFiles/server.dir/message.cpp.o.d -o CMakeFiles/server.dir/message.cpp.o -c /Users/fozua/Desktop/GameServer/src/message.cpp

src/CMakeFiles/server.dir/message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/message.cpp.i"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/GameServer/src/message.cpp > CMakeFiles/server.dir/message.cpp.i

src/CMakeFiles/server.dir/message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/message.cpp.s"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/GameServer/src/message.cpp -o CMakeFiles/server.dir/message.cpp.s

src/CMakeFiles/server.dir/hub.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/hub.cpp.o: /Users/fozua/Desktop/GameServer/src/hub.cpp
src/CMakeFiles/server.dir/hub.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/GameServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/server.dir/hub.cpp.o"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/hub.cpp.o -MF CMakeFiles/server.dir/hub.cpp.o.d -o CMakeFiles/server.dir/hub.cpp.o -c /Users/fozua/Desktop/GameServer/src/hub.cpp

src/CMakeFiles/server.dir/hub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/hub.cpp.i"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/GameServer/src/hub.cpp > CMakeFiles/server.dir/hub.cpp.i

src/CMakeFiles/server.dir/hub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/hub.cpp.s"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/GameServer/src/hub.cpp -o CMakeFiles/server.dir/hub.cpp.s

src/CMakeFiles/server.dir/lobby.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/lobby.cpp.o: /Users/fozua/Desktop/GameServer/src/lobby.cpp
src/CMakeFiles/server.dir/lobby.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/GameServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/server.dir/lobby.cpp.o"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/lobby.cpp.o -MF CMakeFiles/server.dir/lobby.cpp.o.d -o CMakeFiles/server.dir/lobby.cpp.o -c /Users/fozua/Desktop/GameServer/src/lobby.cpp

src/CMakeFiles/server.dir/lobby.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/lobby.cpp.i"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/GameServer/src/lobby.cpp > CMakeFiles/server.dir/lobby.cpp.i

src/CMakeFiles/server.dir/lobby.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/lobby.cpp.s"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/GameServer/src/lobby.cpp -o CMakeFiles/server.dir/lobby.cpp.s

src/CMakeFiles/server.dir/application.cpp.o: src/CMakeFiles/server.dir/flags.make
src/CMakeFiles/server.dir/application.cpp.o: /Users/fozua/Desktop/GameServer/src/application.cpp
src/CMakeFiles/server.dir/application.cpp.o: src/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/GameServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/server.dir/application.cpp.o"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/server.dir/application.cpp.o -MF CMakeFiles/server.dir/application.cpp.o.d -o CMakeFiles/server.dir/application.cpp.o -c /Users/fozua/Desktop/GameServer/src/application.cpp

src/CMakeFiles/server.dir/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/application.cpp.i"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/GameServer/src/application.cpp > CMakeFiles/server.dir/application.cpp.i

src/CMakeFiles/server.dir/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/application.cpp.s"
	cd /Users/fozua/Desktop/GameServer/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/GameServer/src/application.cpp -o CMakeFiles/server.dir/application.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/connection.cpp.o" \
"CMakeFiles/server.dir/room.cpp.o" \
"CMakeFiles/server.dir/server.cpp.o" \
"CMakeFiles/server.dir/message.cpp.o" \
"CMakeFiles/server.dir/hub.cpp.o" \
"CMakeFiles/server.dir/lobby.cpp.o" \
"CMakeFiles/server.dir/application.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

src/libserver.a: src/CMakeFiles/server.dir/connection.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/room.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/server.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/message.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/hub.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/lobby.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/application.cpp.o
src/libserver.a: src/CMakeFiles/server.dir/build.make
src/libserver.a: src/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/fozua/Desktop/GameServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libserver.a"
	cd /Users/fozua/Desktop/GameServer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean_target.cmake
	cd /Users/fozua/Desktop/GameServer/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/server.dir/build: src/libserver.a
.PHONY : src/CMakeFiles/server.dir/build

src/CMakeFiles/server.dir/clean:
	cd /Users/fozua/Desktop/GameServer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/server.dir/clean

src/CMakeFiles/server.dir/depend:
	cd /Users/fozua/Desktop/GameServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fozua/Desktop/GameServer /Users/fozua/Desktop/GameServer/src /Users/fozua/Desktop/GameServer/build /Users/fozua/Desktop/GameServer/build/src /Users/fozua/Desktop/GameServer/build/src/CMakeFiles/server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/server.dir/depend

