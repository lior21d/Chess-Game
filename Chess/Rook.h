#pragma once
#ifndef ROOK_H // ROOK_H
#define ROOK_H // ROOK_H

#include "Piece.h"
#include "Board.h"

class Rook : public Piece
{
public:
	// Constructor
	Rook(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Rook() override = default;

	void draw(sf::RenderWindow& window) override;

	std::vector<sf::Vector2f> getPossibleMoves(Board& board, const std::vector<Piece*>& pieces) override;

};

#endif // ROOK_H
