#pragma once
#ifndef KNIGHT_H // KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : Piece
{
public:
	// Constructor
	Knight(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Knight() override = default;

	void draw(sf::RenderWindow& window) override;

	bool isValidMove(const sf::Vector2f& newPosition) const override;

};

#endif // KNIGHT_H
