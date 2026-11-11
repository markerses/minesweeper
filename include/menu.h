#ifndef M_MENU_H
#define M_MENU_H

class Menu {
  public:
    Menu();
    ~Menu();

    void MenuLoop();

  private:
    void Inputs();
    void Calc();
    void Draw();
};

#endif
