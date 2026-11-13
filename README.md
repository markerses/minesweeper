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

## Features

3 Modes (Easy 9x9, Medium 16x16, Hard 30x16)

Left click to reveal or chord tiles

Right click to flag

Space to reset board

Game timer, shows your time for each board in seconds

## Todo:
  - Create UI element classes (text label, image, text buttons)
  - Add Menu
  - Show stats
    - Games won in each mode, fastest time, ect.
  - Save stats
  - Add customizable board size
  - Add settings for boards
  - Add challenges
  - Add graphics/polish

## Building:
``` bash
  cmake -B build
  cmake --build build