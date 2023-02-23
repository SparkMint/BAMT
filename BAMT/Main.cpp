#include "SDL.h"

#include "EngineManager.h"
#include "TickTimer.h"


#include "Debug.h"
#include "Input.h"

//ENTITY COMPONENT SYSTEM
#include "Entity.h"
#include "Component.h"

#include "Player.h"

#include "PlayerMoveMouse.h"


// RENDERING 
#include "RectRenderer.h"
#include "TriRenderer.h"

auto WINDOW_NAME = "BAMT ENGINE";
auto RESOLUTION_WIDTH = 1280;
auto RESOLUTION_HEIGHT = 720;

int DELTA_TIME = 10;
int HOW_MANY_SNAKE_SEGMENTS = 100;

EngineManager* engineManager;

int main(int argc, char* argv[])
{
	//srand(time(0));

	std::vector<Player*> SnekSegments;
	// Create and initialize our Engine.
	engineManager = new EngineManager();
	engineManager->Initialize(WINDOW_NAME, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, false);

	for (int i = 0; i < HOW_MANY_SNAKE_SEGMENTS; i++)
	{
		SnekSegments.push_back(engineManager->AddEntity<Player>());
	}

	for (int i = 0; i <= SnekSegments.size() - 1; i++)
	{
		SnekSegments[i]->GetComponent<PlayerMoveMouse>()->movementdelay = i;
		SnekSegments[i]->GetComponent<RectRenderer>()->UpdateSize(i / 2, i / 2);
	}

	engineManager->RunLoop();

	// Stops all SQL Related stuff.
	SDL_Quit();

	return 0;
}

// Old Renderer Examples.
//engineManager->AddRenderTarget(new RectRenderer(200, 150, 250, 250, false));
//engineManager->AddRenderTarget(new TriRenderer(new SDL_Point{ 250,200 }, new SDL_Point{ 300,300 }, new SDL_Point{ 200,300 }));
//engineManager->AddRenderTarget(new TriRenderer(new SDL_Point{ 250,200 }, 50));