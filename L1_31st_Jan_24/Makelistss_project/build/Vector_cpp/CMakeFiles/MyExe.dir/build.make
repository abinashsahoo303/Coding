# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build

# Include any dependencies generated for this target.
include Vector_cpp/CMakeFiles/MyExe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Vector_cpp/CMakeFiles/MyExe.dir/compiler_depend.make

# Include the progress variables for this target.
include Vector_cpp/CMakeFiles/MyExe.dir/progress.make

# Include the compile flags for this target's objects.
include Vector_cpp/CMakeFiles/MyExe.dir/flags.make

Vector_cpp/CMakeFiles/MyExe.dir/Vector.cpp.obj: Vector_cpp/CMakeFiles/MyExe.dir/flags.make
Vector_cpp/CMakeFiles/MyExe.dir/Vector.cpp.obj: D:/Repo_GIT/Coding/L1_31st_Jan_24/Makelistss_project/Vector_cpp/Vector.cpp
Vector_cpp/CMakeFiles/MyExe.dir/Vector.cpp.obj: Vector_cpp/CMakeFiles/MyExe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Vector_cpp/CMakeFiles/MyExe.dir/Vector.cpp.obj"
	cd /d D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build\Vector_cpp && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Vector_cpp/CMakeFiles/MyExe.dir/Vector.cpp.obj -MF CMakeFiles\MyExe.dir\Vector.cpp.obj.d -o CMakeFiles\MyExe.dir\Vector.cpp.obj -c D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\Vector_cpp\Vector.cpp

Vector_cpp/CMakeFiles/MyExe.dir/Vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyExe.dir/Vector.cpp.i"
	cd /d D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build\Vector_cpp && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\Vector_cpp\Vector.cpp > CMakeFiles\MyExe.dir\Vector.cpp.i

Vector_cpp/CMakeFiles/MyExe.dir/Vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyExe.dir/Vector.cpp.s"
	cd /d D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build\Vector_cpp && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\Vector_cpp\Vector.cpp -o CMakeFiles\MyExe.dir\Vector.cpp.s

# Object files for target MyExe
MyExe_OBJECTS = \
"CMakeFiles/MyExe.dir/Vector.cpp.obj"

# External object files for target MyExe
MyExe_EXTERNAL_OBJECTS =

Vector_cpp/MyExe.exe: Vector_cpp/CMakeFiles/MyExe.dir/Vector.cpp.obj
Vector_cpp/MyExe.exe: Vector_cpp/CMakeFiles/MyExe.dir/build.make
Vector_cpp/MyExe.exe: Vector_cpp/CMakeFiles/MyExe.dir/linkLibs.rsp
Vector_cpp/MyExe.exe: Vector_cpp/CMakeFiles/MyExe.dir/objects1.rsp
Vector_cpp/MyExe.exe: Vector_cpp/CMakeFiles/MyExe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyExe.exe"
	cd /d D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build\Vector_cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MyExe.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Vector_cpp/CMakeFiles/MyExe.dir/build: Vector_cpp/MyExe.exe
.PHONY : Vector_cpp/CMakeFiles/MyExe.dir/build

Vector_cpp/CMakeFiles/MyExe.dir/clean:
	cd /d D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build\Vector_cpp && $(CMAKE_COMMAND) -P CMakeFiles\MyExe.dir\cmake_clean.cmake
.PHONY : Vector_cpp/CMakeFiles/MyExe.dir/clean

Vector_cpp/CMakeFiles/MyExe.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\Vector_cpp D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build\Vector_cpp D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\build\Vector_cpp\CMakeFiles\MyExe.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : Vector_cpp/CMakeFiles/MyExe.dir/depend

