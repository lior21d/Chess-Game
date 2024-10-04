#pragma once
#ifndef KNIGHT_H // KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Board.h"

class Knight : public Piece
{
public:
	// Constructor
	Knight(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Knight() override = default;

	void draw(sf::RenderWindow& window) override;

	std::vector<sf::Vector2f> getPossibleMoves(Board& board, const std::vector<Piece*>& pieces) override;

};

#endif // KNIGHT_H
