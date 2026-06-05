#include "../include/tile.h"

Tile::Tile() {

}

Tile::Tile(int c) {
  this->num_ = c;
}

void Tile::Activate() {
  this->vis_ = true;
}

// Updates tile number by one, or sets to bomb when inputing -1
// Clears when inputing -2
void Tile::Update(int c) {
  if (c == -1) {
    this->num_ = c;
  } else if (c == -2) {
    this->num_ = 0;
  } else if (this->num_ != -1)
    this->num_++;
}

int Tile::TileNumber() {
  return this->num_;
}
