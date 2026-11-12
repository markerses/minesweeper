#ifndef M_UICONTAIN_H
#define M_UICONTAIN_H

#include "button.h"

#include <vector>

class UIContainer {
  public:
    UIContainer();
    ~UIContainer();

    void AddUI(Button* button);
    void UpdateUI(Button* old, Button* new_button);

    void DrawAll();
    
  private:
   std::vector<Button*> buttons_;
};

#endif