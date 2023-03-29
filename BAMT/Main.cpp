#include <SDL.h>

#include "Assignment/Scenes/PinballGame.h"
#include "Core/EngineManager.h"
#include "Core/Misc/Debug.h"

extern EngineManager* engineManager;

int main(int argc, char* argv[])
{
	// Create and initialize our Engine.
	engineManager = new EngineManager();
	engineManager->Initialize(BAMT_WINDOW_NAME, BAMT_RESOLUTION_WIDTH, BAMT_RESOLUTION_HEIGHT, false, 1000/BAMT_TARGET_FRAME_RATE);

	// GAME PALLET GOES HERE
	auto* loadedGame = engineManager->AddScene<PinballGame>();
	loadedGame->alwaysActive = true;

	engineManager->RunLoop();
	return 0;
}