#include "../include/board.h"
#include "../include/raylib.h"

#include <iostream>

int main() {
  const int X_BOARD = 15;
  const int Y_BOARD = 15;
  const int BOMBS = 30;
  Board test_board(X_BOARD, Y_BOARD, BOMBS);

  InitWindow(800, 800, "Markerses Minesweeper");

  /* Terminal Testing
  while (true) {
    std::cout << "Generated Board:\n\n";
    for (size_t i = 0; i < X_BOARD; i++) {
      for (size_t j = 0; j < Y_BOARD; j++) {
        std::cout << test_board.ShowBoard()[i][j]->TileNumber() << " ";
      }
      std::cout << '\n';
    }   

    std::cout << "Enter to generate new, (q to quit)...\n";
    char input;
    std::cin >> input;
    if (input == 'q') {
      break;
    } else {
      test_board.ResetBoard();
    }
  }
  */

  while (!WindowShouldClose()) {
    BeginDrawing();

    EndDrawing();
  }


  CloseWindow();
  return 0;
}
