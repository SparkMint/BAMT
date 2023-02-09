#include <iostream>
#include "SDL.h"
#include "Debug.h"
#include "Input.h"

// Temporary Function Declarations
void RenderBackground();
void RenderSquare();

// Global Variables
SDL_Window* window;
SDL_Renderer* renderer;

auto WINDOW_NAME = "BAMT ENGINE";
auto RESOLUTION_WIDTH = 640;
auto RESOLUTION_HEIGHT = 480;

int main(int argc, char* argv[])
{
	window = SDL_CreateWindow(
		WINDOW_NAME, 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 
		SDL_WINDOW_SHOWN);

	if (window == NULL) Debug::LogError("Window was not created successfully.");

	renderer = SDL_CreateRenderer(window, -1, 0);

	// Debug Logging Tests.
	Debug::Log("Log Test");
	Debug::LogWarn("Warning Test");
	Debug::LogError("Error Test");

	while (1)
	{
		Input::DoInput();
	
		RenderBackground();

		RenderSquare();

		SDL_Delay(16);
	}
	// Quits SQL. Remember to do this!
	SDL_Quit();

	return 0;
}

void RenderBackground()
{
	// Sets the colour of the renderer to black.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Clears the entire screen to be this colour.
	SDL_RenderClear(renderer);

	// Show the result of the Renderer stuff from before.
	SDL_RenderPresent(renderer);
}

void RenderSquare()
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
}