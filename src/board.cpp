#include "board.h"

Board::Board(int x, int y, int bombs) {
  this->x_size_ = x;
  this->y_size_ = y;

  this->board_.reserve(x);
  for (size_t i = 0; i < x; i++) {
    std::vector<Tile*> v;
    v.reserve(y);
    for (size_t j = 0; j < y; j++) {
      v.push_back(new Tile());
    }
    this->board_.push_back(v);
  }
}

Board::~Board() {
  for (size_t i = 0; i < this->x_size_; i++) {
    for (size_t j = 0; j < this->y_size_; j++) {
      delete this->board_[i][j];
    }
  }
}