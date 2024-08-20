#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>

class Board {
public:
    Board(int squareSize);
    void draw(sf::RenderWindow& window);

    // Method to get the help snapping
    sf::Vector2f getClosestSquare(const sf::Vector2f& position) const;

private:
    static const int BOARD_SIZE = 8;
    int squareSize;
    sf::RectangleShape squares[BOARD_SIZE][BOARD_SIZE];
};

#endif // BOARD_H
