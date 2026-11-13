#include "../include/game.h"
#include "../include/board.h"
#include "../include/raylib.h"

#include <iostream>
#include <vector>
#include <string>

const int X_BOARD = 15;
const int Y_BOARD = 15;
const int BOMBS = 30;

Game::Game() : s_{nullptr}, m_{nullptr} {
  this->state_ = "Menu";
  this->m_ = new Menu();
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
      std::vector<int>* args = m_->MenuLoop();

      if (args != nullptr) {
        InitSweep(*args);
      }
    }
  }

  CloseWindow();
}

void Game::InitSweep(std::vector<int> args) {
  this->s_ = new Sweeper(args[0], args[1], args[2]);
  this->state_ = "Game";
  int x = (s_->kSTART_FROM_CORNER * 2) + (s_->kTILE_SIZE * args[0]);
  int y = (s_->kSTART_FROM_CORNER * 2) + (s_->kTILE_SIZE * args[1]);
  SetWindowSize(x, y);
}