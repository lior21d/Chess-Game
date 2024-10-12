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
		{ board.getSquareSize(), 2 * board.getSquareSize() }, { board.getSquareSize(), -2 * board.getSquareSize() },  // Right moves
		{ -board.getSquareSize(), 2 * board.getSquareSize() }, { -board.getSquareSize(), -2 * board.getSquareSize() }, // Left moves
		{ 2 * board.getSquareSize(), board.getSquareSize() }, { 2 * board.getSquareSize(), -board.getSquareSize() },  // Down moves
		{ -2 * board.getSquareSize(), board.getSquareSize() }, { -2 * board.getSquareSize(), -board.getSquareSize() } // Up moves
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

