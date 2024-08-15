 #include "Pawn.h"

// Constructor
Pawn::Pawn(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture) {}

// Overriden draw function
void Pawn::draw(sf::RenderWindow& window)
{
	window.draw(sprite); // Sprite from Piece
}

// Overriden isValidMove function
bool Pawn::isValidMove(const sf::Vector2f& newPosition) const 
{
	// Need to implement logic for moving
	return true; // Placeholder for now
}