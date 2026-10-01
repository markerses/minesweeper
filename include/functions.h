#ifndef M_FUNCS_H
#define M_FUNCS_H

#include "board.h"

void DrawBoard(Board& b, const int& size, const int& spacing, const int& init_x, const int& init_y);

Tile* find_click(Board& b, const int& size, const int& init_x, const int& init_y);

#endif