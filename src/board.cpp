#include "../include/board.h"

#include <vector>
#include <random>
#include <utility>

std::pair<int, int> generate_rand_pos(int x_range, int y_range) {
  std::random_device seed;
  std::mt19937 rng(seed());
  std::uniform_int_distribution<::std::mt19937::result_type> x_res(0, x_range - 1);
  std::uniform_int_distribution<::std::mt19937::result_type> y_res(0, y_range - 1);

  return {x_res(rng), y_res(rng)};
}

// Generates board of size x, y, with specified bomb count
Board::Board(int x, int y, int bombs) {
  this->x_size_ = x;
  this->y_size_ = y;

  this->bomb_count_ = bombs;

  this->board_.reserve(x);
  for (size_t i = 0; i < x; i++) {
    std::vector<Tile*> v;
    v.reserve(y);
    for (size_t j = 0; j < y; j++) {
      v.push_back(new Tile());
    }
    this->board_.push_back(v);
  }

  this->GenerateBoard();
}

// clears board, frees pointers
Board::~Board() {
  for (size_t i = 0; i < this->x_size_; i++) {
    for (size_t j = 0; j < this->y_size_; j++) {
      delete this->board_[i][j];
    }
  }
}

// Private method that updates the number count of tiles surrounding a new bomb
void Board::UpdateSurrounding(int x, int y) {
  static const int moves[8][2] = {
    {-1, 1},  {0, 1},  {1, 1},
    {-1, 0},           {1, 0},
    {-1, -1}, {0, -1}, {1, -1}
  };

  for (int i = 0; i < 8; i++) {
    int move[2] = {moves[i][0], moves[i][1]};
    int new_x = x + move[0];
    int new_y = y + move[1];
    if ((new_x >= 0 && new_x < this->x_size_) &&
        (new_y >= 0 && new_y < this->x_size_)) {
          
      Tile* eval = this->board_[new_x][new_y];
      eval->Update(0);  
    }
  }
}

// Generates a board with randomly placed bombs
void Board::GenerateBoard() {
  int i = 0;
  while (i < this->bomb_count_) {
    std::pair<int, int> res = generate_rand_pos(this->x_size_, this->y_size_);
    Tile* eval = this->board_[res.first][res.second];
    if (eval->TileNumber() != -1) {
      eval->Update(-1);
      this->UpdateSurrounding(res.first, res.second);
      i++;
    }
  }
}

// Resets board and generated new one
void Board::ResetBoard() {
  for (size_t i = 0; i < this->x_size_; i++) { 
    for (size_t j = 0; j < this->y_size_; j++) {
      this->board_[i][j]->Update(-2);
    }
  }
  this->GenerateBoard();
}

// Returns interal board
std::vector<std::vector<Tile*>> Board::ShowBoard() {
  return this->board_;
}