# Table Of Contents

1 - [Features](#Features)





# TetraBlitz
It is a tetromino (tetris) game.

# Overview
This project is a console-based implementation of the classic Tetris game developed in C++. It features all standard Tetris mechanics, including falling tetrominoes, line clearing, scoring, and game-over conditions. The game is designed to be simple yet engaging, with a smooth user experience.


# Features
Game Mechanics
Tetromino Pieces: Includes all seven standard tetrominoes (I, O, T, S, Z, J, L).
Piece Movement: Players can move left/right, rotate, and drop pieces.
Gravity: Tetrominoes fall at a constant speed that increases as the game progresses.
Collision Detection: Prevents blocks from overlapping or moving out of bounds.
Line Clearing: Full rows are removed, the score is updated, and the grid shifts downward.
Scoring System: Points are awarded for cleared lines (100 points per line).

# Controls
A: Move piece left
D: Move piece right
W: Rotate piece
S: Soft drop (move piece downward faster)
Spacebar: Hard drop (instantly place the piece)
E: Quit the game
R: Restart the game

# Game Progression
Speed increases after clearing a certain number of lines.
Displays current score and level on-screen.
Detects game-over when blocks reach the top of the grid.

# Technical Details
Programming Concepts Used:
Object-Oriented Programming (OOP): Classes and structs are used to manage tetrominoes and game logic.

# Data Structures:
2D arrays (vector<vector<int>>) for grid representation.
Structs for tetromino shapes and positions.
Real-Time Input Handling: Captures keyboard input using _kbhit() and _getch() functions for seamless gameplay.
Collision Detection: Ensures pieces fit in the grid without overlapping or going out of bounds.

# Game Loop:

A continuous loop handles drawing, input processing, and gravity mechanics.

# Score Calculation:
Points are awarded based on the number of cleared rows.

# Installation and Execution
https://github.com/Elite407/TetraBlitz/tree/main
Clone or download this repository to your local machine :
Compile the source code (tetris-final.cpp) using a C++ compiler that supports C++17 or later (e.g., GCC or MSVC).
g++ -std=c++17 tetris-final.cpp -o tetris

Run the compiled executable:
./tetris


