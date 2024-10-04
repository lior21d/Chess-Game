#include "PieceGenerator.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"


std::vector<Piece*> createAllPieces(TextureManager* textureManager) {
	// Creating the vector that will store all the pieces
	std::vector<Piece*> pieces;

	// Creating pawns
	for (int i = 0; i < 8; ++i)
	{
		// Black pawns
		pieces.push_back(new Pawn("black", sf::Vector2f(static_cast<float>(i) * 100, 1 * 100), textureManager->getTexture("black_pawn")));

		// White pawns
		pieces.push_back(new Pawn("white", sf::Vector2f(static_cast<float>(i) * 100, 6 * 100), textureManager->getTexture("white_pawn")));
	}

	// Creating rooks
	pieces.push_back(new Rook("black", sf::Vector2f(0, 0), textureManager->getTexture("black_rook")));
	pieces.push_back(new Rook("black", sf::Vector2f(700, 0), textureManager->getTexture("black_rook")));
	pieces.push_back(new Rook("white", sf::Vector2f(0, 700), textureManager->getTexture("white_rook")));
	pieces.push_back(new Rook("white", sf::Vector2f(700, 700), textureManager->getTexture("white_rook")));

	// Creating knights
	pieces.push_back(new Knight("black", sf::Vector2f(100, 0), textureManager->getTexture("black_knight")));
	pieces.push_back(new Knight("black", sf::Vector2f(600, 0), textureManager->getTexture("black_knight")));
	pieces.push_back(new Knight("white", sf::Vector2f(100, 700), textureManager->getTexture("white_knight")));
	pieces.push_back(new Knight("white", sf::Vector2f(600, 700), textureManager->getTexture("white_knight")));

	// Creating bishops
	pieces.push_back(new Bishop("black", sf::Vector2f(200, 0), textureManager->getTexture("black_bishop")));
	pieces.push_back(new Bishop("black", sf::Vector2f(500, 0), textureManager->getTexture("black_bishop")));
	pieces.push_back(new Bishop("white", sf::Vector2f(200, 700), textureManager->getTexture("white_bishop")));
	pieces.push_back(new Bishop("white", sf::Vector2f(500, 700), textureManager->getTexture("white_bishop")));

	// Creating kings
	pieces.push_back(new King("black", sf::Vector2f(400, 0), textureManager->getTexture("black_king")));
	pieces.push_back(new King("white", sf::Vector2f(400, 700), textureManager->getTexture("white_king")));
	
	// Creating queens
	pieces.push_back(new Queen("black", sf::Vector2f(300, 0), textureManager->getTexture("black_queen")));
	pieces.push_back(new Queen("white", sf::Vector2f(300, 700), textureManager->getTexture("white_queen")));

	return pieces;
}
