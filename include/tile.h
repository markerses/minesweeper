#ifndef M_TILE_H
#define M_TILE_H

class Tile {
  public:
  Tile();
  Tile(int c);

  void Activate();
  void Update(int c);
  void Flag();
  int TileNumber();
  bool IsVisible();
  bool IsFlagged();

  private:
  int num_ = 0;
  bool vis_ = false;
  bool flagged_ = false;

};

#endif