#include "SDL.h"
#include "Debug.h"

#include "EngineManager.h"
#include "PinballGame.h"

#define BAMT_WINDOW_NAME "BAMT ENGINE"
#define BAMT_RESOLUTION_WIDTH 1280
#define BAMT_RESOLUTION_HEIGHT 720
#define BAMT_TARGET_FRAME_RATE 120

EngineManager* engineManager;

int main(int argc, char* argv[])
{
	// Create and initialize our Engine.
	engineManager = new EngineManager();
	engineManager->Initialize(BAMT_WINDOW_NAME, BAMT_RESOLUTION_WIDTH, BAMT_RESOLUTION_HEIGHT, false, 1000/BAMT_TARGET_FRAME_RATE);

	// GAME PALLET GOES HERE
	auto* loadedGame = engineManager->AddScene<PinballGame>();
	loadedGame->active = true;

	engineManager->RunLoop();
	return 0;
}

// Left over garbage

//auto* ent2 = engineManager->AddEntity<Player>();

//ent1->SetParent(ent2);
//Debug::LogWarn("Ent2 should have a child. ", ent2->children[0]);
//Debug::LogWarn("Ent1 should have a parent. ", ent1->parent);