#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Manager;

class Fiche
{
public:
	sf::RectangleShape rect;
	sf::Texture TX;

	sf::Vector2f size;
	sf::Vector2f pos;

	sf::Font font;

	//
	sf::Text* name;
	std::string DisplayedName;
	//
	sf::Text* ContenuName;
	std::string DisplayedContenu;
	//
	sf::Text* TXTville;
	std::string DisplayedVille;
	//
	sf::Text* TXTdate;
	int jour;
	int mois;
	//
	sf::Text* TXRpoid;
	int poids;

public:
	Fiche();
	~Fiche();

	void Update(float dt);
	void GetInformation(Manager& manage);
	void Render(sf::RenderWindow& window);

};

