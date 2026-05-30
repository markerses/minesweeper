#ifndef M_BOARD_H
#define M_BOARD_H

#include "tile.h"
#include <vector>

class Board{
  public:
  Board(int x, int y, int bombs);
  ~Board();

  void GenerateBoard();

  private:
  int x_size_;
  int y_size_;
  int bomb_count_;

  std::vector<std::vector<Tile*>> board_;
};

#endif