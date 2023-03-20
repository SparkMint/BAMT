#include "SDL.h"
#include "Debug.h"

#include "EngineManager.h"
#include "PinballGame.h"

#define BAMT_WINDOW_NAME "BAMT ENGINE"
#define BAMT_RESOLUTION_WIDTH 1280
#define BAMT_RESOLUTION_HEIGHT 720
#define BAMT_TARGET_FRAME_RATE 60

EngineManager* engineManager;

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