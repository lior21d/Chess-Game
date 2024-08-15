#include "Rook.h"


#include "Knight.h"


// Constructor
Rook::Rook(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture) {}

// Overriden draw function
void Rook::draw(sf::RenderWindow& window)
{
	window.draw(sprite); // Sprite from piece
}

// Overriden isValidMove function
bool Rook::isValidMove(const sf::Vector2f& newPosition) const
{
	// Need to implement logic for moving
	return true; // Placeholder for now
}