#include <SFML/Graphics.hpp>
#include "window.h"
#include "Board.h"

int main() {
    // Create a window object
    Window* gameWindow = new Window("Chess Game", 800, 800);
    gameWindow->create();

    // Create a board with each square being 100x100px
    Board* chessBoard = new Board(100);
    
    // Main loop
    while (gameWindow->isOpen()) {
        // Handle events
        gameWindow->handleEvents();

        // Clear the window
        gameWindow->clear();

        // Draw  game here (pieces, board, etc.)

        chessBoard->draw(gameWindow->getRenderWindow());

        // Display the window
        gameWindow->display();
    }

    return 0;
}