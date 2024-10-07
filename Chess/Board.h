#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


class Board {
public:
    Board(int squareSize);
    void draw(sf::RenderWindow& window);

    // Method to get the help snapping
    sf::Vector2f getClosestSquare(const sf::Vector2f& position) const;

    // Methods to help game logic
    bool isOpponentPiece(const sf::Vector2f& position, const std::vector<Piece*>& pieces, const std::string& color);
    bool isEmptySquare(const std::vector<Piece*>& pieces, const sf::Vector2f& position);
    bool isWithinBounds(const sf::Vector2f& position) const;
    Piece* getPieceAtPosition(const sf::Vector2f& position, const std::vector<Piece*>& pieces);
    bool isValidMove(const std::vector<sf::Vector2f>& possibleMoves, const sf::Vector2f& newPosition);
    void showAvailableSquares(const std::vector<sf::Vector2f>& possibleMoves);
    void colorSquares();
private:
    static const int BOARD_SIZE = 8;
    int squareSize;
    sf::RectangleShape squares[BOARD_SIZE][BOARD_SIZE];
    
};

#endif // BOARD_H

