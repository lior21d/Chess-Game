#pragma once
#ifndef BISHOP_H // BISHOP_H
#define BISHOP_H // BISHOP_H

#include "Piece.h"
#include "Board.h"

class Bishop : public Piece
{
public:
	// Constructor
	Bishop(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Bishop() override = default;

	void draw(sf::RenderWindow& window) override;

	void getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves) override;
};


#endif // BISHOP_H


