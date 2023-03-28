#ifndef BAMT_PINBALL_SCENEMANAGER
#define BAMT_PINBALL_SCENEMANAGER

#include "Test/PhysicsTestScene.h"
#include "PinballGameLevel.h"
#include "SplashScreen.h"
#include "../../Core/EngineManager.h"
#include "../../Core/ECS/Scene.h"

class PinballGame : public Scene
{
	// Splash Screen Stuff.
	SplashScreen* _splashScreen;
	float splashScreenDisplaySeconds = 5;
	float splashScreenCurrentSeconds = 0;

	PinballGameLevel* _gameScene = nullptr;
	PhysicsTestScene* _testScene = nullptr;

	public:
		void Start() override;
		void Update(float* timeStep) override;
};
#endif