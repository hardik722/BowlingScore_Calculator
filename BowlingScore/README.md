# Bowling Game Scoring System

This is a simple C++17-based bowling game simulator. It allows interactive gameplay and provides a full scoring system according to standard ten-pin bowling rules. Unit tests are written using Google Test to ensure correct scoring and functionality.

## Features

- Add rolls interactively frame-by-frame.
- Automatically calculates strikes, spares, and open frames.
- Prints scores after each frame.
- Final total score display.
- 100% unit test coverage using Google Test framework.
- Designed following the SOLID principles.


## Requirements

- C++17 compatible compiler (e.g., g++, clang++)
- Google Test (can be installed or linked via CMake)
- WSL or any Linux environment

## Build Instructions (WSL)

1. Open a terminal and navigate to your project directory
2. Build the project using the provided Makefile
    - make clean
    - make
3. To run the main code
    - make run
4. Build and run the unit test
    - make test
    - make run_test