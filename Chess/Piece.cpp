#include "Piece.h"

// Constructor
Piece::Piece(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: color(color), position(position), texture(texture) {
	sprite.setTexture(texture); // Set the texture for the piece
	sprite.setPosition(position); // Set the initial position for the piece

}

// Set the postion of the piece
void Piece::setPosition(const sf::Vector2f& position)
{
	this->position = position;
	sprite.setPosition(position);
}

// Get the position of the piece
sf::Vector2f Piece::getPosition() const {
	return position;
}

// Get the color of the piece
std::string Piece::getColor() const {
	return color;
}