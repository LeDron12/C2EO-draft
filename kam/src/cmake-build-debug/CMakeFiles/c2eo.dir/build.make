# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrew/c2eo-draft/kam/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/c2eo-draft/kam/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c2eo.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/c2eo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c2eo.dir/flags.make

CMakeFiles/c2eo.dir/main.cpp.o: CMakeFiles/c2eo.dir/flags.make
CMakeFiles/c2eo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/c2eo-draft/kam/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c2eo.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c2eo.dir/main.cpp.o -c /home/andrew/c2eo-draft/kam/src/main.cpp

CMakeFiles/c2eo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c2eo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/c2eo-draft/kam/src/main.cpp > CMakeFiles/c2eo.dir/main.cpp.i

CMakeFiles/c2eo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c2eo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/c2eo-draft/kam/src/main.cpp -o CMakeFiles/c2eo.dir/main.cpp.s

CMakeFiles/c2eo.dir/vardecl.cpp.o: CMakeFiles/c2eo.dir/flags.make
CMakeFiles/c2eo.dir/vardecl.cpp.o: ../vardecl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/c2eo-draft/kam/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/c2eo.dir/vardecl.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c2eo.dir/vardecl.cpp.o -c /home/andrew/c2eo-draft/kam/src/vardecl.cpp

CMakeFiles/c2eo.dir/vardecl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c2eo.dir/vardecl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/c2eo-draft/kam/src/vardecl.cpp > CMakeFiles/c2eo.dir/vardecl.cpp.i

CMakeFiles/c2eo.dir/vardecl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c2eo.dir/vardecl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/c2eo-draft/kam/src/vardecl.cpp -o CMakeFiles/c2eo.dir/vardecl.cpp.s

CMakeFiles/c2eo.dir/funcdecl.cpp.o: CMakeFiles/c2eo.dir/flags.make
CMakeFiles/c2eo.dir/funcdecl.cpp.o: ../funcdecl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/c2eo-draft/kam/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/c2eo.dir/funcdecl.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c2eo.dir/funcdecl.cpp.o -c /home/andrew/c2eo-draft/kam/src/funcdecl.cpp

CMakeFiles/c2eo.dir/funcdecl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c2eo.dir/funcdecl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/c2eo-draft/kam/src/funcdecl.cpp > CMakeFiles/c2eo.dir/funcdecl.cpp.i

CMakeFiles/c2eo.dir/funcdecl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c2eo.dir/funcdecl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/c2eo-draft/kam/src/funcdecl.cpp -o CMakeFiles/c2eo.dir/funcdecl.cpp.s

CMakeFiles/c2eo.dir/analyzers.cpp.o: CMakeFiles/c2eo.dir/flags.make
CMakeFiles/c2eo.dir/analyzers.cpp.o: ../analyzers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/c2eo-draft/kam/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/c2eo.dir/analyzers.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c2eo.dir/analyzers.cpp.o -c /home/andrew/c2eo-draft/kam/src/analyzers.cpp

CMakeFiles/c2eo.dir/analyzers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c2eo.dir/analyzers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/c2eo-draft/kam/src/analyzers.cpp > CMakeFiles/c2eo.dir/analyzers.cpp.i

CMakeFiles/c2eo.dir/analyzers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c2eo.dir/analyzers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/c2eo-draft/kam/src/analyzers.cpp -o CMakeFiles/c2eo.dir/analyzers.cpp.s

CMakeFiles/c2eo.dir/matchers.cpp.o: CMakeFiles/c2eo.dir/flags.make
CMakeFiles/c2eo.dir/matchers.cpp.o: ../matchers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/c2eo-draft/kam/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/c2eo.dir/matchers.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c2eo.dir/matchers.cpp.o -c /home/andrew/c2eo-draft/kam/src/matchers.cpp

CMakeFiles/c2eo.dir/matchers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c2eo.dir/matchers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/c2eo-draft/kam/src/matchers.cpp > CMakeFiles/c2eo.dir/matchers.cpp.i

CMakeFiles/c2eo.dir/matchers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c2eo.dir/matchers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/c2eo-draft/kam/src/matchers.cpp -o CMakeFiles/c2eo.dir/matchers.cpp.s

CMakeFiles/c2eo.dir/generator.cpp.o: CMakeFiles/c2eo.dir/flags.make
CMakeFiles/c2eo.dir/generator.cpp.o: ../generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/c2eo-draft/kam/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/c2eo.dir/generator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c2eo.dir/generator.cpp.o -c /home/andrew/c2eo-draft/kam/src/generator.cpp

CMakeFiles/c2eo.dir/generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c2eo.dir/generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/c2eo-draft/kam/src/generator.cpp > CMakeFiles/c2eo.dir/generator.cpp.i

CMakeFiles/c2eo.dir/generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c2eo.dir/generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/c2eo-draft/kam/src/generator.cpp -o CMakeFiles/c2eo.dir/generator.cpp.s

CMakeFiles/c2eo.dir/util.cpp.o: CMakeFiles/c2eo.dir/flags.make
CMakeFiles/c2eo.dir/util.cpp.o: ../util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/c2eo-draft/kam/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/c2eo.dir/util.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c2eo.dir/util.cpp.o -c /home/andrew/c2eo-draft/kam/src/util.cpp

CMakeFiles/c2eo.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c2eo.dir/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/c2eo-draft/kam/src/util.cpp > CMakeFiles/c2eo.dir/util.cpp.i

CMakeFiles/c2eo.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c2eo.dir/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/c2eo-draft/kam/src/util.cpp -o CMakeFiles/c2eo.dir/util.cpp.s

# Object files for target c2eo
c2eo_OBJECTS = \
"CMakeFiles/c2eo.dir/main.cpp.o" \
"CMakeFiles/c2eo.dir/vardecl.cpp.o" \
"CMakeFiles/c2eo.dir/funcdecl.cpp.o" \
"CMakeFiles/c2eo.dir/analyzers.cpp.o" \
"CMakeFiles/c2eo.dir/matchers.cpp.o" \
"CMakeFiles/c2eo.dir/generator.cpp.o" \
"CMakeFiles/c2eo.dir/util.cpp.o"

# External object files for target c2eo
c2eo_EXTERNAL_OBJECTS =

c2eo: CMakeFiles/c2eo.dir/main.cpp.o
c2eo: CMakeFiles/c2eo.dir/vardecl.cpp.o
c2eo: CMakeFiles/c2eo.dir/funcdecl.cpp.o
c2eo: CMakeFiles/c2eo.dir/analyzers.cpp.o
c2eo: CMakeFiles/c2eo.dir/matchers.cpp.o
c2eo: CMakeFiles/c2eo.dir/generator.cpp.o
c2eo: CMakeFiles/c2eo.dir/util.cpp.o
c2eo: CMakeFiles/c2eo.dir/build.make
c2eo: CMakeFiles/c2eo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrew/c2eo-draft/kam/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable c2eo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c2eo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c2eo.dir/build: c2eo
.PHONY : CMakeFiles/c2eo.dir/build

CMakeFiles/c2eo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c2eo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c2eo.dir/clean

CMakeFiles/c2eo.dir/depend:
	cd /home/andrew/c2eo-draft/kam/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/c2eo-draft/kam/src /home/andrew/c2eo-draft/kam/src /home/andrew/c2eo-draft/kam/src/cmake-build-debug /home/andrew/c2eo-draft/kam/src/cmake-build-debug /home/andrew/c2eo-draft/kam/src/cmake-build-debug/CMakeFiles/c2eo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c2eo.dir/depend

