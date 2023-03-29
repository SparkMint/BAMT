#include "PinballGame.h"

void PinballGame::Start()
{
	// Set this scene to always be active.
	alwaysActive = true;

	// Create all the scenes that we will need for this game.
	_splashScreen = engine->AddScene<SplashScreen>();
	_testScene = engine->AddScene<PhysicsTestScene>();
	_gameScene = engine->AddScene<PinballGameLevel>();

	// Activate the splash screen upon startup.
	_splashScreen->active = true;
}

void PinballGame::Update(float* timeStep)
{
	// If the splash screen is active, check if enough time has passed.
	if (_splashScreen->active)
	{
		// Skip the Splash Screen if the user presses space.
		if(Input::GetKeyDown(SDLK_SPACE)) splashScreenCurrentSeconds = splashScreenDisplaySeconds;

		if (splashScreenCurrentSeconds < splashScreenDisplaySeconds)
		{
			splashScreenCurrentSeconds += *timeStep;
		}
		else
		{
			// If it has, disable splash screen, enable menu.
			_splashScreen->active = false;
			_gameScene->active = true;
		}
	}
	Scene::Update(timeStep);
}