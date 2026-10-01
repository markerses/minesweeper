#include "../include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"

#include "../include/board.h"
#include "../include/functions.h"

#include <iostream>
#include <string>

// Define Graphics

const int TILE_SIZE = 30;
const int TILE_SPACING = 29;

const int BOARD_START_X = 180;
const int BOARD_START_Y = 180;

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

    // Mouse clicks
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Tile* tile_clicked = find_click(test_board, TILE_SIZE, BOARD_START_X, BOARD_START_Y);
      if (tile_clicked != nullptr) {
        tile_clicked->Activate();

        if (tile_clicked->TileNumber() == -1) {
          test_board.RevealBoard();
        }
      }
    }

    BeginDrawing();

    ClearBackground(BLACK);

    DrawBoard(test_board, TILE_SIZE, TILE_SPACING, BOARD_START_X, BOARD_START_Y);


    EndDrawing();
  }


  CloseWindow();
  return 0;
}
