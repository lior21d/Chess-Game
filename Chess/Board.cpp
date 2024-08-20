#include "Board.h"

Board::Board(int squareSize)
    : squareSize(squareSize) {

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            squares[row][col].setSize(sf::Vector2f(squareSize, squareSize)); // 100x100px
            squares[row][col].setPosition(col * squareSize, row * squareSize);

            // Color the board
            const sf::Color green = sf::Color(118, 150, 86, 255);
            const sf::Color white = sf::Color(238, 238, 210, 255);
            if ((row + col) % 2 != 0) {
                squares[row][col].setFillColor(green); // Green
            }
            else {
                squares[row][col].setFillColor(white); // White
            }
        }
    }
}

void Board::draw(sf::RenderWindow& window) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            window.draw(squares[row][col]);
        }
    }
}

sf::Vector2f Board::getClosestSquare(const sf::Vector2f& position) const {

    int col = static_cast<int>(position.x / squareSize);
    int row = static_cast<int>(position.y / squareSize);

    // Calculate the top-left corner of the square
    float xCorner = static_cast<float>(col) * squareSize;
    float yCorner = static_cast<float>(row) * squareSize;

    return sf::Vector2f(xCorner, yCorner);
    
}

