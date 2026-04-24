#pragma once
#include <SFML/Graphics.hpp>

class Manager;

class DebugDisplay
{
public:
	sf::Font font;
	sf::Text* fpstext;

	sf::Text* sender;

	int framecount = 0;
	double time = 0;

public:
	DebugDisplay();
	~DebugDisplay();

	void update(float dt, Manager& man);
	void render(sf::RenderWindow& window);
};

