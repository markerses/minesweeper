#ifndef M_SWEEP_H
#define M_SWEEP_H

#include "board.h"

class Sweeper {
  public:
  Sweeper(const int& x, const int& y, const int& bombs);
  ~Sweeper();
  void SweepLoop();

  private:
  void Inputs();

  void MouseInputs();

  std::pair<int, int> MouseToTile(const int& x, const int& y);

  void Calc();
  void Draw();

  void DrawBoard();

  void DrawInfo();

  const int kSTART_FROM_CORNER = 50;
  const int kTILE_SIZE = 30;
  Board board_;
};

#endif