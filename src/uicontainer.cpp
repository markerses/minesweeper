#include "../include/uicontainer.h"

#include "../include/button.h"

#include <vector>

UIContainer::UIContainer() {

}

UIContainer::~UIContainer() {

}

void UIContainer::AddUI(Button* button) {
  this->buttons_.push_back(button);
}

void UIContainer::UpdateUI(Button* old, Button* new_button ) {
  for (auto i = this->buttons_.begin(); i != this->buttons_.end(); i++) {
    if (*i == old) {
      this->buttons_.erase(i);
      this->buttons_.push_back(new_button);
    }
  }
}

void UIContainer::DrawAll() {
  for (size_t i = 0 ; i < this->buttons_.size(); i++) {
    this->buttons_[i]->Draw();
  }
}