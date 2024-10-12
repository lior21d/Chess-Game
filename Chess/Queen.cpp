#include "Queen.h"


// Constructor
Queen::Queen(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture) {}

// Overriden draw function
void Queen::draw(sf::RenderWindow& window)
{
	window.draw(sprite); // Sprite from piece
}

void Queen::getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves)
{
	possibleMoves.clear();
	sf::Vector2f currentPosition = this->getPosition();

	// Because the queen moves like a rook and a bishop combined, we will check for both

	// Rook movement
	sf::Vector2f rookDir[] = {
		{0, -board.getSquareSize()}, // Up
		{0, board.getSquareSize()}, // Down
		{-board.getSquareSize(), 0}, // Left
		{board.getSquareSize(),0} // Right
	};

	// Iterating over each direction
	for (const auto& direction : rookDir) {
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
	
	// Bishop movement
	sf::Vector2f bishopDir[] = {
		{board.getSquareSize(), -board.getSquareSize()}, // Up-Right
		{-board.getSquareSize(), -board.getSquareSize()}, // Up-Left
		{board.getSquareSize(), board.getSquareSize()}, // Down-Right
		{-board.getSquareSize(), board.getSquareSize()}, // Down-Left
	};

	// Iterating over each direction
	for (const auto& direction : bishopDir) {
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
				possibleMoves.push_back(nextPosition);
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

