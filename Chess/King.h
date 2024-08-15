#pragma once
#ifndef KING_H // KNIGHT_H
#define KING_H


#include "Piece.h"

class King : Piece
{
public:
	// Constructor
	King(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~King() override = default;

	void draw(sf::RenderWindow& window) override;

	bool isValidMove(const sf::Vector2f& newPosition) const override;

};

#endif // KING_H
