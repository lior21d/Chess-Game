#pragma once
#ifndef KING_H // KNIGHT_H
#define KING_H


#include "Piece.h"
#include "Board.h"

class King : public Piece
{
public:
	bool hasMoved;
	// Constructor
	King(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~King() override = default;

	void draw(sf::RenderWindow& window) override;

	void getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves) override;

	void setHasMoved(bool flag);
};

#endif // KING_H
#pragma once
