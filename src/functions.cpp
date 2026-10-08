#include "../include/functions.h"

#include "../include/raylib.h"
#include "../include/raygui.h"

#include "../include/board.h"

#include <iostream>
#include <string>
#include <memory>

void DrawBoard(Board& b, const int& size, const int& spacing, const int& init_x, const int& init_y) {
  const int SPACE_FROM_EDGE = 20;

  // DrawRectangle(
  //   init_x, 
  //   init_y, 
  //   b.GetSizeX() * size + (SPACE_FROM_EDGE * 0), 
  //   b.GetSizeY() * size + (SPACE_FROM_EDGE * 0), 
  //   GRAY);

  for (size_t i = 0; i < b.GetSizeX(); i++) {
      for (size_t j = 0; j < b.GetSizeY(); j++) {
        int x_pos = init_x + (i * size);
        int y_pos = init_y + (j * size);

        // Rectangle rec = Rectangle();
        // rec.x = x_pos;
        // rec.y = y_pos;
        // rec.height = size;
        // rec.width = size;

        Tile* t = b.GetTile(i, j);
        int tile_num = t->TileNumber();
        Color col;

        if (t->IsVisible()) {
          col = (tile_num == -1) ? RED:GREEN;
        } else {
          col = GRAY;
        }
        // GuiButton(rec, std::to_string(tile_num).c_str());
        // GuiLabelButton(rec, std::to_string(tile_num).c_str());

        DrawRectangle(x_pos, y_pos, size, size, col);

        if (t->IsVisible() && tile_num > 0) {
          DrawText(std::to_string(tile_num).c_str(), x_pos + 10, y_pos + 6, 20, BLACK);
        } else if (t->IsFlagged()) {
          DrawText(std::string("F").c_str(), x_pos + 10, y_pos + 6, 20, BLACK); // Might memory leak...
        }
      }
    }

}

// Draws Flag and Bomb count
void DrawFlagCount(Board& b, const int& x, const int& y, const int& font_size) {
  std::string bomb_message = "Bomb Count: ";
  bomb_message += std::to_string(b.GetBombCount());

  std::string flag_message = "Flag Count: ";
  flag_message += std::to_string(b.GetFlagCount());

  DrawText(bomb_message.c_str(), x, y, font_size, RED);
  DrawText(flag_message.c_str(), x, y + font_size, font_size, RED);
}

std::pair<int, int> find_click(Board& b, const int& size, const int& init_x, const int& init_y) {
  int x = (GetMouseX() - init_x) / size;
  int y = (GetMouseY() - init_y) / size;
  std::cout << "mouse clicked: " << x << ", " << y << "\n";
  return {x, y};
}