#pragma once
#ifndef PAWN_H // PAWN_H
#define PAWH_H // PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
public:
	// Constructor
	Pawn(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Pawn() override = default;

	void draw(sf::RenderWindow& window) override;
	
	bool isValidMove(const sf::Vector2f& newPosition) const override;
	
};


#endif // PAWN_H


