#include "../include/menu.h"

#include "../include/raylib.h"
#include "../include/button.h"
#include "../include/uicontainer.h"

#include <vector>
#include <string>

const std::vector<int> EASY_ARGS = {9, 9, 10};
const std::vector<int> MED_ARGS = {16, 16, 40};
const std::vector<int> HARD_ARGS = {30, 16, 99};

Menu::Menu() {
  Button easy = {80, 100, 600, 75, GREEN};
  easy.AddText("Easy", 20);

  Button med{80, 300, 600, 75, ORANGE};
  med.AddText("Medium", 20);

  Button hard{80, 500, 600, 75, RED};
  hard.AddText("Hard", 20);

  this->uis_.AddUI("easy", new Button(easy));
  this->uis_.AddUI("med", new Button(med));
  this->uis_.AddUI("hard", new Button(hard));

  this->state_ = "menu";
}

Menu::~Menu() {

}

std::vector<int>* Menu::MenuLoop() {
  Inputs();
  Calc();
  Draw();
  return this->state_ == "startGame" ? &this->return_message_ : nullptr;
}

void Menu::Inputs() {
  ClickDifficulty();
}

void Menu::ClickDifficulty() {
  Button* easy = this->uis_.GetUIButton("easy");
  Button* med = this->uis_.GetUIButton("med");
  Button* hard = this->uis_.GetUIButton("hard");
  if (easy->OnClick(MOUSE_BUTTON_LEFT)) {
    this->return_message_ = EASY_ARGS;
  } else if (med->OnClick(MOUSE_BUTTON_LEFT)) {
    this->return_message_ = MED_ARGS;
  } else if (hard->OnClick(MOUSE_BUTTON_LEFT)) {
    this->return_message_ = HARD_ARGS;
  }

  if (!this->return_message_.empty()) {
    this->state_ = "startGame";
  }
}

void Menu::Calc() {

}

void Menu::Draw() {
  BeginDrawing();

  ClearBackground(BLACK);

  this->uis_.DrawAll();

  EndDrawing();
}