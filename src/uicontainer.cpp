#include "../include/uicontainer.h"

#include "../include/button.h"

#include <string>
#include <unordered_map>
#include <utility>

UIContainer::UIContainer() {

}

UIContainer::~UIContainer() {
  for (auto pair : this->buttons_) {
    delete pair.second;
  }
}

void UIContainer::AddUI(const std::string& name, Button* button) {
  this->buttons_.insert_or_assign(name, button);
}

Button* UIContainer::GetUIButton(const std::string& name) {
  if (this->buttons_.find(name) != this->buttons_.end())
    return this->buttons_.at(name);
  return nullptr;
}

void UIContainer::DrawAll() {
  for (auto pair : this->buttons_) { 
    pair.second->Draw();
  }
}