#include "../include/sweeper.h"

#include "../include/raylib.h"
#include "../include/board.h"

#include <iostream>
#include <string>

Sweeper::Sweeper(const int& x, const int& y, const int& bombs) : board_{x, y, bombs} {
  
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
  }

  this->MouseInputs();
}

void Sweeper::MouseInputs() {
  auto [x, y] = MouseToTile(GetMouseX(), GetMouseY());

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    this->board_.OnClick(x, y);
  } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
    this->board_.FlagTile(x, y);
  }
}

std::pair<int, int> Sweeper::MouseToTile(const int& x, const int& y) {
  int new_x = (x - kSTART_FROM_CORNER) / kTILE_SIZE;
  int new_y = (y - kSTART_FROM_CORNER) / kTILE_SIZE;
  return {new_x, new_y};
}

void Sweeper::Calc() {

}

void Sweeper::Draw() {
  BeginDrawing();

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

  DrawText(bomb_message.c_str(), kSTART_FROM_CORNER , kSTART_FROM_CORNER, FONT_SIZE, RED);
  DrawText(flag_message.c_str(), kSTART_FROM_CORNER, kSTART_FROM_CORNER + FONT_SIZE, FONT_SIZE, RED);
}