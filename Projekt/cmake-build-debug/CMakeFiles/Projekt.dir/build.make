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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Projekt.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Projekt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projekt.dir/flags.make

CMakeFiles/Projekt.dir/main.cpp.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projekt.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projekt.dir/main.cpp.o -c "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/main.cpp"

CMakeFiles/Projekt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projekt.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/main.cpp" > CMakeFiles/Projekt.dir/main.cpp.i

CMakeFiles/Projekt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projekt.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/main.cpp" -o CMakeFiles/Projekt.dir/main.cpp.s

CMakeFiles/Projekt.dir/FileIOEngine.cpp.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/FileIOEngine.cpp.o: ../FileIOEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Projekt.dir/FileIOEngine.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projekt.dir/FileIOEngine.cpp.o -c "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/FileIOEngine.cpp"

CMakeFiles/Projekt.dir/FileIOEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projekt.dir/FileIOEngine.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/FileIOEngine.cpp" > CMakeFiles/Projekt.dir/FileIOEngine.cpp.i

CMakeFiles/Projekt.dir/FileIOEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projekt.dir/FileIOEngine.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/FileIOEngine.cpp" -o CMakeFiles/Projekt.dir/FileIOEngine.cpp.s

CMakeFiles/Projekt.dir/Database.cpp.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/Database.cpp.o: ../Database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Projekt.dir/Database.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projekt.dir/Database.cpp.o -c "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/Database.cpp"

CMakeFiles/Projekt.dir/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projekt.dir/Database.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/Database.cpp" > CMakeFiles/Projekt.dir/Database.cpp.i

CMakeFiles/Projekt.dir/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projekt.dir/Database.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/Database.cpp" -o CMakeFiles/Projekt.dir/Database.cpp.s

CMakeFiles/Projekt.dir/FileHistory.cpp.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/FileHistory.cpp.o: ../FileHistory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Projekt.dir/FileHistory.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projekt.dir/FileHistory.cpp.o -c "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/FileHistory.cpp"

CMakeFiles/Projekt.dir/FileHistory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projekt.dir/FileHistory.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/FileHistory.cpp" > CMakeFiles/Projekt.dir/FileHistory.cpp.i

CMakeFiles/Projekt.dir/FileHistory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projekt.dir/FileHistory.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/FileHistory.cpp" -o CMakeFiles/Projekt.dir/FileHistory.cpp.s

# Object files for target Projekt
Projekt_OBJECTS = \
"CMakeFiles/Projekt.dir/main.cpp.o" \
"CMakeFiles/Projekt.dir/FileIOEngine.cpp.o" \
"CMakeFiles/Projekt.dir/Database.cpp.o" \
"CMakeFiles/Projekt.dir/FileHistory.cpp.o"

# External object files for target Projekt
Projekt_EXTERNAL_OBJECTS =

Projekt: CMakeFiles/Projekt.dir/main.cpp.o
Projekt: CMakeFiles/Projekt.dir/FileIOEngine.cpp.o
Projekt: CMakeFiles/Projekt.dir/Database.cpp.o
Projekt: CMakeFiles/Projekt.dir/FileHistory.cpp.o
Projekt: CMakeFiles/Projekt.dir/build.make
Projekt: CMakeFiles/Projekt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Projekt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projekt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projekt.dir/build: Projekt
.PHONY : CMakeFiles/Projekt.dir/build

CMakeFiles/Projekt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projekt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projekt.dir/clean

CMakeFiles/Projekt.dir/depend:
	cd "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt" "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt" "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug" "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug" "/Users/dasha/Desktop/CDV (2021 - 2022)/1 semestr zimowy/Podstawy programowania (laboratorium)/Zaliczenie/Projekt/cmake-build-debug/CMakeFiles/Projekt.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Projekt.dir/depend

