#pragma once
#ifndef QUEEN_H // QUEEN_H
#define QUEEN_H // QUEEN_H

#include "Piece.h"
#include "Board.h"

class Queen : public Piece
{
public:
	// Constructor
	Queen(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Queen() override = default;

	void draw(sf::RenderWindow& window) override;

	void getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves) override;
};

#endif // KNIGHT_H
