#include "../include/functions.h"

#include "../include/raylib.h"
#include "../include/raygui.h"

#include "../include/board.h"

#include <iostream>
#include <string>

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
        int x_pos = SPACE_FROM_EDGE + init_x + (i * spacing);
        int y_pos = SPACE_FROM_EDGE + init_y + (j * spacing);

        Rectangle rec = Rectangle();
        rec.x = x_pos;
        rec.y = y_pos;
        rec.height = size;
        rec.width = size;

        int tile_num = b.ShowBoard()[i][j]->TileNumber();
        Color col = (tile_num == -1) ? RED:GREEN;
        
        // GuiButton(rec, std::to_string(tile_num).c_str());
        // GuiLabelButton(rec, std::to_string(tile_num).c_str());

        DrawRectangle(x_pos - 8, y_pos - 6, size, size, col);
        if (tile_num != 0)
          DrawText(std::to_string(tile_num).c_str(), x_pos, y_pos, 20, BLACK);
      }
    }

}

Tile* find_click(Board& b, const int& size, const int& init_x, const int& init_y) {
  int x = (GetMouseX() - init_x) / size;
  int y = (GetMouseY() - init_y) / size;
  std::cout << "mouse clicked: " << x << ", " << y << "\n";

  if ((x >= 0 && x < b.GetSizeX()) && (y >= 0 && y < b.GetSizeY())) {
    return b.ShowBoard()[x][y];
  }
  return nullptr;
}