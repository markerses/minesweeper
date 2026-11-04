cmake_minimum_required(VERSION 3.28)

project(MarkersesMinesweeper)

add_executable(MarkersesMinesweeper)

target_sources(MarkersesMinesweeper
  PRIVATE
    src/main.cpp
    src/game.cpp
    src/sweeper.cpp
    src/board.cpp
    src/tile.cpp
)

target_include_directories(MarkersesMinesweeper
  PRIVATE
    include
)