#pragma once
#ifndef BOARD_H // BOARD_H
#define BOARD_H // BOARD_H 
#include <SFML/Graphics.hpp>
class Board
{
private:
	static const int BOARD_SIZE = 8; // Board size 8x8
	sf::RectangleShape squares[BOARD_SIZE][BOARD_SIZE]; // Board rectangles
	int squareSize; // 8x8 -> 100px each

public:
	Board(int squareSize);
	void draw(sf::RenderWindow& window);
	// Method to get the closest square's center position based on a given position
	sf::Vector2f getClosestSquareCenter(const sf::Vector2f& position) const;
};



#endif // BOARD_H

