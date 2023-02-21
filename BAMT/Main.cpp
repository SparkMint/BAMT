#include "SDL.h"

#include "EngineManager.h"
#include "TickTimer.h"


#include "Debug.h"
#include "Input.h"


// RENDERING 
#include "RectRenderer.h"
#include "TriRenderer.h"


//ENTITY COMPONENT SYSTEM
#include "Entity.h"
#include "Component.h"

#include "Player.h"

auto WINDOW_NAME = "BAMT ENGINE";
auto RESOLUTION_WIDTH = 640;
auto RESOLUTION_HEIGHT = 480;

int DELTA_TIME = 16;

EngineManager* engineManager;

int main(int argc, char* argv[])
{
	// Create and initialize our Engine.
	engineManager = new EngineManager();
	engineManager->Initialize(WINDOW_NAME, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, false);

	Player* p = engineManager->AddEntity<Player>();
	p->GetComponent<Transform>()->Translate(250, 250);
	p->renderLayer = 1;

	Player* l = engineManager->AddEntity<Player>();
	l->GetComponent<Transform>()->Translate(250, 250);
	l->GetComponent<PlayerInput>()->movementSpeed = -2;
	l->renderLayer = 3;


	Entity* h = engineManager->AddEntity<Entity>();
	h->renderLayer = 2;
	h->AddComponent<Transform>();
	h->GetComponent<Transform>()->Translate(250, 250);
	h->AddComponent<RectRenderer>(51, 51, true);

	while (engineManager->IsActive()) 
	{
		engineManager->tickTimer->ResetTimer();

		// Get Input from the User.
		Input::DoInput();

		engineManager->Update();

		engineManager->Render();

		// Cleans any garbage data. TODO: Implement this.
		engineManager->Clean();

		if (engineManager->tickTimer->GetTicks() < DELTA_TIME)
		{
			SDL_Delay(DELTA_TIME - engineManager->tickTimer->GetTicks());
		}
	}

	engineManager->Stop();

	// Stops all SQL Related stuff.
	SDL_Quit();

	return 0;
}

// Old Renderer Examples.
//engineManager->AddRenderTarget(new RectRenderer(200, 150, 250, 250, false));
//engineManager->AddRenderTarget(new TriRenderer(new SDL_Point{ 250,200 }, new SDL_Point{ 300,300 }, new SDL_Point{ 200,300 }));
//engineManager->AddRenderTarget(new TriRenderer(new SDL_Point{ 250,200 }, 50));