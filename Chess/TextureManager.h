#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class TextureManager
{
private:
	std::unordered_map<std::string, sf::Texture> textures; // Map to store textures
	void loadTexture(const std::string& key, const std::string& filepath); // Load one texture

public:
	// Load all textures for chess pieces
	void loadAllTextures();

	// Retrieve a texture by its key
	sf::Texture& getTexture(const std::string& key);

};


#endif // TEXTUREMANAGER_H
