# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Chess Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Chess Project\build"

# Include any dependencies generated for this target.
include CMakeFiles/chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess.dir/flags.make

CMakeFiles/chess.dir/codegen:
.PHONY : CMakeFiles/chess.dir/codegen

CMakeFiles/chess.dir/src/Board.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/Board.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/Board.cpp.obj: D:/Chess\ Project/src/Board.cpp
CMakeFiles/chess.dir/src/Board.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess.dir/src/Board.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/Board.cpp.obj -MF CMakeFiles\chess.dir\src\Board.cpp.obj.d -o CMakeFiles\chess.dir\src\Board.cpp.obj -c "D:\Chess Project\src\Board.cpp"

CMakeFiles/chess.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/Board.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\Board.cpp" > CMakeFiles\chess.dir\src\Board.cpp.i

CMakeFiles/chess.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/Board.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\Board.cpp" -o CMakeFiles\chess.dir\src\Board.cpp.s

CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.obj: D:/Chess\ Project/src/ChessEngine/AIPlayer.cpp
CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.obj -MF CMakeFiles\chess.dir\src\ChessEngine\AIPlayer.cpp.obj.d -o CMakeFiles\chess.dir\src\ChessEngine\AIPlayer.cpp.obj -c "D:\Chess Project\src\ChessEngine\AIPlayer.cpp"

CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\ChessEngine\AIPlayer.cpp" > CMakeFiles\chess.dir\src\ChessEngine\AIPlayer.cpp.i

CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\ChessEngine\AIPlayer.cpp" -o CMakeFiles\chess.dir\src\ChessEngine\AIPlayer.cpp.s

CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.obj: D:/Chess\ Project/src/ChessEngine/PieceSquareTables.cpp
CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.obj -MF CMakeFiles\chess.dir\src\ChessEngine\PieceSquareTables.cpp.obj.d -o CMakeFiles\chess.dir\src\ChessEngine\PieceSquareTables.cpp.obj -c "D:\Chess Project\src\ChessEngine\PieceSquareTables.cpp"

CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\ChessEngine\PieceSquareTables.cpp" > CMakeFiles\chess.dir\src\ChessEngine\PieceSquareTables.cpp.i

CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\ChessEngine\PieceSquareTables.cpp" -o CMakeFiles\chess.dir\src\ChessEngine\PieceSquareTables.cpp.s

CMakeFiles/chess.dir/src/Game.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/Game.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/Game.cpp.obj: D:/Chess\ Project/src/Game.cpp
CMakeFiles/chess.dir/src/Game.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chess.dir/src/Game.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/Game.cpp.obj -MF CMakeFiles\chess.dir\src\Game.cpp.obj.d -o CMakeFiles\chess.dir\src\Game.cpp.obj -c "D:\Chess Project\src\Game.cpp"

CMakeFiles/chess.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/Game.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\Game.cpp" > CMakeFiles\chess.dir\src\Game.cpp.i

CMakeFiles/chess.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/Game.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\Game.cpp" -o CMakeFiles\chess.dir\src\Game.cpp.s

CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.obj: D:/Chess\ Project/src/ResourceManager/ResourceManager.cpp
CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.obj -MF CMakeFiles\chess.dir\src\ResourceManager\ResourceManager.cpp.obj.d -o CMakeFiles\chess.dir\src\ResourceManager\ResourceManager.cpp.obj -c "D:\Chess Project\src\ResourceManager\ResourceManager.cpp"

CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\ResourceManager\ResourceManager.cpp" > CMakeFiles\chess.dir\src\ResourceManager\ResourceManager.cpp.i

CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\ResourceManager\ResourceManager.cpp" -o CMakeFiles\chess.dir\src\ResourceManager\ResourceManager.cpp.s

CMakeFiles/chess.dir/src/UIManager.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/UIManager.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/UIManager.cpp.obj: D:/Chess\ Project/src/UIManager.cpp
CMakeFiles/chess.dir/src/UIManager.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chess.dir/src/UIManager.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/UIManager.cpp.obj -MF CMakeFiles\chess.dir\src\UIManager.cpp.obj.d -o CMakeFiles\chess.dir\src\UIManager.cpp.obj -c "D:\Chess Project\src\UIManager.cpp"

CMakeFiles/chess.dir/src/UIManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/UIManager.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\UIManager.cpp" > CMakeFiles\chess.dir\src\UIManager.cpp.i

CMakeFiles/chess.dir/src/UIManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/UIManager.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\UIManager.cpp" -o CMakeFiles\chess.dir\src\UIManager.cpp.s

CMakeFiles/chess.dir/src/main.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/main.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/main.cpp.obj: D:/Chess\ Project/src/main.cpp
CMakeFiles/chess.dir/src/main.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/chess.dir/src/main.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/main.cpp.obj -MF CMakeFiles\chess.dir\src\main.cpp.obj.d -o CMakeFiles\chess.dir\src\main.cpp.obj -c "D:\Chess Project\src\main.cpp"

CMakeFiles/chess.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/main.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\main.cpp" > CMakeFiles\chess.dir\src\main.cpp.i

CMakeFiles/chess.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/main.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\main.cpp" -o CMakeFiles\chess.dir\src\main.cpp.s

CMakeFiles/chess.dir/src/pieces/Bishop.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/pieces/Bishop.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/pieces/Bishop.cpp.obj: D:/Chess\ Project/src/pieces/Bishop.cpp
CMakeFiles/chess.dir/src/pieces/Bishop.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/chess.dir/src/pieces/Bishop.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/pieces/Bishop.cpp.obj -MF CMakeFiles\chess.dir\src\pieces\Bishop.cpp.obj.d -o CMakeFiles\chess.dir\src\pieces\Bishop.cpp.obj -c "D:\Chess Project\src\pieces\Bishop.cpp"

CMakeFiles/chess.dir/src/pieces/Bishop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/pieces/Bishop.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\pieces\Bishop.cpp" > CMakeFiles\chess.dir\src\pieces\Bishop.cpp.i

CMakeFiles/chess.dir/src/pieces/Bishop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/pieces/Bishop.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\pieces\Bishop.cpp" -o CMakeFiles\chess.dir\src\pieces\Bishop.cpp.s

CMakeFiles/chess.dir/src/pieces/King.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/pieces/King.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/pieces/King.cpp.obj: D:/Chess\ Project/src/pieces/King.cpp
CMakeFiles/chess.dir/src/pieces/King.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/chess.dir/src/pieces/King.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/pieces/King.cpp.obj -MF CMakeFiles\chess.dir\src\pieces\King.cpp.obj.d -o CMakeFiles\chess.dir\src\pieces\King.cpp.obj -c "D:\Chess Project\src\pieces\King.cpp"

CMakeFiles/chess.dir/src/pieces/King.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/pieces/King.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\pieces\King.cpp" > CMakeFiles\chess.dir\src\pieces\King.cpp.i

CMakeFiles/chess.dir/src/pieces/King.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/pieces/King.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\pieces\King.cpp" -o CMakeFiles\chess.dir\src\pieces\King.cpp.s

CMakeFiles/chess.dir/src/pieces/Knight.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/pieces/Knight.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/pieces/Knight.cpp.obj: D:/Chess\ Project/src/pieces/Knight.cpp
CMakeFiles/chess.dir/src/pieces/Knight.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/chess.dir/src/pieces/Knight.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/pieces/Knight.cpp.obj -MF CMakeFiles\chess.dir\src\pieces\Knight.cpp.obj.d -o CMakeFiles\chess.dir\src\pieces\Knight.cpp.obj -c "D:\Chess Project\src\pieces\Knight.cpp"

CMakeFiles/chess.dir/src/pieces/Knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/pieces/Knight.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\pieces\Knight.cpp" > CMakeFiles\chess.dir\src\pieces\Knight.cpp.i

CMakeFiles/chess.dir/src/pieces/Knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/pieces/Knight.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\pieces\Knight.cpp" -o CMakeFiles\chess.dir\src\pieces\Knight.cpp.s

CMakeFiles/chess.dir/src/pieces/Pawn.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/pieces/Pawn.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/pieces/Pawn.cpp.obj: D:/Chess\ Project/src/pieces/Pawn.cpp
CMakeFiles/chess.dir/src/pieces/Pawn.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/chess.dir/src/pieces/Pawn.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/pieces/Pawn.cpp.obj -MF CMakeFiles\chess.dir\src\pieces\Pawn.cpp.obj.d -o CMakeFiles\chess.dir\src\pieces\Pawn.cpp.obj -c "D:\Chess Project\src\pieces\Pawn.cpp"

CMakeFiles/chess.dir/src/pieces/Pawn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/pieces/Pawn.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\pieces\Pawn.cpp" > CMakeFiles\chess.dir\src\pieces\Pawn.cpp.i

CMakeFiles/chess.dir/src/pieces/Pawn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/pieces/Pawn.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\pieces\Pawn.cpp" -o CMakeFiles\chess.dir\src\pieces\Pawn.cpp.s

CMakeFiles/chess.dir/src/pieces/Piece.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/pieces/Piece.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/pieces/Piece.cpp.obj: D:/Chess\ Project/src/pieces/Piece.cpp
CMakeFiles/chess.dir/src/pieces/Piece.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/chess.dir/src/pieces/Piece.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/pieces/Piece.cpp.obj -MF CMakeFiles\chess.dir\src\pieces\Piece.cpp.obj.d -o CMakeFiles\chess.dir\src\pieces\Piece.cpp.obj -c "D:\Chess Project\src\pieces\Piece.cpp"

CMakeFiles/chess.dir/src/pieces/Piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/pieces/Piece.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\pieces\Piece.cpp" > CMakeFiles\chess.dir\src\pieces\Piece.cpp.i

CMakeFiles/chess.dir/src/pieces/Piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/pieces/Piece.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\pieces\Piece.cpp" -o CMakeFiles\chess.dir\src\pieces\Piece.cpp.s

CMakeFiles/chess.dir/src/pieces/Queen.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/pieces/Queen.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/pieces/Queen.cpp.obj: D:/Chess\ Project/src/pieces/Queen.cpp
CMakeFiles/chess.dir/src/pieces/Queen.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/chess.dir/src/pieces/Queen.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/pieces/Queen.cpp.obj -MF CMakeFiles\chess.dir\src\pieces\Queen.cpp.obj.d -o CMakeFiles\chess.dir\src\pieces\Queen.cpp.obj -c "D:\Chess Project\src\pieces\Queen.cpp"

CMakeFiles/chess.dir/src/pieces/Queen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/pieces/Queen.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\pieces\Queen.cpp" > CMakeFiles\chess.dir\src\pieces\Queen.cpp.i

CMakeFiles/chess.dir/src/pieces/Queen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/pieces/Queen.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\pieces\Queen.cpp" -o CMakeFiles\chess.dir\src\pieces\Queen.cpp.s

CMakeFiles/chess.dir/src/pieces/Rook.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/pieces/Rook.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/pieces/Rook.cpp.obj: D:/Chess\ Project/src/pieces/Rook.cpp
CMakeFiles/chess.dir/src/pieces/Rook.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/chess.dir/src/pieces/Rook.cpp.obj"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/pieces/Rook.cpp.obj -MF CMakeFiles\chess.dir\src\pieces\Rook.cpp.obj.d -o CMakeFiles\chess.dir\src\pieces\Rook.cpp.obj -c "D:\Chess Project\src\pieces\Rook.cpp"

CMakeFiles/chess.dir/src/pieces/Rook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/pieces/Rook.cpp.i"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Chess Project\src\pieces\Rook.cpp" > CMakeFiles\chess.dir\src\pieces\Rook.cpp.i

CMakeFiles/chess.dir/src/pieces/Rook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/pieces/Rook.cpp.s"
	\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Chess Project\src\pieces\Rook.cpp" -o CMakeFiles\chess.dir\src\pieces\Rook.cpp.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/src/Board.cpp.obj" \
"CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.obj" \
"CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.obj" \
"CMakeFiles/chess.dir/src/Game.cpp.obj" \
"CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.obj" \
"CMakeFiles/chess.dir/src/UIManager.cpp.obj" \
"CMakeFiles/chess.dir/src/main.cpp.obj" \
"CMakeFiles/chess.dir/src/pieces/Bishop.cpp.obj" \
"CMakeFiles/chess.dir/src/pieces/King.cpp.obj" \
"CMakeFiles/chess.dir/src/pieces/Knight.cpp.obj" \
"CMakeFiles/chess.dir/src/pieces/Pawn.cpp.obj" \
"CMakeFiles/chess.dir/src/pieces/Piece.cpp.obj" \
"CMakeFiles/chess.dir/src/pieces/Queen.cpp.obj" \
"CMakeFiles/chess.dir/src/pieces/Rook.cpp.obj"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

chess.exe: CMakeFiles/chess.dir/src/Board.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/ChessEngine/AIPlayer.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/ChessEngine/PieceSquareTables.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/Game.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/ResourceManager/ResourceManager.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/UIManager.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/main.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/pieces/Bishop.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/pieces/King.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/pieces/Knight.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/pieces/Pawn.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/pieces/Piece.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/pieces/Queen.cpp.obj
chess.exe: CMakeFiles/chess.dir/src/pieces/Rook.cpp.obj
chess.exe: CMakeFiles/chess.dir/build.make
chess.exe: D:/msys64/ucrt64/lib/libsfml-graphics.dll.a
chess.exe: D:/msys64/ucrt64/lib/libsfml-window.dll.a
chess.exe: D:/msys64/ucrt64/lib/libsfml-system.dll.a
chess.exe: CMakeFiles/chess.dir/linkLibs.rsp
chess.exe: CMakeFiles/chess.dir/objects1.rsp
chess.exe: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\Chess Project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\chess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess.dir/build: chess.exe
.PHONY : CMakeFiles/chess.dir/build

CMakeFiles/chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/chess.dir/clean

CMakeFiles/chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Chess Project" "D:\Chess Project" "D:\Chess Project\build" "D:\Chess Project\build" "D:\Chess Project\build\CMakeFiles\chess.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/chess.dir/depend

