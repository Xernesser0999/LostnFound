#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Colis
{
private:
    sf::Texture texture;
public:
    sf::RectangleShape rectangle;

    Colis(float width, float height, float x, float y);

    void Open(std::string path);

    bool isClicked(sf::Vector2i mousePos, sf::Mouse::Button button);

    void draw(sf::RenderWindow& window);
    
};