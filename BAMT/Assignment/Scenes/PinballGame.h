#ifndef ASSIGNMENT_SCENEMANAGER
#define ASSIGNMENT_SCENEMANAGER

#include "PinballGameLevel.h"
#include "SplashScreen.h"
#include "../../Core/EngineManager.h"
#include "../../Core/ECS/Scene.h"
#include "Test/PhysicsTestScene.h"

class PinballGame : public Scene
{
	// Splash Screen Stuff.
	SplashScreen* _splashScreen = nullptr;
	float splashScreenDisplaySeconds = 0;
	float splashScreenCurrentSeconds = 0;

	PinballGameLevel* _gameScene = nullptr;

	public:
		void Start() override;
		void Update(float* timeStep) override;
};
#endif