#ifndef ASSIGNMENT_SCENEMANAGER
#define ASSIGNMENT_SCENEMANAGER

#include "PinballGameLevel.h"
#include "SplashScreen.h"
#include "../../Core/ECS/Scene.h"

class PinballGame : public Scene
{
	// Splash Screen Stuff.
	SplashScreen* _splashScreen = nullptr;
	float splashScreenDisplaySeconds = 5;
	float splashScreenCurrentSeconds = 0;

	PinballGameLevel* _gameScene = nullptr;

	public:
		void Start() override;
		void Update(float* timeStep) override;
};
#endif