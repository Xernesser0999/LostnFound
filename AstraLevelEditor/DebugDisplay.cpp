#include "DebugDisplay.h"
#include "Manager.h"

DebugDisplay::DebugDisplay() {
	font.openFromFile("font/Pixellettersfull-BnJ5.ttf");
	fpstext = new sf::Text(font, "FPS 0", 24);
	fpstext->setFillColor(sf::Color::Red);
	fpstext->setPosition({ 10, 10 });

	sender = new sf::Text(font, "FPS 0", 24);
	sender->setFillColor(sf::Color::Red);
	sender->setPosition({ 10, 30 });
}

DebugDisplay::~DebugDisplay() {

}

void DebugDisplay::update(float dt, Manager& man) {
	time += dt;
	++framecount;

	if (time >= 1) {
		fpstext->setString("FPS: " + std::to_string(framecount));
		time = 0;
		framecount = 0;
	}

	sender->setString(std::to_string(man.SendId));
}

void DebugDisplay::render(sf::RenderWindow& window) {
	window.draw(*fpstext);
	window.draw(*sender);
}