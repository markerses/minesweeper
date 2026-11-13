#include "../include/button.h"
#include "../include/raylib.h"

#include <string>

Button::Button(const int& x, const int& y, const int& w, const int& h, const Color& color) :
    x_{x}, y_{y}, w_{w}, h_{h}, color_{color} {

}

bool Button::OnClick(int button) {
  return IsMouseButtonPressed(button) && this->MouseIntersects();
}

bool Button::OnRelease(int button) {
  return IsMouseButtonReleased(button) && this->MouseIntersects();
}

bool Button::Held(int button) {
  return IsMouseButtonDown(button) && this->MouseIntersects();
}

void Button::AddText(const std::string& text, int text_size) {
  this->text_ = text;
  this->text_size_ = text_size;
}

bool Button::MouseIntersects() {
  return (this->x_ <= GetMouseX() && GetMouseX() <= (this->x_ + this->w_) &&
          this->y_ <= GetMouseY() && GetMouseY() <= (this->y_ + this->h_));
}

void Button::Draw() {
  DrawRectangle(this->x_, this->y_, this->w_, this->h_, this->color_);
  if (this->text_.size() > 0) {
    int x_centered = this->x_ + (this->w_ / 2) - ((this->text_.size() / 2) * (this->text_size_ * 0.6));
    int y_centered = this->y_ + (this->h_ / 2) - (this->text_size_ / 2);
    DrawText(this->text_.c_str(), x_centered, y_centered, this->text_size_, BLACK);
  }
}