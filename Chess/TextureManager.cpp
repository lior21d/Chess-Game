#include "TextureManager.h"
#include <iostream>

void TextureManager::loadTexture(const std::string& key, const std::string& filepath) {
	sf::Texture texture;
	if (texture.loadFromFile(filepath)) {
		textures[key] = texture;
		texture.setSmooth(true); // Setting smooth texture to not make it look pixelated
	}
	else {
		std::cerr << "Error: Could not load texture from " << filepath << std::endl;
	}
}

void TextureManager::loadAllTextures() {
	loadTexture("white_pawn", "Assets/white-pawn.png");
	loadTexture("black_pawn", "Assets/black-pawn.png");
	loadTexture("white_knight", "Assets/white-knight.png");
	loadTexture("black_knight", "Assets/black-knight.png");
	loadTexture("white_rook", "Assets/white-rook.png");
	loadTexture("black_rook", "Assets/black-rook.png");
	loadTexture("white_bishop", "Assets/white-bishop.png");
	loadTexture("black_bishop", "Assets/black-bishop.png");
	loadTexture("white_king", "Assets/white-king.png");
	loadTexture("black_king", "Assets/black-king.png");
	loadTexture("white_queen", "Assets/white-queen.png");
	loadTexture("black_queen", "Assets/black-queen.png");
}

sf::Texture& TextureManager::getTexture(const std::string& key)
{
	return textures.at(key);
}
