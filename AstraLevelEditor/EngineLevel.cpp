#include "EngineLevel.h"
#include "Global.h"

EngineLevel::EngineLevel(sf::RenderWindow& window, Global& var_) : glob(var_) {
    manage = new Manager();
    test = new Fiche();
    fps = new DebugDisplay();

    test->GetInformation(*manage);
}

EngineLevel::~EngineLevel() {

    delete test;
    test = nullptr;

    delete fps;
    fps = nullptr;
}

void EngineLevel::update(const bool* keys, float dt) {
    fps->update(dt, *manage);
}

void EngineLevel::displayScene(sf::RenderWindow& window) {
    fps->render(window);
    test->Render(window);
}

void EngineLevel::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
}