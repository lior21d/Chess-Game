#ifndef PIECE_H // PIECE_H
#define PIECE_H // PIECE_H

#include <SFML/Graphics.hpp>
#include <string>

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

	
	virtual bool isValidMove(const sf::Vector2f& newPosition) const = 0;

	
	void setPosition(const sf::Vector2f& position);

	
	sf::Vector2f getPosition() const;

	
	std::string getColor() const;


};




#endif // PIECEP_H