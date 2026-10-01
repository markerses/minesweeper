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

        if (t->IsVisible() && tile_num > 0)
          DrawText(std::to_string(tile_num).c_str(), x_pos + 10, y_pos + 6, 20, BLACK);
      }
    }

}

std::pair<int, int> find_click(Board& b, const int& size, const int& init_x, const int& init_y) {
  int x = (GetMouseX() - init_x) / size;
  int y = (GetMouseY() - init_y) / size;
  std::cout << "mouse clicked: " << x << ", " << y << "\n";
  return {x, y};
}