#include "PinballGame.h"

void PinballGame::Start()
{
	// Set this scene to always be active.
	alwaysActive = true;

	// Create all the scenes that we will need for this game.
	_splashScreen = engine->AddScene<SplashScreen>();
	_testScene = engine->AddScene<PhysicsTestScene>();

	// Activate the splash screen upon startup.
	_splashScreen->active = true;
}

void PinballGame::Update(float* timeStep)
{
	// If the splash screen is active, check if enough time has passed.
	if (_splashScreen->active)
	{
		if (splashScreenCurrentSeconds < splashScreenDisplaySeconds)
		{
			splashScreenCurrentSeconds += *timeStep;
		}
		else
		{
			// If it has, disable splash screen, enable menu.
			_splashScreen->active = false;
			_testScene->active = true;
		}
	}

	Scene::Update(timeStep);
}
