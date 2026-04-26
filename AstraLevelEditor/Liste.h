#pragma once
#include "SFML/Graphics.hpp";
#include "string"

class Manager;

class Liste
{
public:
	Liste();
	~Liste();

	void update(float dt);
	void GetInfo(Manager& manage);
	void render(sf::RenderWindow& window);

public:
	sf::Vector2f Pos;
	sf::Vector2f Size;
	sf::Texture Tx;

	sf::RectangleShape rect;

	sf::Font font;
	sf::Text* Text;
	sf::Text* Date;
	sf::Text* note;

};

