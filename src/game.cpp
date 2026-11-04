#include "../include/game.h"
#include "../include/board.h"
#include "../include/raylib.h"

#include <iostream>

const int X_BOARD = 15;
const int Y_BOARD = 15;
const int BOMBS = 30;

Game::Game() : s_{X_BOARD, Y_BOARD, BOMBS} {
  this->state_ = "Game";
  this->Run();
}

Game::~Game() {

}

void Game::Run() {
  InitWindow(550, 550, "Sweeper");
  while (!WindowShouldClose()) {
    if (this->state_ == "Game") {
      s_.SweepLoop();
    } else {
    }
  }

  CloseWindow();
}