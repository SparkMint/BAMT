#include <iostream>
#include "SDL.h"
#include "Debug.h"
#include "GameManager.h"

auto WINDOW_NAME = "BAMT ENGINE";
auto RESOLUTION_WIDTH = 640;
auto RESOLUTION_HEIGHT = 480;

GameManager* gameManager;

int main(int argc, char* argv[])
{
	gameManager = new GameManager();
	gameManager->Initialize(WINDOW_NAME, RESOLUTION_WIDTH, RESOLUTION_WIDTH, false);

	Debug::ShowWarnings(false);

	while (gameManager->IsActive())
	{
		gameManager->Update();

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