#include "GameManager.h"

GameManager::GameManager()
{
	Debug::Log("Game Instance Created!");

	// Initialize variables.
	isActive = false;
	window = NULL;
	renderer = NULL;
}

GameManager::~GameManager() 
{
	Debug::Log("Game Instance Destroyed!");
}


void GameManager::Initialise(const char* windowName, int windowWidth, int windowHeight, bool fullscreen)
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
	if (window == NULL) Debug::LogError("Window was not created successfully.");

	// Check if the renderer was successfully created.
	if (renderer == NULL) Debug::LogError("Renderer was not created successfully.");

	// Sets this GameManager to being Active.
	isActive = true;
}

void GameManager::Update()
{
	Render();
	Clean();
	Input::DoInput();
}

void GameManager::Render()
{
	// Sets the colour of the renderer to black.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// Clears the entire screen to be this colour.
	SDL_RenderClear(renderer);

	// Show the result of the Renderer stuff from before.
	SDL_RenderPresent(renderer);
}

void GameManager::Clean()
{
	Debug::LogWarn("Clean function has not been implemented yet.");
}

bool GameManager::IsActive() 
{
	return isActive;
}