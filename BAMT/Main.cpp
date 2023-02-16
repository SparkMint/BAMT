#include "SDL.h"
#include "BAMT.h"

#include <iostream>

auto WINDOW_NAME = "BAMT ENGINE";
auto RESOLUTION_WIDTH = 640;
auto RESOLUTION_HEIGHT = 480;

EngineManager* engineManager;

int main(int argc, char* argv[])
{
	engineManager = new EngineManager();
	engineManager->Initialize(WINDOW_NAME, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, false);

	
	engineManager->AddRenderTarget(new RectRenderer(200, 150, 250, 250, false));
	//engineManager->AddRenderTarget(new TriRenderer(new SDL_Point{ 250,200 }, new SDL_Point{ 300,300 }, new SDL_Point{ 200,300 }));
	engineManager->AddRenderTarget(new TriRenderer(new SDL_Point{ 250,200 }, 50));

	Entity* ent = new Entity();
	ent->AddComponent<TestComponent>();
	ent->GetComponent<TestComponent>()->Start();


	// Game Loop. TODO: Move this into its own thing.
	while (engineManager->IsActive()) 
	{
		// Call update method on the GameManager
		engineManager->Update();

		// Call the render method.
		engineManager->Render();

		// Cleans any garbage data. TODO: Implement this.
		engineManager->Clean();

		// Sets a delay of 16 milliseconds. AKA 60 FPS.
		SDL_Delay(16);
	}

	engineManager->Stop();

	// Stops all SQL Related stuff.
	SDL_Quit();

	return 0;
}