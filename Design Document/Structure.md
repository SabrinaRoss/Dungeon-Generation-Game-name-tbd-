# Project Structure

This document outlines the planned file structure for the project, providing a clear overview of how the codebase is organized.

**Notice:** The core file structure and initial template of this document were generated with the assistance of Google Gemini 2.0 Flash Thinking Experimental.

### Top-Level Files and Directories: 
* `.gitignore`: Specifies intentionally untracked files that Git should ignore. This helps keep the repository clean.
*  `bin/`: (Likely created after the first successful build) Contains the compiled executable(s) of the game.
*  `build/`: Contains intermediate build files generated by CMake or your build system. This directory is typically not committed to version control (but I made it so with a .placeholder file inside the directory before adding it to the gitignore, because I think it is more convinent).
* `CMakeLists.txt`: The CMake configuration file used to manage the build process, dependencies, and project settings.
* `Design Document/`: Contains high-level design documentation, planning documents, and potentially research notes (and the occasional crazy one liner by yours truly, idk yet though, have yet to write any).
* `include/`: Contains the public header files (.h) that define the interfaces for the different modules. The subdirectory structure mirrors the `src/` directory.
* `LICENSE`: Contains the GNU GENERAL PUBLIC LICENSE under which the project is distributed.
* `README.md`: Provides an overview of the project, instructions on how to build and run it, and other essential information for users and developers.
* `src/`: Contains the source code files (.cpp) and their corresponding header files (.h) (Note: I have yet to decide which header format want to use).

## src/

This directory contains the source code files (.cpp) and their corresponding header files (.h / .hpp).

* **core/**
    * Source Files:
        * `game.cpp`
        * `game_state.cpp`
        * `... (other core game logic)`
    * Header Files:
        * `game.h`
        * `game_state.h`

* **dungeon/**
    * Source Files:
        * `dungeon.cpp`
        * `tile.cpp`
        * `dungeon_generator.cpp`
        * `... (different generation algorithms, room/corridor classes)`
    * Header Files:
        * `dungeon.h`
        * `tile.h`
        * `dungeon_generator.h`

* **entities/**
    * Source Files:
        * `entity.cpp`
        * `player.cpp`
        * `enemy.cpp`
        * `item.cpp`
        * `... (specific enemy types, item types, etc.)`
    * Header Files:
        * `entity.h`
        * `player.h`
        * `enemy.h`
        * `item.h`

* **graphics/**
    * Source Files:
        * `renderer.cpp`
        * `sprite_manager.cpp`
        * `... (texture loading, animation handling)`
    * Header Files:
        * `renderer.h`
        * `sprite_manager.h`

* **input/**
    * Source Files:
        * `input_handler.cpp`
        * `... (specific input actions, command pattern)`
    * Header Files:
        * `input_handler.h`

* **utils/**
    * Source Files:
        * `random.cpp`
        * `logger.cpp`
        * `... (other utility functions or classes)`
    * Header Files:
        * `random.h`
        * `logger.h`

* `main.cpp`

## include/

This directory contains the public header files (.h / .hpp) that define the interfaces for the different modules. The subdirectory structure mirrors the `src/` directory.

* **core/**
* **dungeon/**
* **entities/**
* **graphics/**
* **input/**
* **utils/**

## assets/

This directory stores all non-code assets used by the game.

* **textures/**
    * **tiles/**
    * **entities/**
* **sounds/**
* **fonts/**