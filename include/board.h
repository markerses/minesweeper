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
  void Chord(const int& x, const int& y);
  void FlagTile(const int& x, const int& y);

  int GetSizeX();
  int GetSizeY();
  int GetFlagCount();
  int GetBombCount();
  Tile* GetTile(const int& x, const int& y);

  std::vector<std::vector<Tile*>> ShowBoard();

  private:
  void UpdateSurrounding(int x, int y);
  void WinBoard();
  bool IsValid(const int& x, const int& y);

  int x_size_;
  int y_size_;
  int tiles_;
  int bomb_count_;

  int tiles_left_;
  int flag_count_ = 0;
  bool won_ = false;

  std::vector<std::vector<Tile*>> board_;
};

#endif