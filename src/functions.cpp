#include "../include/functions.h"
#include "../include/raylib.h"
#include "../include/board.h"

#include <string>

void DrawBoard(Board& b, const int& size, const int& spacing) {
  for (size_t i = 0; i < b.GetSizeX(); i++) {
      for (size_t j = 0; j < b.GetSizeY(); j++) {
        int x_pos = 200 + (i * spacing);
        int y_pos = 200 + (j * spacing);
        int tile_num = b.ShowBoard()[i][j]->TileNumber();
        Color col = (tile_num == -1) ? RED:GREEN;

        DrawRectangle(x_pos - 8, y_pos - 6, size, size, col);
        DrawText(std::to_string(tile_num).c_str(), x_pos, y_pos, 20, BLACK);
      }
    }

}