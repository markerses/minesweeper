#ifndef M_MENU_H
#define M_MENU_H

#include "uicontainer.h"
#include "button.h"

#include <vector>
#include <string>

class Menu {
  public:
    Menu();
    ~Menu();

    std::vector<int>* MenuLoop();

  private:
    void Inputs();

    void ClickDifficulty();

    void Calc();
    void Draw();

    UIContainer uis_;
    std::string state_;
    std::vector<int> return_message_;
};

#endif
