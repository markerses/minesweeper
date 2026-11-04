# Minesweeper Game Project
A remake of the classic puzzle game Minesweeper, using c++ and Raylib

## Mechanics

Generates a random board, with randomly placed bombs.

Tiles show the number of mines adjacent to it in a 9x9 grid around it
- Ex: 

      M M M
      0 4 0
      0 0 M

Use left click to reveal tiles that are hidden.
If a tile is already revealed, and surrounded by a number of flags that match its own number, it will reveal all non flagged tiles adjacent.

When right clicking, you place a flag.

To win, you must reveal all safe tiles. Upon winning, the entire board will be shown.

## Todo:
  - Add timer
  - Add Menu
  - Add 3 preset modes
    - Beginner, Medium, Expert
  - Show stats
    - Games won in each mode, fastest time, ect.
  - Save stats
  - Add customizable size
  - Add challenges

## Building:
``` bash
  cmake -B build
  cmake --build build