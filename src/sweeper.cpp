#include "../include/sweeper.h"

#include "../include/raylib.h"
#include "../include/board.h"

#include <iostream>
#include <string>

Sweeper::Sweeper(const int& x, const int& y, const int& bombs) : board_{x, y, bombs}, state_{"idle"}, time_elapsed_{0} {

}

Sweeper::~Sweeper() {

}

void Sweeper::SweepLoop() {
  this->Inputs();
  this->Calc();
  this->Draw();
}

void Sweeper::Inputs() {
  if (IsKeyPressed(KEY_SPACE)) {
    this->board_.ResetBoard();
    this->state_ = "idle";
    this->time_elapsed_ = 0.0;
  }

  this->MouseInputs();
}

void Sweeper::MouseInputs() {
  int clicked = 0;
  if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
    clicked = 2;
  } else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    clicked = 1;
  }

  if (clicked > 0) {
    auto [x, y] = MouseToTile(GetMouseX(), GetMouseY());
    bool success = false;

    if (clicked == 1) {
      success = this->board_.OnClick(x, y);
    } else if (clicked == 2) {
      success = this->board_.FlagTile(x, y);
    }

    if (this->state_ == "idle" && success)
      this->state_ = "clicked"; 
  }
}

std::pair<int, int> Sweeper::MouseToTile(const int& x, const int& y) {
  int new_x = (x - kSTART_FROM_CORNER) / kTILE_SIZE;
  int new_y = (y - kSTART_FROM_CORNER) / kTILE_SIZE;
  return {new_x, new_y};
}

void Sweeper::Calc() {
  if (this->state_ == "clicked") {
    StartTimer();
  } else if (this->state_ == "running") {
    UpdateTime();
  }

  if (this->board_.BoardStatus()) {
    StopTime();
  }
}

void Sweeper::StartTimer() {
  this->start_time_ = GetTime();
  this->state_ = "running";
}

void Sweeper::UpdateTime() {
  this->time_elapsed_ = GetTime() - this->start_time_;
}

void Sweeper::StopTime() {
  this->state_ = "idle";
}

void Sweeper::Draw() {
  BeginDrawing();

  ClearBackground(BLACK);
  DrawBoard();
  DrawInfo();

  EndDrawing();
}

void Sweeper::DrawBoard() {
  const int TEXT_OFFSET_X = 10;
  const int TEXT_OFFSET_Y = 6;
  const int TEXT_SIZE = 20;

  for (size_t i = 0; i < this->board_.GetSizeX(); i++) {
    for (size_t j = 0; j < this->board_.GetSizeY(); j++) {
      int x = kSTART_FROM_CORNER + (i * kTILE_SIZE);
      int y = kSTART_FROM_CORNER + (j * kTILE_SIZE);

      Tile* t = this->board_.ShowBoard()[i][j];
      if (!t->IsVisible()) {
        DrawRectangle(x, y, kTILE_SIZE, kTILE_SIZE, GRAY);

        if (t->IsFlagged())
          DrawText(std::string("F").c_str(), x + TEXT_OFFSET_X, y + TEXT_OFFSET_Y, TEXT_SIZE, BLACK); // Might memory leak...

      } else {
        int tile_num = t->TileNumber();
        Color col = tile_num == -1 ? RED : GREEN;

        DrawRectangle(x, y, kTILE_SIZE, kTILE_SIZE, col);

        if (tile_num > 0)
          DrawText(std::to_string(tile_num).c_str(), x + TEXT_OFFSET_X, y + TEXT_OFFSET_Y, TEXT_SIZE, BLACK);
      }
    }
  }
}

void Sweeper::DrawInfo() {
  const int FONT_SIZE = 20;
  std::string bomb_message = "Bomb Count: ";
  bomb_message += std::to_string(this->board_.GetBombCount());

  std::string flag_message = "Flag Count: ";
  flag_message += std::to_string(this->board_.GetFlagCount());

  std::string timer_text = std::to_string(this->time_elapsed_);
  CutDecimal(timer_text);

  int y_offset = kSTART_FROM_CORNER - FONT_SIZE;
  DrawText(bomb_message.c_str(), kSTART_FROM_CORNER , y_offset, FONT_SIZE, RED);
  DrawText(flag_message.c_str(), kSTART_FROM_CORNER, y_offset - FONT_SIZE, FONT_SIZE, RED);

  int x_midpoint = (kTILE_SIZE * this->board_.GetSizeX() / 2) + kSTART_FROM_CORNER;
  DrawText(timer_text.c_str(), x_midpoint - (timer_text.size() * 5 / 2), y_offset, FONT_SIZE, RED);
}

// Cuts decimals to 2 decimal points
void Sweeper::CutDecimal(std::string& s) {
  size_t pos = s.find(".");
  if (pos != std::string::npos && s.size() > pos + 2) {
    s.resize(pos+3);
  }
}