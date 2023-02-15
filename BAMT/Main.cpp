#include <iostream>
#include "SDL.h"
#include "BAMT.h"

auto WINDOW_NAME = "BAMT ENGINE";
auto RESOLUTION_WIDTH = 640;
auto RESOLUTION_HEIGHT = 480;

EngineManager* gameManager;

int main(int argc, char* argv[])
{
	gameManager = new EngineManager();
	gameManager->Initialize(WINDOW_NAME, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, false);

	gameManager->AddDrawTarget(new DrawRect(250, 250, 250, 250));

	Debug::ShowWarns(false);
	// Game Loop. TODO: Move this into its own thing.
	while (gameManager->IsActive())
	{
		// Call update method on the GameManager
		gameManager->Update();

		// Call the render method.
		gameManager->Render();

		// Cleans any garbage data. TODO: Implement this.
		gameManager->Clean();

		// Sets a delay of 16 milliseconds. AKA 60 FPS.
		SDL_Delay(16);
	}

	// Quits SQL. Remember to do this!
	SDL_Quit();

	return 0;
}
/*void RenderSquare()
{
	SDL_Rect rect;
	rect.x = 250;
	rect.y = 150;
	rect.w = 200;
	rect.h = 200;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderPresent(renderer);
}*/