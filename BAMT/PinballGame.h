#ifndef BAMT_PINBALL_SCENEMANAGER
#define BAMT_PINBALL_SCENEMANAGER

#include "Scene.h"
#include "PinballGameLevel.h"

class PinballGame : public Scene
{
	//Scene* splashScreen;
	//Scene* mainMenu;
	//Scene* pauseMenu;
	PinballGameLevel* _gameLevel = nullptr;

	public:
		void Start() override;
};
#endif