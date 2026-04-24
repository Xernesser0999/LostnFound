#include "ChoixPerso.h"
#include <iostream>

ChoixPerso::ChoixPerso(std::string nom, std::string pathTexture, sf::Vector2f size, sf::Vector2f pos)
    : nomPerso(nom)
{
    shape.setSize(size);
    shape.setPosition(pos);

    if (!texture.loadFromFile(pathTexture)) {
        std::cerr << "Erreur : Impossible de charger le bouton de " << nom << std::endl;
    }
    shape.setTexture(&texture);
}

void ChoixPerso::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool ChoixPerso::isClicked(sf::Vector2f mousePos)
{
    return shape.getGlobalBounds().contains(mousePos);
}

