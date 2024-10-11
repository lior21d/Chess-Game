#include "Pawn.h"
#include "iostream"
// Constructor
Pawn::Pawn(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture)
	: Piece(color, position, texture), firstMove(true) {}

// Overriden draw function
void Pawn::draw(sf::RenderWindow& window)
{
	window.draw(sprite); // Sprite from Piece
}

// Get all possible moves for pawn piece
void Pawn::getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves)
{
	possibleMoves.clear();
	sf::Vector2f currentPosition = this->getPosition();

	// Getting movement direction
	float direction = (this->getColor() == "white") ? -1.0f : 1.0f; // White goes up, black goes down

	// Forward move
	sf::Vector2f forwardMove = currentPosition + sf::Vector2f(0, direction * 100);
	if (board.isEmptySquare(pieces, forwardMove) && board.isWithinBounds(forwardMove)) {
		possibleMoves.push_back(forwardMove);
	}
	// Double step - first move
	if (this->firstMove == true) {
		sf::Vector2f doubleMove = currentPosition + sf::Vector2f(0, direction * 200);
		if (board.isEmptySquare(pieces, doubleMove) && board.isEmptySquare(pieces, forwardMove) && board.isWithinBounds(doubleMove)) {
			possibleMoves.push_back(doubleMove);
			this->firstMove = false;
		}
	}
	
	
	// Capture moves (diagonal)
	sf::Vector2f captureRight = currentPosition + sf::Vector2f(100, direction * 100);
	sf::Vector2f captureLeft = currentPosition + sf::Vector2f(-100, direction * 100);

	if (board.isOpponentPiece(captureRight, pieces, this->getColor()) && board.isWithinBounds(captureRight))
	{
		possibleMoves.push_back(captureRight);
	}

	if (board.isOpponentPiece(captureLeft, pieces, this->getColor()) && board.isWithinBounds(captureLeft))
	{
		possibleMoves.push_back(captureLeft);
	}

	// En passant check
	sf::Vector2f enPassantTarget = board.getEnPassantTarget();
	if (board.isWithinBounds(enPassantTarget)) { // There is a possible en passant
		// Check if enPassantTarget is a valid diagonal move for this pawn
		if (abs(enPassantTarget.x - currentPosition.x) == 100 &&
			enPassantTarget.y == currentPosition.y + (getColor() == "white" ? -100 : 100)) {
			possibleMoves.push_back(enPassantTarget);
		}
			
		
	}
	
}




bool Pawn::getFirstMove() {
	return firstMove;
}
void Pawn::setFirstMove(bool flag) {
	firstMove = flag;
}
