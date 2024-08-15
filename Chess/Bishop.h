#pragma once
#ifndef BISHOP_H // BISHOP_H
#define BISHOP_H // BISHOP_H

#include "Piece.h"

class Bishop : Piece
{
	// Constructor 
	Bishop(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Bishop() override = default;

	void draw(sf::RenderWindow& window) override;

	bool isValidMove(const sf::Vector2f& newPosition) const override;

};

#endif // BISHOP_H