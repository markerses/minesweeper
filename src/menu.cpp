#include "../include/menu.h"

#include "../include/raylib.h"
#include "../include/button.h"
#include "../include/uicontainer.h"

const std::vector<int> EASY_ARGS = {15, 15, 10};

Menu::Menu() : easy_button_{100, 100, 200, 200, GREEN} {
  this->easy_button_.AddText("Easy", 20);
  this->uis_.AddUI(&this->easy_button_);
  this->state_ = "menu";
}

Menu::~Menu() {

}

std::vector<int>* Menu::MenuLoop() {
  Inputs();
  Calc();
  Draw();
  return this->state_ == "startGame" ? &return_message : nullptr;
}

void Menu::Inputs() {
  if (this->easy_button_.OnClick(MOUSE_BUTTON_LEFT)) {
    this->state_ = "startGame";
    this->return_message = EASY_ARGS;
  }
}

void Menu::Draw() {
  uis_.DrawAll();
}