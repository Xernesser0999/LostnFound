#include "EngineLevel.h"
#include "Global.h"

EngineLevel::EngineLevel(sf::RenderWindow& window, Global& var_) : glob(var_) {
   
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

    fps->update(dt);
}

void EngineLevel::displayScene(sf::RenderWindow& window) {
    window.setView(*cam->view);

    parralax->render(window);
    loader->render(window, cam);
    player->render(window);
    Machine->currentState->render(window);
    trig->render(window);

    window.setView(window.getDefaultView());

    fps->render(window);
}

void EngineLevel::nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) {
}