#include "Knight.h"


// Constructor
Knight::Knight(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture) {}

// Overriden draw function
void Knight::draw(sf::RenderWindow& window)
{
	window.draw(sprite); // Sprite from piece
}

void Knight::getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves)
{
	possibleMoves.clear();
	sf::Vector2f currentPosition = this->getPosition();

	sf::Vector2f directions[] = {
		{ 100, 200 }, { 100, -200 },  // Right moves
		{ -100, 200 }, { -100, -200 }, // Left moves
		{ 200, 100 }, { 200, -100 },  // Down moves
		{ -200, 100 }, { -200, -100 } // Up moves
	};

	// Iterating over each direction
	for (const auto& direction : directions) {
		sf::Vector2f nextPosition = currentPosition + direction;

		// Check if the move is within bounds
		if (board.isWithinBounds(nextPosition))
		{
			if (board.isEmptySquare(pieces, nextPosition)) // Empty square, can move
			{
				possibleMoves.push_back(nextPosition);
			}
			else if (board.isOpponentPiece(nextPosition, pieces, this->getColor())) // Enemy on the square, capture
			{
				possibleMoves.push_back(nextPosition);
			}
		}
	}

	
}

