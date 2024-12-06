# Chess AI Project
A personal C++ project featuring a fully functional chess game with an intelligent AI opponent and a graphical user interface built using SFML.
# Project Overview
This Chess AI project is a comprehensive implementation of the classic game of chess in C++. It includes a robust AI opponent that leverages advanced algorithms to make strategic decisions, 
ensuring challenging gameplay. The graphical user interface (GUI) is developed using SFML (Simple and Fast Multimedia Library), providing an intuitive and visually appealing experience for users.

# Features
* **Intelligent AI Opponent:** Implements the Negamax algorithm with alpha-beta pruning to evaluate and select optimal moves. 
* **Graphical User Interface:** Interactive and responsive chessboard with clearly distinguishable pieces, built using SFML.
* **Comprehensive Move Validation:** Supports all standard chess rules, including castling, en passant, and pawn promotion.
* **Game State Management:** Detects and handles various game states such as check, checkmate, stalemate, and insufficient material.
* **Resource Management**: Efficient handling of textures and fonts through a singleton ResourceManager class to optimize performance.
* **User Interaction:** Click-based piece selection and movement with visual highlights indicating valid moves.
* **Game Over Handling:** Displays end-game messages with options to play again or exit, ensuring a seamless user experience.

# Technologies Used
* **C++17:** Core programming language for implementing game logic and AI.
* **SFML (Simple and Fast Multimedia Library):** Used for rendering graphics, handling user input, and managing multimedia components.
* **Object-Oriented Programming (OOP):** Structured using classes and inheritance to represent different chess pieces and game components.
* **Algorithms:** Utilized Negamax with alpha-beta pruning for efficient AI decision-making and move evaluation.

# Key Achievements
* **AI Implementation:** Successfully developed an AI opponent capable of evaluating multiple moves ahead, providing a challenging experience for players.
* **Efficient Algorithms:** Enhanced move selection efficiency through strategic move ordering heuristics and alpha-beta pruning, reducing computation time.
* **Robust Move Validation:** Ensured all moves adhere to standard chess rules, including handling complex scenarios like en passant and castling.
* **User-Friendly Interface:** Designed an intuitive GUI that allows users to interact with the game effortlessly, enhancing overall gameplay enjoyment.
* **Error Handling:** Implemented comprehensive error handling to manage invalid moves and unexpected scenarios gracefully.

# Installation and Setup
## Prerequisites
* **C++17 Compiler**: C++17 Compiler: Ensure you have a C++17 compatible compiler installed (e.g., GCC, Clang, MSVC).
*  **SFML Library**: Version 2.5 or later is rqeuired for graphic rendering.

## Steps to build and run
1. Clone the repository

```
git clone 'https://github.com/shoemant/chess-ai-project.git'

git chess-ai-project
```

2. Install SFML
* **Windows:** Download SFML from their [official website](https://www.sfml-dev.org/download.php) and follow the installation instructions.
* **macOS:** Use Homebrew to install SFML
  ' brew install sfml '

3. Build the Project
Use your preferred build system or compile directly using g++:

4. Run the application

# Usage
* **Select a Piece:** Click on any chess piece to select it. Valid moves for the selected piece will be highlighted.
* **Move a Piece:** Click on a highlighted square to move the selected piece to that location.
* **Special Moves:** The program supports castling, en passant, and pawn promotion. These are handled automatically based on the game state.
* **Game Over:** Upon checkmate, stalemate, or draw, a game over screen will appear with options to play again or exit the game.

# Code Structure
## Main Components
* **AIPlayer:** Handles the AI logic using the Negamax algorithm with alpha-beta pruning. Responsible for evaluating board states and selecting the best possible move.
* **Board:** Manages the state of the chessboard, including piece positions, move validation, and game state checks (e.g., check, checkmate).
* **Piece:** Abstract base class representing a chess piece. Derived classes (King, Queen, Bishop, Knight, Rook, Pawn) implement specific movement logic.
* **Game:** Controls the game loop, user interactions, AI move processing, and overall game state management.
* **UIManager:** Manages the graphical user interface elements, including the game over overlay and interactive buttons.
* **ResourceManager:** Singleton class responsible for loading and managing textures and fonts efficiently to optimize performance.
* **Utilities:** Contains helper functions for move validation and other utility operations.

# AI Details
The AI component utilizes the **Negamax** algorithm enhanced with **alpha-beta pruning** to efficiently explore the game tree and determine the most advantageous moves. The evaluation function considers both material balance and positional advantages using Piece-Square Tables, which assign values based on the location of each piece on the board. Additionally, the AI prioritizes moves that involve captures, castling, and promotions to optimize search efficiency.

## Evaluation Function
* **Material Balance:** Calculates the total value of pieces for both AI and the opponent.
* **Positional Advantage:** Uses piece-square tables to evaluate the strength of piece positions on the board.
* **King Safety:** Assesses the safety of the king to prevent checkmate scenarios.
## Move Ordering
Moves are sorted based on a heuristic that prioritizes captures, castling, and promotions. This improves the efficiency of alpha-beta pruning by exploring more promising moves first, potentially reducing the number of nodes evaluated.

## Future Enhancements
* **AI Depth Adjustment:** Implement dynamic depth adjustment to balance AI difficulty based on player skill.
* **Enhanced Graphics:** Add animations and sound effects to enrich the user experience.
* **Multiplayer Support:** Enable online multiplayer functionality for competitive play.
* **Move History and Undo:** Incorporate a move history log and the ability to undo moves.
* **Opening Book:** Integrate an opening book to improve AI performance in the early stages of the game.
