#include "EngineLevel.h"
#include "Global.h"

EngineLevel::EngineLevel(sf::RenderWindow& window, Global& var_) 
    : glob(var_), windowRef(window)
{
   
    loader = new LevelLoader();
    loader->load (
        "level/TestLevel/map.txt",  
        "level/TestLevel/map.png",  
        window,
        60,                         
        40                        
    );

   
    cam = new Camera(1920, 1080, 50*60, 50*40, 0.005);
    Machine = new StateMachine(new DummyState());
   
    player = new PlayerEX (
        window,
        1,
        200,
        1300,
        50,
        50,
        1425,
        600,
        "sprite/Debug/PlaceHolder.png",
        1,
        *Machine
    );
    Machine->currentState = new IdleStateRight(*player);

    parralax = new BG_parralax_Full();
    parralax->addlayer("sprite/Background/Debugmap.png", 0.5);

   
    trig = new Trigger(
        500,
        800,
        150,
        50,
        true
    );

    cam->view->setCenter(player->pos);

    fps = new DebugDisplay();

    listeColis.push_back(new Colis(300.f, 1700.f, 200.f, 200.f));
}

EngineLevel::~EngineLevel() {
    for (auto& r : Colliderlist) {
        delete r;
        r = nullptr;
    }
    Colliderlist.clear();
    delete loader;
    delete cam;
    delete player;
    delete parralax;
    delete trig;
    delete fps;

    loader = nullptr;
    cam = nullptr;
    player = nullptr;
    parralax = nullptr;
    trig = nullptr;
    fps = nullptr;

    for (auto* c : listeColis) { delete c; }
    listeColis.clear();

    delete Machine;
    Machine = nullptr;
}

void EngineLevel::update(const bool* keys, float dt) {

    loader->update(dt, *player);
    player->update(dt, loader->colliders);
    cam->Update(*player);
    parralax->update(dt, *cam);
    trig->update(dt, *player);
    if (trig->trigger) {
        std::cout << "tick";
    }

    if (player->pos.y > 10000) {
        player->pos.y = 0;
    }

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

    fps->update(dt);
}

void EngineLevel::displayScene(sf::RenderWindow& window) {
    window.setView(*cam->view);

    parralax->render(window);
    loader->render(window, cam);

    for (auto* colis : listeColis) 
    {
        colis->draw(window);
    }

    player->render(window);
    Machine->currentState->render(window);
    trig->render(window);

    window.setView(window.getDefaultView());

    fps->render(window);
}

void EngineLevel::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
}