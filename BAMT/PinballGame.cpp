#include "PinballGame.h"

#include "EngineManager.h"

void PinballGame::Start()
{
	// Set this scene to always be active.
	alwaysActive = true;

	_gameLevel = engine->AddScene<PinballGameLevel>();
	_gameLevel->active = true;
}
