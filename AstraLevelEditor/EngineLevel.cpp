#include "EngineLevel.h"
#include "Global.h"

EngineLevel::EngineLevel(sf::RenderWindow& window, Global& var_) 
    : glob(var_), windowRef(window)
{

    fps = new DebugDisplay();

    listeColis.push_back(new Colis(1920/2-250, 1080/2-250, 500.f, 500.f));

    manage = new Manager();
    test = new Fiche();

    test->GetInformation(*manage);

    liste = new Liste();
    liste->GetInfo(*manage);
    //WIN

    Win.setPosition({ 0, 0 });
    Win.setSize({ 1920, 1080 });
    WinTX.loadFromFile("sprite/Debug/win.png");
    Win.setTexture(&WinTX);

    //float posX_, float posY_, float sizeX, float sizeY, std::string file, std::string hover, int ID_
    Youssef = new GUI_button(
        20,
        1080-120,
        100,
        100,
        "sprite/Debug/Youssef.png",
        "sprite/Debug/Youssef.png",
        1
    );

    Jaouen = new GUI_button(
        20,
        1080 - 240,
        100,
        100,
        "sprite/Debug/Jaouen.png",
        "sprite/Debug/Jaouen.png",
        2
    );

    Etienne = new GUI_button(
        20,
        1080 - 360,
        100,
        100,
        "sprite/Debug/Etienne.png",
        "sprite/Debug/Etienne.png",
        3
    );

    Alex = new GUI_button(
        20,
        1080 - 480,
        100,
        100,
        "sprite/Debug/Alex.png",
        "sprite/Debug/Alex.png",
        4
    );

    Line = new GUI_button(
        20,
        1080 - 480 - 120,
        100,
        100,
        "sprite/Debug/Line.png",
        "sprite/Debug/Line.png",
        5
    );

    Chloe = new GUI_button(
        20,
        1080 - 480 - 240,
        100,
        100,
        "sprite/Debug/Chloe.png",
        "sprite/Debug/Chloe.png",
        6
    );

    Vincent = new GUI_button(
        20,
        1080 - 480 - 360,
        100,
        100,
        "sprite/Debug/Vincent.png",
        "sprite/Debug/Vincent.png",
        7
    );

    Maiwen = new GUI_button(
        20,
        1080 - 480 - 480,
        100,
        100,
        "sprite/Debug/Maiwen.png",
        "sprite/Debug/Maiwen.png",
        8
    );
}

EngineLevel::~EngineLevel() {

    delete test;
    test = nullptr;

    delete fps;
    fps = nullptr;

    delete liste;
    liste = nullptr;

    for (auto* c : listeColis) { delete c; }
    listeColis.clear();
}

void EngineLevel::update(const bool* keys, float dt) {
    fps->update(dt, *manage);
    bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    if (isPressed && !wasMousePressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(windowRef);
        sf::Vector2f worldPos = windowRef.mapPixelToCoords(mousePos);

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
    liste->render(window);

    if (Youssef->clicked(window)) {
        if (Youssef->ID == manage->SendId) {
            isWin = true;
        }
        else {
            isGO = true;
            WinTX.loadFromFile("sprite/Debug/GO.png");
        }
    };
    if (Jaouen->clicked(window)) {
        if (Jaouen->ID == manage->SendId) {
            isWin = true;
        }
        else {
            isGO = true;
            WinTX.loadFromFile("sprite/Debug/GO.png");
        }
    };
    if (Alex->clicked(window)) {
        if (Alex->ID == manage->SendId) {
            isWin = true;
        }
        else {
            isGO = true;
            WinTX.loadFromFile("sprite/Debug/GO.png");
        }
    };
    if (Chloe->clicked(window)) {
        if (Chloe->ID == manage->SendId) {
            isWin = true;
        }
        else {
            isGO = true;
            WinTX.loadFromFile("sprite/Debug/GO.png");
        }
    };
    if (Line->clicked(window)) {
        if (Line->ID == manage->SendId) {
            isWin = true;
        }
        else {
            isGO = true;
            WinTX.loadFromFile("sprite/Debug/GO.png");
        }
    };
    if (Vincent->clicked(window)) {
        if (Vincent->ID == manage->SendId) {
            isWin = true;
        }
        else {
            isGO = true;
            WinTX.loadFromFile("sprite/Debug/GO.png");
        }
    };
    if (Maiwen->clicked(window)) {
        if (Maiwen->ID == manage->SendId) {
            isWin = true;
        }
        else {
            isGO = true;
            WinTX.loadFromFile("sprite/Debug/GO.png");
        }
    };
    if (Etienne->clicked(window)) {
        if (Etienne->ID == manage->SendId) {
            isWin = true;
        }
        else {
            isGO = true;
            WinTX.loadFromFile("sprite/Debug/GO.png");
        }
    };

    Youssef->render(window);
    Jaouen->render(window);
    Alex->render(window);
    Chloe->render(window);
    Etienne->render(window);
    Maiwen->render(window);
    Vincent->render(window);
    Line->render(window);

    if (isWin || isGO) {
        window.draw(Win);
    }
}

void EngineLevel::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
}