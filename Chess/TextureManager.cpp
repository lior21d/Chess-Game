#include "TextureManager.h"
#include <iostream>

void TextureManager::loadTexture(const std::string& key, const std::string& filepath) {
	sf::Texture texture;
	if (texture.loadFromFile(filepath)) {
		textures[key] = texture;
	}
	else {
		std::cerr << "Error: Could not load texture from " << filepath << std::endl;
	}
}

void TextureManager::loadAllTextures() {
	loadTexture("white_pawn", "Assets/white-pawn");
	loadTexture("black_pawn", "Assets/black-pawn");
	loadTexture("white_knight", "Assets/white-knight");
	loadTexture("black_knight", "Assets/black-knight");
	loadTexture("white_rook", "Assets/white-rook");
	loadTexture("black_rook", "Assets/black-rook");
	loadTexture("white_bishop", "Assets/white-bishop");
	loadTexture("black_bishop", "Assets/black-bishop");
	loadTexture("white_king", "Assets/white-king");
	loadTexture("black_king", "Assets/black-king");
	loadTexture("white_queen", "Assets/white-queen");
	loadTexture("black_queen", "Assets/black-queen");
}

sf::Texture& TextureManager::getTexture(const std::string& key)
{
	return textures.at(key);
}
