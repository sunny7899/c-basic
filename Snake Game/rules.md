# Snake Game in C

## Overview

This is a simple console-based Snake game implemented in C. Navigate the snake to collect fruits and grow your score while avoiding self-collision.

## Rules

1. **Objective**: Control the snake to eat the fruit (`F`) to grow your score. Each fruit collected increases your score by 10 points.
2. **Controls**:
   - `W`: Move Up
   - `A`: Move Left
   - `S`: Move Down
   - `D`: Move Right
   - `X`: Exit the Game
3. **Boundaries**: The game area is wrapped; moving off one edge will bring you back on the opposite edge.
4. **Collision**: The game ends if the snake collides with itself.
5. **Score**: Your current score is displayed at the bottom of the screen.

## Installation

1. **Compile**: Use a C compiler to compile the code:
   ```
   gcc snake_game.c -o snake_game
   ```
2. **Run**: Execute the compiled program:
   ```
   ./snake_game  // Linux
   snake_game.exe // Windows
   ```
