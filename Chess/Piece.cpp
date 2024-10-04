#include "Piece.h"
#include <iostream>

// Constructor
Piece::Piece(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: color(color), position(position), texture(texture) {
	sprite.setTexture(texture);
	sprite.setPosition(position);

	// Set the sprite to be 100x100
	sf::Vector2u textureSize = texture.getSize();
	float scaleFactor = 100.0f / textureSize.x;

	sprite.setScale(scaleFactor, scaleFactor);

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

const sf::Sprite& Piece::getSprite() const
{
	return sprite;
}

std::vector<sf::Vector2f> Piece::getPossibleMoves(Board& board, const std::vector<Piece*>& pieces) {
	return {}; // Empty vector for default behavior
}