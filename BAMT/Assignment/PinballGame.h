#ifndef BAMT_PINBALL_SCENEMANAGER
#define BAMT_PINBALL_SCENEMANAGER
#include "../Core/ECS/Scene.h"

#include "PhysicsTestScene.h"
#include "PinballGameLevel.h"

class PinballGame : public Scene
{
	//Scene* splashScreen;
	//Scene* mainMenu;
	//Scene* pauseMenu;
	PinballGameLevel _gameScene;
	PhysicsTestScene* _TestScene = nullptr;

	public:
		void Start() override;
};
#endif