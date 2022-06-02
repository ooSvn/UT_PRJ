# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/ali/Desktop/C++/git_folder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ali/Desktop/C++/git_folder

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ali/Desktop/C++/git_folder/CMakeFiles /home/ali/Desktop/C++/git_folder/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ali/Desktop/C++/git_folder/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ap

# Build rule for target.
ap: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ap
.PHONY : ap

# fast build rule for target.
ap/fast:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/build
.PHONY : ap/fast

sources/bishop.o: sources/bishop.cpp.o

.PHONY : sources/bishop.o

# target to build an object file
sources/bishop.cpp.o:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/bishop.cpp.o
.PHONY : sources/bishop.cpp.o

sources/bishop.i: sources/bishop.cpp.i

.PHONY : sources/bishop.i

# target to preprocess a source file
sources/bishop.cpp.i:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/bishop.cpp.i
.PHONY : sources/bishop.cpp.i

sources/bishop.s: sources/bishop.cpp.s

.PHONY : sources/bishop.s

# target to generate assembly for a file
sources/bishop.cpp.s:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/bishop.cpp.s
.PHONY : sources/bishop.cpp.s

sources/board.o: sources/board.cpp.o

.PHONY : sources/board.o

# target to build an object file
sources/board.cpp.o:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/board.cpp.o
.PHONY : sources/board.cpp.o

sources/board.i: sources/board.cpp.i

.PHONY : sources/board.i

# target to preprocess a source file
sources/board.cpp.i:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/board.cpp.i
.PHONY : sources/board.cpp.i

sources/board.s: sources/board.cpp.s

.PHONY : sources/board.s

# target to generate assembly for a file
sources/board.cpp.s:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/board.cpp.s
.PHONY : sources/board.cpp.s

sources/king.o: sources/king.cpp.o

.PHONY : sources/king.o

# target to build an object file
sources/king.cpp.o:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/king.cpp.o
.PHONY : sources/king.cpp.o

sources/king.i: sources/king.cpp.i

.PHONY : sources/king.i

# target to preprocess a source file
sources/king.cpp.i:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/king.cpp.i
.PHONY : sources/king.cpp.i

sources/king.s: sources/king.cpp.s

.PHONY : sources/king.s

# target to generate assembly for a file
sources/king.cpp.s:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/king.cpp.s
.PHONY : sources/king.cpp.s

sources/knight.o: sources/knight.cpp.o

.PHONY : sources/knight.o

# target to build an object file
sources/knight.cpp.o:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/knight.cpp.o
.PHONY : sources/knight.cpp.o

sources/knight.i: sources/knight.cpp.i

.PHONY : sources/knight.i

# target to preprocess a source file
sources/knight.cpp.i:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/knight.cpp.i
.PHONY : sources/knight.cpp.i

sources/knight.s: sources/knight.cpp.s

.PHONY : sources/knight.s

# target to generate assembly for a file
sources/knight.cpp.s:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/knight.cpp.s
.PHONY : sources/knight.cpp.s

sources/main.o: sources/main.cpp.o

.PHONY : sources/main.o

# target to build an object file
sources/main.cpp.o:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/main.cpp.o
.PHONY : sources/main.cpp.o

sources/main.i: sources/main.cpp.i

.PHONY : sources/main.i

# target to preprocess a source file
sources/main.cpp.i:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/main.cpp.i
.PHONY : sources/main.cpp.i

sources/main.s: sources/main.cpp.s

.PHONY : sources/main.s

# target to generate assembly for a file
sources/main.cpp.s:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/main.cpp.s
.PHONY : sources/main.cpp.s

sources/null.o: sources/null.cpp.o

.PHONY : sources/null.o

# target to build an object file
sources/null.cpp.o:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/null.cpp.o
.PHONY : sources/null.cpp.o

sources/null.i: sources/null.cpp.i

.PHONY : sources/null.i

# target to preprocess a source file
sources/null.cpp.i:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/null.cpp.i
.PHONY : sources/null.cpp.i

sources/null.s: sources/null.cpp.s

.PHONY : sources/null.s

# target to generate assembly for a file
sources/null.cpp.s:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/null.cpp.s
.PHONY : sources/null.cpp.s

sources/pawn.o: sources/pawn.cpp.o

.PHONY : sources/pawn.o

# target to build an object file
sources/pawn.cpp.o:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/pawn.cpp.o
.PHONY : sources/pawn.cpp.o

sources/pawn.i: sources/pawn.cpp.i

.PHONY : sources/pawn.i

# target to preprocess a source file
sources/pawn.cpp.i:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/pawn.cpp.i
.PHONY : sources/pawn.cpp.i

sources/pawn.s: sources/pawn.cpp.s

.PHONY : sources/pawn.s

# target to generate assembly for a file
sources/pawn.cpp.s:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/pawn.cpp.s
.PHONY : sources/pawn.cpp.s

sources/queen.o: sources/queen.cpp.o

.PHONY : sources/queen.o

# target to build an object file
sources/queen.cpp.o:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/queen.cpp.o
.PHONY : sources/queen.cpp.o

sources/queen.i: sources/queen.cpp.i

.PHONY : sources/queen.i

# target to preprocess a source file
sources/queen.cpp.i:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/queen.cpp.i
.PHONY : sources/queen.cpp.i

sources/queen.s: sources/queen.cpp.s

.PHONY : sources/queen.s

# target to generate assembly for a file
sources/queen.cpp.s:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/queen.cpp.s
.PHONY : sources/queen.cpp.s

sources/rook.o: sources/rook.cpp.o

.PHONY : sources/rook.o

# target to build an object file
sources/rook.cpp.o:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/rook.cpp.o
.PHONY : sources/rook.cpp.o

sources/rook.i: sources/rook.cpp.i

.PHONY : sources/rook.i

# target to preprocess a source file
sources/rook.cpp.i:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/rook.cpp.i
.PHONY : sources/rook.cpp.i

sources/rook.s: sources/rook.cpp.s

.PHONY : sources/rook.s

# target to generate assembly for a file
sources/rook.cpp.s:
	$(MAKE) -f CMakeFiles/ap.dir/build.make CMakeFiles/ap.dir/sources/rook.cpp.s
.PHONY : sources/rook.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... ap"
	@echo "... sources/bishop.o"
	@echo "... sources/bishop.i"
	@echo "... sources/bishop.s"
	@echo "... sources/board.o"
	@echo "... sources/board.i"
	@echo "... sources/board.s"
	@echo "... sources/king.o"
	@echo "... sources/king.i"
	@echo "... sources/king.s"
	@echo "... sources/knight.o"
	@echo "... sources/knight.i"
	@echo "... sources/knight.s"
	@echo "... sources/main.o"
	@echo "... sources/main.i"
	@echo "... sources/main.s"
	@echo "... sources/null.o"
	@echo "... sources/null.i"
	@echo "... sources/null.s"
	@echo "... sources/pawn.o"
	@echo "... sources/pawn.i"
	@echo "... sources/pawn.s"
	@echo "... sources/queen.o"
	@echo "... sources/queen.i"
	@echo "... sources/queen.s"
	@echo "... sources/rook.o"
	@echo "... sources/rook.i"
	@echo "... sources/rook.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
