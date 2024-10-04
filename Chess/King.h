#pragma once
#ifndef KING_H // KNIGHT_H
#define KING_H


#include "Piece.h"
#include "Board.h"

class King : public Piece
{
public:
	// Constructor
	King(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~King() override = default;

	void draw(sf::RenderWindow& window) override;

	std::vector<sf::Vector2f> getPossibleMoves(Board& board, const std::vector<Piece*>& pieces) override;

};

#endif // KING_H
