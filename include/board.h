#ifndef M_BOARD_H
#define M_BOARD_H

#include "tile.h"
#include <vector>

class Board{
  public:
  Board(int x, int y, int bombs);
  ~Board();

  void GenerateBoard();
  void ResetBoard();
  void RevealBoard();
  void RevealTile(const int& x, const int& y);
  void FlagTile(const int& x, const int& y);

  int GetSizeX();
  int GetSizeY();
  Tile* GetTile(const int& x, const int& y);

  std::vector<std::vector<Tile*>> ShowBoard();

  private:
  void UpdateSurrounding(int x, int y);
  int x_size_;
  int y_size_;
  int bomb_count_;

  std::vector<std::vector<Tile*>> board_;
};

#endif