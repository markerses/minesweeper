#ifndef M_FUNCS_H
#define M_FUNCS_H

#include "board.h"

#include <utility>

void DrawBoard(Board& b, const int& size, const int& spacing, const int& init_x, const int& init_y);

void DrawFlagCount(Board& b, const int& x, const int& y, const int& font_size);

std::pair<int, int> find_click(Board& b, const int& size, const int& init_x, const int& init_y);

#endif