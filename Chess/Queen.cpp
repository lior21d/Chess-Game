#include "Queen.h"


// Constructor
Queen::Queen(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture) {}

// Overriden draw function
void Queen::draw(sf::RenderWindow& window)
{
	window.draw(sprite); // Sprite from piece
}

// Overriden isValidMove function
bool Queen::isValidMove(const sf::Vector2f& newPosition) const
{
	// Need to implement logic for moving
	return true; // Placeholder for now
}