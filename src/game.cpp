#include "../include/game.h"
#include "../include/board.h"
#include "../include/raylib.h"

#include <iostream>

const int X_BOARD = 15;
const int Y_BOARD = 15;
const int BOMBS = 30;

Game::Game() : s_{nullptr}, m_{nullptr} {
  this->state_ = "Menu";
  this->Run();
}

Game::~Game() {
  delete this->s_;
  delete this->m_;
}

void Game::Run() {
  InitWindow(780, 780, "Sweeper");
  while (!WindowShouldClose()) {
    if (this->state_ == "Game") {
      s_->SweepLoop();
    } else {
    }
  }

  CloseWindow();
}