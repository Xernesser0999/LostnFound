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
		isOpen = true;
	}
}

void Colis::addButton(std::string nom, std::string path)
{
	float offsetX = (bouton.size() * 120.f);
	sf::Vector2f pos = rectangle.getPosition() + sf::Vector2f(offsetX, 520.f);
	bouton.push_back(new ChoixPerso(nom, path, { 100.f, 100.f }, pos));
}

	
void Colis::draw(sf::RenderWindow& window) 
{
	window.draw(rectangle);
	if (isOpen) 
	{
		for (auto* b : bouton) b->draw(window);
	}
}

std::string Colis::checkButtonClick(sf::Vector2f mousePos)
{
	if (!isOpen) return "";
	for (auto* b : bouton)
	{
		if (b->isClicked(mousePos)) return b->getNom();
	}
	return "";
}
