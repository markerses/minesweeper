#ifndef M_GAME_H
#define M_GAME_H

#include "sweeper.h"
#include "menu.h"

#include <string>

class Game {
  public:
  Game();
  ~Game();
  
  private:
  void Run();

  void InitSweep(std::vector<int> args);

  std::string state_;
  Sweeper* s_;
  Menu* m_;
  

};






#endif