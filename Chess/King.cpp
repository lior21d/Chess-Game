#include "King.h"


// Constructor
King::King(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture) {}

// Overriden draw function
void King::draw(sf::RenderWindow& window)
{
	window.draw(sprite); // Sprite from piece
}

void King::getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves)
{
	possibleMoves.clear();
	sf::Vector2f currentPosition = this->getPosition();

	sf::Vector2f directions[] = {
		{ 100, 0 },    // Right
		{ -100, 0 },   // Left
		{ 0, 100 },    // Down
		{ 0, -100 },   // Up
		{ 100, 100 },  // Bottom-right (Diagonal)
		{ -100, 100 }, // Bottom-left (Diagonal)
		{ 100, -100 }, // Top-right (Diagonal)
		{ -100, -100 } // Top-left (Diagonal)
	};

	// Iterating over each direction
	for (const auto& direction : directions) {
		sf::Vector2f nextPosition = currentPosition + direction;
		
			if (board.isEmptySquare(pieces, nextPosition)) // Empty square, piece can move
			{
				possibleMoves.push_back(nextPosition);
			}
			else if (board.isOpponentPiece(nextPosition, pieces, this->getColor())) // Enemy piece, capture
			{
				possibleMoves.push_back(nextPosition);
				break; // Stop after capturing
			}
			else
			{
				break; // Stop if friendly piece
			}

		
	}

	
}

