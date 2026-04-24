#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class ChoixPerso
{
private: 
	sf::RectangleShape shape;
	sf::Texture texture;
	std::string nomPerso;

public:
	ChoixPerso(std::string nom, std::string pathTexture, sf::Vector2f size, sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	bool isClicked(sf::Vector2f mousePos);

	std::string getNom() const { return nomPerso; }

};

