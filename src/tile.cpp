#include "tile.h"

Tile::Tile() {

}

Tile::Tile(int c) {
  this->num = c;
}

void Tile::Activate() {
  this->vis_ = true;
}

void Tile::Update(int c) {
  this->num = c;
}
