#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ChoixPerso.h"

class Colis
{
private:
    sf::Texture texture;
    bool isOpen = false;
    std::vector<ChoixPerso*> bouton;

public:
    sf::RectangleShape rectangle;

    Colis(float width, float height, float x, float y);

    ~Colis()
    {
        for (auto* b : bouton) delete b;
    }

    void Open(std::string path);
    void addButton(std::string nom, std::string path);

    void draw(sf::RenderWindow& window);

    std::string checkButtonClick(sf::Vector2f mousePos);

    bool getIsOpen() const { return isOpen; }
    
};