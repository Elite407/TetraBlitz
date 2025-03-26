# TetraBlitz
It is a tetromino (tetris) game.

Overview
This project is a console-based implementation of the classic Tetris game developed in C++. It features all standard Tetris mechanics, including falling tetrominoes, line clearing, scoring, and game-over conditions. The game is designed to be simple yet engaging, with a smooth user experience.


Features
Game Mechanics
Tetromino Pieces: Includes all seven standard tetrominoes (I, O, T, S, Z, J, L).

Grid Representation: The game board is a 10x20 grid.

Piece Movement: Players can move left/right, rotate, and drop pieces.

Gravity: Tetrominoes fall at a constant speed that increases as the game progresses.

Collision Detection: Prevents blocks from overlapping or moving out of bounds.

Line Clearing: Full rows are removed, and the grid shifts downward.

Scoring System: Points are awarded for cleared lines (100 points per line).

Controls
A: Move piece left

D: Move piece right

W: Rotate piece

S: Soft drop (move piece downward faster)

Spacebar: Hard drop (instantly place the piece)

E: Quit the game

R: Restart the game

Game Progression
Speed increases after clearing a certain number of lines.

Displays current score and level on-screen.

Detects game-over when blocks reach the top of the grid.

How to Play
Run the executable file in a console window.

Use the controls to manipulate tetrominoes and clear rows.

Aim to maximize your score by clearing multiple rows simultaneously.

If the blocks reach the top of the grid, the game ends. You can restart or exit.

Technical Details
Programming Concepts Used:
Object-Oriented Programming (OOP): Classes and structs are used to manage tetrominoes and game logic.

Data Structures:

2D arrays (vector<vector<int>>) for grid representation.

Structs for tetromino shapes and positions.

Real-Time Input Handling: Captures keyboard input using _kbhit() and _getch() functions for seamless gameplay.

Collision Detection: Ensures pieces fit in the grid without overlapping or going out of bounds.

Code Highlights:
Tetromino Representation:

Each tetromino is represented as a 2D array with specific shapes.

Game Loop:

A continuous loop handles drawing, input processing, and gravity mechanics.

Score Calculation:

Points are awarded based on the number of cleared rows.

Installation and Execution
Clone or download this repository to your local machine.

Compile the source code (tetris-final.cpp) using a C++ compiler that supports C++17 or later (e.g., GCC or MSVC).

bash
g++ -std=c++17 tetris-final.cpp -o tetris
Run the compiled executable:

bash
./tetris
Known Issues & Future Improvements
Current Limitations:
The game runs only in Windows console due to platform-specific code (SetConsoleCursorPosition).

No support for advanced Tetris features like hold pieces or ghost pieces.

Potential Enhancements:
Add support for other platforms (Linux/macOS).

Implement advanced mechanics such as hold functionality and ghost pieces.

Add sound effects and animations for better user experience.
