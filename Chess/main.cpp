#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Window.h"
#include "TextureManager.h"
#include "PieceGenerator.h"

int main() {
    // Create a window object
    Window* gameWindow = new Window("Chess Game", 800, 800);
    gameWindow->create();

    // Create a board with each square being 100x100px
    Board* chessBoard = new Board(100);

    // Create a TextureManager and load all of the textures

    TextureManager* textureManager = new TextureManager();
    textureManager->loadAllTextures();

    // Create all chess pieces

    std::vector<Piece*> pieces = createAllPieces(textureManager);

    // Main loop
    while (gameWindow->isOpen()) {
        // Handle events
        //gameWindow->handleEvents(pieces, *(chessBoard));

        // Clear the window
        gameWindow->clear();

        // Draw the board
        chessBoard->draw(gameWindow->getRenderWindow());

        // Draw the pieces
        for (Piece* piece : pieces) {
            piece->draw(gameWindow->getRenderWindow());
        }
        

        // Display the window
        gameWindow->display();
    }


    // Free memory
    delete gameWindow;
    delete chessBoard;
    delete textureManager;
    for (Piece* piece : pieces) {
        delete piece;
    }


    return 0;
}