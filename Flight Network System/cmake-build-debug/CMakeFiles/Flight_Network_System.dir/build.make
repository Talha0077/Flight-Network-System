# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\CLion\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\CLion\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\madina\Desktop\Flight Network System"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\madina\Desktop\Flight Network System\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Flight_Network_System.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Flight_Network_System.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Flight_Network_System.dir\flags.make

CMakeFiles\Flight_Network_System.dir\main.cpp.obj: CMakeFiles\Flight_Network_System.dir\flags.make
CMakeFiles\Flight_Network_System.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\madina\Desktop\Flight Network System\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Flight_Network_System.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Flight_Network_System.dir\main.cpp.obj /FdCMakeFiles\Flight_Network_System.dir\ /FS -c "C:\Users\madina\Desktop\Flight Network System\main.cpp"
<<

CMakeFiles\Flight_Network_System.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Flight_Network_System.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\Flight_Network_System.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\madina\Desktop\Flight Network System\main.cpp"
<<

CMakeFiles\Flight_Network_System.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Flight_Network_System.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Flight_Network_System.dir\main.cpp.s /c "C:\Users\madina\Desktop\Flight Network System\main.cpp"
<<

# Object files for target Flight_Network_System
Flight_Network_System_OBJECTS = \
"CMakeFiles\Flight_Network_System.dir\main.cpp.obj"

# External object files for target Flight_Network_System
Flight_Network_System_EXTERNAL_OBJECTS =

Flight_Network_System.exe: CMakeFiles\Flight_Network_System.dir\main.cpp.obj
Flight_Network_System.exe: CMakeFiles\Flight_Network_System.dir\build.make
Flight_Network_System.exe: CMakeFiles\Flight_Network_System.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\madina\Desktop\Flight Network System\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Flight_Network_System.exe"
	"C:\CLion\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Flight_Network_System.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Flight_Network_System.dir\objects1.rsp @<<
 /out:Flight_Network_System.exe /implib:Flight_Network_System.lib /pdb:"C:\Users\madina\Desktop\Flight Network System\cmake-build-debug\Flight_Network_System.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Flight_Network_System.dir\build: Flight_Network_System.exe

.PHONY : CMakeFiles\Flight_Network_System.dir\build

CMakeFiles\Flight_Network_System.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Flight_Network_System.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Flight_Network_System.dir\clean

CMakeFiles\Flight_Network_System.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\madina\Desktop\Flight Network System" "C:\Users\madina\Desktop\Flight Network System" "C:\Users\madina\Desktop\Flight Network System\cmake-build-debug" "C:\Users\madina\Desktop\Flight Network System\cmake-build-debug" "C:\Users\madina\Desktop\Flight Network System\cmake-build-debug\CMakeFiles\Flight_Network_System.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Flight_Network_System.dir\depend
