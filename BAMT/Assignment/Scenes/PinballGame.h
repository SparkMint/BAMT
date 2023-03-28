#ifndef BAMT_PINBALL_SCENEMANAGER
#define BAMT_PINBALL_SCENEMANAGER

#include "PinballGameLevel.h"
#include "SplashScreen.h"
#include "../../Core/EngineManager.h"
#include "../../Core/ECS/Scene.h"
#include "Test/PhysicsTestScene.h"

class PinballGame : public Scene
{
	// Splash Screen Stuff.
	SplashScreen* _splashScreen = nullptr;
	float splashScreenDisplaySeconds = 5;
	float splashScreenCurrentSeconds = 0;

	PinballGameLevel* _gameScene = nullptr;
	PhysicsTestScene* _testScene = nullptr;

	public:
		void Start() override;
		void Update(float* timeStep) override;
};
#endif