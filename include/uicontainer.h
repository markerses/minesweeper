#ifndef M_UICONTAIN_H
#define M_UICONTAIN_H

#include "button.h"

#include <unordered_map>
#include <string>

class UIContainer {
  public:
    UIContainer();
    ~UIContainer();

    void AddUI(const std::string& name, Button* button);
    void UpdateUI(const std::string& name, Button* button);

    void DrawAll();
    
  private:
   std::unordered_map<std::string, Button*> buttons_;
};

#endif