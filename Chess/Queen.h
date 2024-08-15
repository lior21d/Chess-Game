#pragma once
#ifndef QUEEN_H // QUEEN_H
#define QUEEN_H // QUEEN_H

#include "Piece.h"

class Queen : Piece
{
public:
	// Constructor
	Queen(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Queen() override = default;

	void draw(sf::RenderWindow& window) override;

	bool isValidMove(const sf::Vector2f& newPosition) const override;

};

#endif // KNIGHT_H
