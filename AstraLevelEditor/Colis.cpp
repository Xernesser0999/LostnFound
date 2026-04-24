#include "Colis.h"
#include <iostream>

Colis::Colis(float x, float y, float width, float height)
{
	rectangle.setSize({ width, height });

	if (!texture.loadFromFile("sprite/Debug/Colis Fermer.png")) {
		std::cerr << "Erreur : Impossible de charger sprite/Debug/Colis Fermer\n";
	}
	else {
		rectangle.setTexture(&texture);
	}

	rectangle.setPosition({ x,y });
}

void Colis::Open(std::string path)
{
	if (!texture.loadFromFile(path))
	{
		std::cerr << "Erreur : Impossible de charger " << path << "\n";
	}
	else
	{
		rectangle.setTexture(&texture);
	}
}

bool Colis::isClicked(sf::Vector2i mousePos, sf::Mouse::Button button)
{
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	if (button == sf::Mouse::Button::Left && rectangle.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}
	return false;
}

	
void Colis::draw(sf::RenderWindow& window) 
{
	window.draw(rectangle);
}