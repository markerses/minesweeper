#ifndef M_TILE_H
#define M_TILE_H

class Tile {
  public:
  Tile();
  Tile(int c);

  void Activate();
  void Update(int c);

  private:
  int num = 0;
  bool vis_ = false;

};

#endif