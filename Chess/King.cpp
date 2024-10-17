#include "King.h"


// Constructor
King::King(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture), hasMoved(false) {}

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
		{ board.getSquareSize(), 0 },    // Right
		{ -board.getSquareSize(), 0 },   // Left
		{ 0, board.getSquareSize() },    // Down
		{ 0, -board.getSquareSize() },   // Up
		{ board.getSquareSize(), board.getSquareSize() },  // Bottom-right (Diagonal)
		{ -board.getSquareSize(), board.getSquareSize() }, // Bottom-left (Diagonal)
		{ board.getSquareSize(), -board.getSquareSize() }, // Top-right (Diagonal)
		{ -board.getSquareSize(), -board.getSquareSize() } // Top-left (Diagonal)
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

	// Check for castle
	if (board.canCastleKingSide(this->getColor(), pieces))
	{
		float y = (this->getColor() == "white") ? 7 : 0;
		possibleMoves.push_back(sf::Vector2f(7 * board.getSquareSize(), y * board.getSquareSize()));
	}
	if (board.canCastleQueenSide(this->getColor(), pieces))
	{
		float y = (this->getColor() == "white") ? 7 : 0;
		possibleMoves.push_back(sf::Vector2f(0, y * board.getSquareSize()));
	}
	
}

void King::setFirstMove(bool flag)
{
	hasMoved = false;
}


