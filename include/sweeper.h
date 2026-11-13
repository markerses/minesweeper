#ifndef M_SWEEP_H
#define M_SWEEP_H

#include "board.h"

#include <string>

class Sweeper {
  public:
    Sweeper(const int& x, const int& y, const int& bombs);
    ~Sweeper();
    void SweepLoop();

    const int kSTART_FROM_CORNER = 50;
    const int kTILE_SIZE = 30;

  private:
    void Inputs();

    void MouseInputs();

    std::pair<int, int> MouseToTile(const int& x, const int& y);

    void Calc();

    void StartTimer();

    void UpdateTime();

    void StopTime();

    void Draw();

    void DrawBoard();

    void DrawInfo();

    void CutDecimal(std::string& s);

    Board board_;
    double start_time_;
    double time_elapsed_;
    std::string state_;
};

#endif