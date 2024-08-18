#pragma once
#ifndef ROOK_H // ROOK_H
#define ROOK_H // ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
	// Constructor
	Rook(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Rook() override = default;

	void draw(sf::RenderWindow& window) override;

	bool isValidMove(const sf::Vector2f& newPosition) const override;


};

#endif // ROOK_H
