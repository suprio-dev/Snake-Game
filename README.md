# 🐍 Snake Game in C

A simple **console-based Snake Game written in C**, created as my first game project while learning the fundamentals of C programming.

This project helped me understand how basic programming concepts such as **variables, loops, conditional statements, user input, random numbers, and game logic** can come together to create an interactive program.

## 🎮 About the Game

The objective is simple:

* 🐍 Move the snake around the game board
* 🍎 Eat the food (`*`)
* 📈 Increase your score
* 🧱 Avoid hitting the walls
* ❌ Quit whenever you want

Every time the snake reaches the food, the score increases and the food appears at a new random position.

## 🛠️ Technologies Used

* **C Programming Language**
* **GCC Compiler**
* **Windows Console**

### Libraries

* `stdio.h` — Input and output
* `stdlib.h` — Random number generation and system commands
* `windows.h` — Windows-specific console support

## 🎯 Controls

| Key | Action        |
| --- | ------------- |
| `U` | Move Up ⬆️    |
| `D` | Move Down ⬇️  |
| `L` | Move Left ⬅️  |
| `R` | Move Right ➡️ |
| `Q` | Quit Game ❌   |

> **Note:** This version uses keyboard input followed by `Enter`.

## ✨ Features

* 🖥️ Console-based gameplay
* 🐍 Snake movement
* 🍎 Random food generation
* 📊 Score tracking
* 🧱 Border collision detection
* 💀 Game-over condition
* 🎮 Simple keyboard controls
* 🔄 Replayable gameplay
* 🌱 Beginner-friendly C implementation

## 🧠 What I Learned

Building this project gave me practical experience with several fundamental C concepts.

### 1. Variables

Used variables to keep track of the snake's position, food position, score, and player input.

### 2. Loops

Nested `for` loops are used to draw the game board row by row and column by column.

The `while` loop keeps the game running until the player quits or the game ends.

### 3. Conditional Statements

`if`, `else if`, and `else` conditions are used to:

* Draw the border
* Display the snake
* Display the food
* Detect when food is eaten
* Detect collisions
* Handle player movement

### 4. Random Numbers

Random numbers are used to generate a new position for the food after it is eaten.

### 5. Keyboard Input

User input is taken using `scanf()` to determine the direction in which the snake should move.

### 6. Game Logic

The most interesting part was learning how individual programming concepts can work together inside a continuous **game loop**.

## 🔄 Game Flow

```text
Start Game
    ↓
Initialize Snake
    ↓
Set Food Position
    ↓
Draw Game Board
    ↓
Check Game Over
    ↓
Update Score
    ↓
Check Food
    ↓
Take User Input
    ↓
Move Snake
    ↓
Repeat
```

## 🚀 Future Improvements

There is a lot of room to expand this project. Some improvements I would like to add in future versions:

* 🐍 Actual snake body and growth
* ⚡ Continuous movement
* 🎮 Real-time keyboard controls
* 🏆 High-score system
* 🔊 Sound effects
* 🎨 Better console graphics
* 📈 Increasing difficulty
* ⏸️ Pause and resume
* 🧱 Obstacles
* 🗺️ Different maps
* 🍎 Multiple food types
* 💾 Save high scores
* 👥 Two-player mode

## 📚 Why I Made This Project

As a beginner, I wanted to go beyond writing individual C programs and build something that actually **works and feels interactive**.

This project taught me an important lesson:

> Programming is not just about learning individual concepts. It's about combining those concepts to build something real.

This Snake Game is my **first step toward building larger and more complex projects in the future.** 🚀

## ❤️ My First Game

> **My first game. My first step into building with C.**

It may be a simple console game, but it represents an important milestone in my programming journey.

From basic C programs to my first game — **this is just the beginning. 🐍🚀**

## 👨‍💻 Author

**Sriyan Acharya**
B.Tech CSE (AI) Student
UEM Kolkata

---

⭐ If you found this project interesting, feel free to **star the repository**!
