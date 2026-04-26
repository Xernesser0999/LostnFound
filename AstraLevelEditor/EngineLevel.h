#pragma once
#include "Scene.h"

#include "LevelLoader.h"
#include "Collider.h"
#include "Camera.h"
#include "PlayerEX.h"
#include "Trigger.h"
#include "BG_parralax_Full.h"

#include "Colis.h"
#include "Fiche.h"
#include "Manager.h"
#include "Liste.h"

#include "GUI_Button.h"

#include "DebugDisplay.h"

class Global;

class EngineLevel : public Scene {
public:

	EngineLevel(sf::RenderWindow& window, Global& var_);
	~EngineLevel();

	void displayScene(sf::RenderWindow& window) override;
	void update(const bool* keys, float dt);
	void nextScene(SceneState& currentScene, keys* _myKeys, sf::RenderWindow& window) override;

public:

	Manager* manage;
	Fiche* test;
	DebugDisplay* fps;

	StateMachine* Machine;
	Trigger* trig;
	LevelLoader* loader;
	PlayerEX* player;
	Camera* cam;
	std::vector<Collider*> Colliderlist;
	BG_parralax_Full* parralax;
	std::vector<Colis*> listeColis;
	Liste* liste;

	sf::RectangleShape Win;
	sf::Texture WinTX;

	GUI_button* Alex;
	GUI_button* Chloe;
	GUI_button* Etienne;
	GUI_button* Jaouen;
	GUI_button* Line;
	GUI_button* Maiwen;
	GUI_button* Vincent;
	GUI_button* Youssef;

	bool wasMousePressed = false;
	bool isWin = false;
	bool isGO = false;

	Global& glob;

private:
	sf::RenderWindow& windowRef;
};
