![so long img](https://raw.githubusercontent.com/Ebejay95/so_long/master/so_long.gif)

# so_long

**A simple 2D game developed in C using the MinilibX library.**

This project involves creating a basic 2D game where the player navigates through a maze, collects items, and reaches the exit while avoiding enemies. It demonstrates proficiency in game development concepts, graphics handling, and event-driven programming.

## Structure

### src/

The `src` directory contains the core game logic and implementation files:

- **main.c**: The entry point of the game, handling initialization and the main game loop.
- **map.c**: Responsible for loading, validating, and displaying the game map.
- **player.c**: Manages player movements, interactions with the environment, and collision detection.
- **enemy.c**: Handles enemy behavior and interactions with the player.
- **render.c**: Manages rendering of game elements, including the map, player, and enemies.
- **utils.c**: Contains utility functions for memory management, string manipulation, and error handling.

### includes/

The `includes` directory contains the header files:

- **so_long.h**: Declares function prototypes and defines macros used across the project.

### assets/

The `assets` directory stores game resources:

- **images/**: Contains sprite images used for the player, enemies, items, and map tiles.

### Makefile

The Makefile automates the build process, compiling all source files and linking them to create the final executable.

## Features

- **2D Game Mechanics**: Implements basic game mechanics such as player movement, item collection, and level completion.
- **Graphics Rendering**: Utilizes the MinilibX library to render game graphics and handle user input.
- **Event Handling**: Responds to player input and game events in real-time.

## Usage

To compile the project, run:

```bash
make
