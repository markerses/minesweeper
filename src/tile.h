#ifndef M_TILE_H
#define M_TILE_H

class Tile {
  public:
  Tile();
  Tile(int c);

  void Activate();
  void Update(int c);
  int TileNumber();

  private:
  int num_ = 0;
  bool vis_ = false;

};

#endif