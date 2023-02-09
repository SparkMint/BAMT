#include <iostream>
#include "SDL.h"
#include "Debug.h"

int main(int argc, char* argv[])
{
	auto WINDOW_NAME = "BAMT ENGINE";
	auto RESOLUTION_WIDTH = 640;
	auto RESOLUTION_HEIGHT = 480;

	SDL_Window* window = SDL_CreateWindow(
		WINDOW_NAME, 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 
		SDL_WINDOW_SHOWN);

	if (window == NULL) Debug::LogError("Window was not created successfully.");

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// Sets the colour of the renderer to black.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Clears the entire screen to be this colour.
	SDL_RenderClear(renderer);

	// Show the result of the Renderer stuff from before.
	SDL_RenderPresent(renderer);

	// Debug Logging Tests.
	Debug::Log("Log Test");
	Debug::LogWarn("Warning Test");
	Debug::LogError("Error Test");

	// Creates a Delay of 5 seconds.
	SDL_Delay(5000);

	// Quits SQL. Remember to do this!
	SDL_Quit();

	return 0;
}