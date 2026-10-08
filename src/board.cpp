#include "../include/board.h"


#include <iostream>
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

// Initialize Functions

// Generates board of size x, y, with specified bomb count
Board::Board(int x, int y, int bombs) {
  this->x_size_ = x;
  this->y_size_ = y;

  this->bomb_count_ = bombs;
  this->tiles_ = x * y;
  this->tiles_left_ = this->tiles_ - bombs;

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

const int MOVES = 8;
static const int ADJACENT[8][2] = {
  {-1, 1},  {0, 1},  {1, 1},
  {-1, 0},           {1, 0},
  {-1, -1}, {0, -1}, {1, -1}
};

// Private Methods

// Private method that updates the number count of tiles surrounding a new bomb
void Board::UpdateSurrounding(int x, int y) {
  for (int i = 0; i < MOVES; i++) {
    int move[2] = {ADJACENT[i][0], ADJACENT[i][1]};
    int new_x = x + move[0];
    int new_y = y + move[1];
    if ((new_x >= 0 && new_x < this->x_size_) &&
        (new_y >= 0 && new_y < this->x_size_)) {
          
      Tile* eval = this->board_[new_x][new_y];
      eval->Update(0);  
    }
  }
}

// Private method that handles winning
void Board::WinBoard() {
  this->won_ = true;
  this->RevealBoard();
  std::cout << "Game Won!\n";
}

// Public Methods

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

// Resets board and generates new one
void Board::ResetBoard() {
  this->won_ = false;
  this->tiles_left_ = this->tiles_ - this->bomb_count_;
  this->flag_count_ = 0;

  for (size_t i = 0; i < this->x_size_; i++) { 
    for (size_t j = 0; j < this->y_size_; j++) {
      this->board_[i][j]->Update(-2);
    }
  }
  this->GenerateBoard();
}

// Reveals entire board
void Board::RevealBoard() {
  for (size_t i = 0; i < this->x_size_; i++) {
    for (size_t j = 0; j < this->y_size_; j++) {
      this->board_[i][j]->Activate();
    }
  }
}

// Reveals Tile with at board coordinates (x, y) 
void Board::RevealTile(const int& x, const int& y) {
  if (x < 0 || x >= this->x_size_ || 
    y < 0 || y >= this->y_size_)
    return;
  Tile* t = this->board_[x][y];

    if (t->IsFlagged() || t->IsVisible())
    return;

  std::cout << "revealing " << x << ", " << y << "\n";
  t->Activate();
  this->tiles_left_--;
  std::cout << "tiles left: " << this->tiles_left_ << "\n";

  if (tiles_left_ == 0)
    this->WinBoard();

  if (t->TileNumber() == 0) {
    for (int i = 0; i < MOVES; i++) {
      this->RevealTile(x + ADJACENT[i][0], y + ADJACENT[i][1]);
    }
  } else if (t->TileNumber() == -1) {
    this->RevealBoard();
  }
}

void Board::FlagTile(const int& x, const int& y) {
  if (x < 0 || x >= this->x_size_ || 
    y < 0 || y >= this->y_size_)
    return;

  Tile* t = this->board_[x][y];
  if (t->IsVisible())
    return;
  
  std::cout << "flagging " << x << ", " << y << "\n";
  this->flag_count_+= t->Flag() ? 1 : -1 ;
  std::cout << "Flags: " << this->flag_count_ << "\n"; 
}

// Returns board's x size
int Board::GetSizeX() {return x_size_;}

// Returns board's y size
int Board::GetSizeY() {return x_size_;}

// Returns Tile pointer
Tile* Board::GetTile(const int& x, const int& y) {
  if ((x >= 0 && x < this->x_size_) && (y >= 0 && y < this->y_size_)) {
    return this->board_[x][y];
  }
  return nullptr;
}

// Returns interal board
std::vector<std::vector<Tile*>> Board::ShowBoard() {
  return this->board_;
}