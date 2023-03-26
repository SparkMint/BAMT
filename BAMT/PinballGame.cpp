#include "PinballGame.h"

#include "EngineManager.h"
#include "PhysicsTestScene.h"

void PinballGame::Start()
{
	// Set this scene to always be active.
	alwaysActive = true;

	_TestScene = engine->AddScene<PhysicsTestScene>();
	_TestScene->active = true;
}