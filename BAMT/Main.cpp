#include "SDL.h"
#include "Debug.h"

#include "EngineManager.h"

#define WINDOW_NAME "BAMT ENGINE"
#define RESOLUTION_WIDTH 1280
#define RESOLUTION_HEIGHT 720
#define TARGET_FRAME_RATE 10

EngineManager* engineManager;

int main(int argc, char* argv[])
{
	// Create and initialize our Engine.
	engineManager = new EngineManager();
	engineManager->Initialize(WINDOW_NAME, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, false, 1000/TARGET_FRAME_RATE);
	//engineManager->AddEntity<GameOfLife>();
	engineManager->RunLoop();

	return 0;
}