
#pragma once
#ifndef PAWN_H // PAWN_H
#define PAWH_H // PAWN_H

#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{
public:
	// Constructor
	Pawn(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);

	// Destructor
	~Pawn() override = default;

	void draw(sf::RenderWindow& window) override;

	void getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves) override;
	
	bool getFirstMove();
	void setFirstMove(bool flag);
private:
	bool firstMove;
};


#endif // PAWN_H


