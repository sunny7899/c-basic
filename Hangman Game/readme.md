# Hangman Game in C++

## Overview
This is a simple console-based Hangman game implemented in C++. Try to save the character from being hanged by correctly guessing the letters in the hidden codeword.

## Rules
- **Objective:** Guess the letters in the codeword to reveal it and save the character.
- **Controls:** 
  - Enter a letter when prompted to make a guess.
- **Winning:** The game is won if you guess all letters in the codeword before the character is fully "hanged."
- **Losing:** If you make 7 incorrect guesses, the game ends, and the character is hanged.

## Game Flow
1. Start the game by running the program.
2. Enter letters to guess parts of the hidden codeword.
3. The game displays incorrect guesses, remaining attempts, and progress on the codeword.
4. The game ends when you either reveal the codeword or make 7 incorrect guesses.

## Installation

### Requirements
- C++ compiler

### Compile the Game
Compile all the files with a C++ compiler:
```bash
g++ main.cpp hangman_functions.cpp -o hangman_game

```

## Run the Game
Execute the compiled program:

- **Linux:** ./hangman_game
- **Windows:** hangman_game.exe
