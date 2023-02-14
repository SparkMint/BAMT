#include "EngineManager.h"

EngineManager::EngineManager()
{
	Debug::Log("Engine Instance Created!");

	// Initialize variables.
	isActive = false;
	window = NULL;
	renderer = NULL;
}

EngineManager::~EngineManager() 
{
	Debug::Log("Engine Instance Destroyed!");

	// Initialize variables.
	isActive = false;

	window = nullptr;
	renderer = nullptr;
	delete window;
	delete renderer;
}


void EngineManager::Initialize(const char* windowName, int windowWidth, int windowHeight, bool fullscreen)
{
	SDL_WindowFlags windowFlag = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

	// Create an instance of a window.
	window = SDL_CreateWindow(
		windowName,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		windowWidth, windowHeight,
		windowFlag);

	// Create an instance of a Renderer.
	renderer = SDL_CreateRenderer(window, -1, 0);

	// Check if the window was successfully created.
	if (window) Debug::Log("Engine Window Instance Created Successfully!");
	else Debug::LogError("Engine Window Instance is Null!");
	

	// Check if the renderer was successfully created.
	if (renderer) Debug::Log("Engine Renderer Instance Created Successfully!");
	else Debug::LogError("Engine Renderer Instance is Null!");

	// Sets this GameManager to being Active.
	isActive = true;
}

void EngineManager::Update()
{
	Input::DoInput();
	tick++;
}

void EngineManager::Render()
{
	// Sets the colour of the renderer to black.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Clears the entire screen to be this colour.
	SDL_RenderClear(renderer);

	// Show the result of the Renderer stuff from before.
	SDL_RenderPresent(renderer);
}

void EngineManager::Clean()
{
	//Debug::LogWarn("GameManager's Clean Function isnt implemented yet!");
}

bool EngineManager::IsActive() 
{
	return isActive;
}