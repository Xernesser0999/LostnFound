#include "EngineLevel.h"
#include "Global.h"

EngineLevel::EngineLevel(sf::RenderWindow& window, Global& var_) 
    : glob(var_), windowRef(window)
{

    fps = new DebugDisplay();

    listeColis.push_back(new Colis(1300.f, 900.f, 500.f, 500.f));

    manage = new Manager();
    test = new Fiche();

    test->GetInformation(*manage);
}

EngineLevel::~EngineLevel() {

    delete test;
    test = nullptr;

    delete fps;
    fps = nullptr;

    for (auto* c : listeColis) { delete c; }
    listeColis.clear();
}

void EngineLevel::update(const bool* keys, float dt) {
    fps->update(dt, *manage);
    bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    if (isPressed && !wasMousePressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(windowRef);
        sf::Vector2f worldPos = windowRef.mapPixelToCoords(mousePos, *cam->view);

        for (auto* colis : listeColis) {
            if (colis->rectangle.getGlobalBounds().contains(worldPos)) {
                std::cout << "Livreur Chronopost !" << std::endl;
                colis->Open("sprite/Debug/Colis Ouvert.png");
            }
        }
    }
    wasMousePressed = isPressed;
}

void EngineLevel::displayScene(sf::RenderWindow& window) {
    fps->render(window);
    for (auto* colis : listeColis) 
    {
        colis->draw(window);
    }
    test->Render(window);

}

void EngineLevel::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
}