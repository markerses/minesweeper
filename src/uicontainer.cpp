#include "../include/uicontainer.h"

#include "../include/button.h"

#include <vector>

UIContainer::UIContainer() {

}

UIContainer::~UIContainer() {

}

void UIContainer::AddUI(const std::string& name, Button* button) {
  this->buttons_.insert({name, button});
}

void UIContainer::UpdateUI(const std::string& name, Button* button) {
  if (this->buttons_.find(name) != this->buttons_.end()) {
    this->buttons_[name] = button;
  }
}

Button* UIContainer::GetUIButton(const std::string& name) {
  return this->buttons_.find(name)->second;
}

void UIContainer::DrawAll() {
  for (auto i = this->buttons_.begin() ; i != this->buttons_.end(); i++) {
    i->second->Draw();
  }
}