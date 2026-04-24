#pragma once
#include "Scene.h"

#include "LevelLoader.h"
#include "Collider.h"
#include "Camera.h"
#include "PlayerEX.h"
#include "Trigger.h"
#include "BG_parralax_Full.h"
#include "Fiche.h"
#include "Manager.h"

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

	Global& glob;
};
