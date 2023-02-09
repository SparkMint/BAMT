#include <iostream>

#include "SDL.h"
#include "Debug.h"

using namespace Debug;

int main(int argc, char* argv[])
{
	SDL_Window* window = SDL_CreateWindow("BAMT Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	DebugLog("Log Test");
	DebugLogWarn("Warning Test");
	DebugLogError("Error Test");

	SDL_Delay(5000);

	SDL_DestroyWindow(window);

	return 0;
}