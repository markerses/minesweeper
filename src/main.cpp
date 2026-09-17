#include "../include/board.h"
#include "../include/raylib.h"
#include "../include/functions.h"

#include <iostream>
#include <string>

// Define Graphics

const int TILE_SIZE = 30;
const int TILE_SPACING = 30;

//

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

    if (IsKeyPressed(KEY_SPACE)) {
      test_board.ResetBoard();
    }

    BeginDrawing();

    ClearBackground(BLACK);
    DrawRectangle(180, 180, 475, 475, GRAY);

    DrawBoard(test_board, TILE_SIZE, TILE_SPACING);


    EndDrawing();
  }


  CloseWindow();
  return 0;
}
