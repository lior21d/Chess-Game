#include "Bishop.h"


// Constructor
Bishop::Bishop(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture) {}

// Overriden draw function
void Bishop::draw(sf::RenderWindow& window)
{
	window.draw(sprite); // Sprite from piece
}

// Overriden isValidMove function
bool Bishop::isValidMove(const sf::Vector2f& newPosition) const
{
	// Need to implement logic for moving
	return true; // Placeholder for now
}