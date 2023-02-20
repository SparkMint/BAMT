#include "EngineManager.h"

#pragma region Constructors
EngineManager::EngineManager()
{
	Debug::Log("Engine Instance Created!");

	// Initialize variables.
	_isActive = false;
	_window = NULL;
	_renderer = NULL;
	tickTimer = NULL;
}
EngineManager::~EngineManager() 
{
	Debug::Log("Engine Instance Destroyed!");

	// Initialize variables.
	_isActive = false;
}
#pragma endregion Constructors

void EngineManager::Initialize(const char* windowName, int windowWidth, int windowHeight, bool fullscreen)
{
	SDL_WindowFlags windowFlag = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

	// Create an instance of a window.
	_window = SDL_CreateWindow(
		windowName,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		windowWidth, windowHeight,
		windowFlag);

	// Create an instance of a Renderer.
	_renderer = SDL_CreateRenderer(_window, -1, 0);

	// Create a new TickTimer.
	tickTimer = new TickTimer();

	// Check if the window was successfully created.
	if (_window) Debug::Log("Engine Window Instance Created Successfully!");
	else Debug::LogError("Engine Window Instance is Null!");
	
	// Check if the renderer was successfully created.
	if (_renderer) Debug::Log("Engine Renderer Instance Created Successfully!");
	else Debug::LogError("Engine Renderer Instance is Null!");

	// Create a command thread.
	//Debug::CreateCommandThread();

	// Sets this GameManager to being Active.
	_isActive = true;
}

void EngineManager::Render()
{
	// Sets the colour of the renderer to black.
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);

	// Clears the entire screen to be this colour.
	SDL_RenderClear(_renderer);

	// Show the result of the Renderer stuff from before.
	SDL_RenderPresent(_renderer);
}

void EngineManager::Clean()
{
	//Debug::LogWarn("GameManager's Clean Function isnt implemented yet!");
}

void EngineManager::Stop()
{
	// Stop the command thread on exit otherwise it can cause a memory leak.
	Debug::StopCommandThread();
}

bool EngineManager::IsActive() 
{
	return _isActive;
}

void EngineManager::RemoveEntity(Entity* ent)
{
	remove(entityList.begin(), entityList.end(), ent);
	delete(ent);
	Debug::Log("Entity Destroyed!");
}

void EngineManager::Update()
{
	for (Entity* ent : entityList)
	{
		if (ent->active)
			ent->Update();
	}
}

void EngineManager::LateUpdate()
{
	for (Entity* ent : entityList)
	{
		if (ent->active)
			ent->LateUpdate();
	}
}