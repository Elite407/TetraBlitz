# TetraBlitz - A Tetris Game

TetraBlitz is a console-based implementation of the classic **Tetris** game, developed in **C++**. It features standard Tetris mechanics, including falling tetrominoes, line clearing, scoring, and game-over conditions.

---

## Table Of Contents

1. [Features](#features)
2. [Controls](#controls)
3. [Game Progression](#game-progression)
4. [Technical Details](#technical-details)
5. [Installation and Execution](#installation-and-execution)

---

## Overview

TetraBlitz follows the traditional Tetris rules and mechanics while ensuring smooth gameplay. The game increases in difficulty as the speed of falling tetrominoes gradually increases.

---

## Features

### Game Mechanics
- **Tetromino Pieces:** Includes all seven standard tetrominoes (I, O, T, S, Z, J, L).
- **Piece Movement:** Players can move left/right, rotate, and drop pieces.
- **Gravity:** Tetrominoes fall at a constant speed that increases as the game progresses.
- **Collision Detection:** Prevents blocks from overlapping or moving out of bounds.
- **Line Clearing:** Full rows are removed, the score is updated, and the grid shifts downward.
- **Scoring System:** Points are awarded based on the number of cleared lines.

---

## Controls

- **A** → Move piece left  
- **D** → Move piece right  
- **W** → Rotate piece  
- **S** → Soft drop (move piece downward faster)  
- **Spacebar** → Hard drop (instantly place the piece)  
- **E** → Quit the game  
- **R** → Restart the game  

---

## Game Progression

- The speed of falling pieces increases after clearing a certain number of lines.
- The game displays the **current score and level**.
- The game ends when blocks reach the **top of the grid**.

---

## Technical Details

### Programming Concepts Used
- **Object-Oriented Programming (OOP):** The game is structured using classes and structs to manage tetrominoes and game logic efficiently.
- **Encapsulation:** Game-related data members are protected within classes for better modularity.
- **Polymorphism & Inheritance:** Different tetromino shapes share a common interface while allowing unique implementations for rotations.

### Data Structures
- **2D Vector (`vector<vector<int>>`)** → Represents the game grid.
- **Structs for Tetrominoes** → Stores shape, rotation states, and position.
- **Queue System** → Manages upcoming tetrominoes for a next-piece preview.
- **Unordered Maps (`unordered_map<char, vector<vector<int>>>`)** → Stores tetromino shapes and rotations efficiently.

### Real-Time Input Handling
- Uses `_kbhit()` and `_getch()` functions to capture real-time keyboard input.
- Implements an input buffer to prevent lag and improve responsiveness.

### Game Loop
- The game runs in a continuous loop handling:
  - **Rendering:** Updates the grid and displays the game.
  - **Input Processing:** Captures user input for movement and rotation.
  - **Gravity Mechanics:** Moves pieces downward at an increasing speed.
  - **Collision Detection:** Ensures pieces do not overlap or move outside the grid.

### Collision Detection
- Ensures that:
  - Pieces do not move beyond grid boundaries.
  - Pieces stop falling when they land on existing blocks.
  - Wall-kicks allow smooth rotations near edges when necessary.

### Score Calculation
- **Basic Clearing:** 100 points per cleared line.
- **Combo Bonus:** Consecutive line clears increase the score multiplier.
- **Tetris Bonus:** Clearing 4 lines at once grants extra points.
- **Speed-Based Bonus:** Faster clears yield higher scores.

---

## Installation and Execution

### Clone the Repository

```sh
git clone https://github.com/Elite407/TetraBlitz.git
cd TetraBlitz
```

### Compilation

Compile the source code (`tetris-final.cpp`) using a **C++17 or later** compiler:

```sh
g++ -std=c++17 tetris-final.cpp -o tetris
```

### Run the Game

```sh
./tetris
```

---

Enjoy playing TetraBlitz! Test your reflexes and aim for the highest score!

