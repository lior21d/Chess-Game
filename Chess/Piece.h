#ifndef PIECE_H // PIECE_H
#define PIECE_H // PIECE_H

#include <SFML/Graphics.hpp>
#include <string>


class Board;

class Piece {

private:
	sf::Texture texture; // Texture for the piece

protected:
	std::string color; // Color of the piece (black or white)
	sf::Vector2f position; // Position of piece in pixels
	sf::Sprite sprite; // Sprite representing the piece

public:
	// Constructor
	Piece(const std::string& color, const sf::Vector2f& position, const sf::Texture& texture);


	virtual ~Piece() = default;

	virtual void draw(sf::RenderWindow& window) = 0;

	

	void setPosition(const sf::Vector2f& position);

	virtual void getPossibleMoves(Board& board, const std::vector<Piece*>& pieces, std::vector<sf::Vector2f>& possibleMoves) = 0;


	sf::Vector2f getPosition() const;


	std::string getColor() const;

	const sf::Sprite& getSprite() const;

};




#endif // PIECEP_H
