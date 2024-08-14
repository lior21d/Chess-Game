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

};



#endif // BOARD_H

