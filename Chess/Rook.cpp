#include "Rook.h"



// Constructor
Rook::Rook(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture) , hasMoved(false) {}

// Overriden draw function
void Rook::draw(sf::RenderWindow& window)
{
	window.draw(sprite); // Sprite from piece
}

void Rook::getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves)
{
	possibleMoves.clear();
	sf::Vector2f currentPosition = this->getPosition();

	sf::Vector2f directions[] = {
		{0, -board.getSquareSize()}, // Up
		{0, board.getSquareSize()}, // Down
		{-board.getSquareSize(), 0}, // Left
		{board.getSquareSize(),0} // Right
	};

	// Iterating over each direction
	for (const auto& direction : directions) {
		sf::Vector2f nextPosition = currentPosition + direction;

		// Keep moving in the same direction until we hit a piece or reach bounds of border
		while (board.isWithinBounds(nextPosition))
		{
			if (board.isEmptySquare(pieces, nextPosition)) // Empty square, piece can move
			{
				possibleMoves.push_back(nextPosition);
			}
			else if (board.isOpponentPiece(nextPosition, pieces, this->getColor())) // Reached an enemy piece, will capture
			{
				possibleMoves.push_back(nextPosition); // Capture
				break; // Stop after capturing
			}
			else
			{
				break; // Stop if friendly piece
			}
			nextPosition += direction;
		}
	}

	
}

void Rook::setHasMoved(bool flag)
{
	this->hasMoved = flag;
}

