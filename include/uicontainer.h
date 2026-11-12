#ifndef M_UICONTAIN_H
#define M_UICONTAIN_H

#include "button.h"

#include <vector>

class UIContainer {
  UIContainer();
  ~UIContainer();

  void AddUI(Button* button);
  void UpdateUI(Button* button);

  void DrawAll();

  std::vector<Button*> buttons_;
};

#endif