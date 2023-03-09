#include "SDL.h"
#include "Debug.h"

#include "EngineManager.h"
#include "GameOfLife.h"
#include "Player.h"

#define WINDOW_NAME "BAMT ENGINE"
#define RESOLUTION_WIDTH 1280
#define RESOLUTION_HEIGHT 720
#define TARGET_FRAME_RATE 60

EngineManager* engineManager;

int main(int argc, char* argv[])
{
	// Create and initialize our Engine.
	engineManager = new EngineManager();
	engineManager->Initialize(WINDOW_NAME, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, false, 1000/TARGET_FRAME_RATE);

	auto* ent1 = engineManager->AddEntity<Player>();

	auto* ent2 = engineManager->AddEntity<Player>();

	ent1->SetParent(ent2);
	Debug::Log("Ent2 should have a child. ", ent2->children[0]);
	Debug::Log("Ent1 should have a parent. ", ent1->parent);


	engineManager->RunLoop();

	return 0;
}