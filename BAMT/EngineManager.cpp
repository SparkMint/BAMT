#include "EngineManager.h"

EngineManager::EngineManager()
{
	Debug::Log("Engine Instance Created!");

	// Initialize variables.
	_isActive = false;
	_window = NULL;
	_renderer = NULL;
}

EngineManager::~EngineManager() 
{
	Debug::Log("Engine Instance Destroyed!");

	// Initialize variables.
	_isActive = false;

	_window = nullptr;
	_renderer = nullptr;
	delete _window;
	delete _renderer;
}


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

	// Check if the window was successfully created.
	if (_window) Debug::Log("Engine Window Instance Created Successfully!");
	else Debug::LogError("Engine Window Instance is Null!");
	

	// Check if the renderer was successfully created.
	if (_renderer) Debug::Log("Engine Renderer Instance Created Successfully!");
	else Debug::LogError("Engine Renderer Instance is Null!");



	// Sets this GameManager to being Active.
	_isActive = true;
}

void EngineManager::Update()
{
	Input::DoInput();
	_tick++;
}

void EngineManager::Render()
{
	
	// Sets the colour of the renderer to black.
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);

	// Clears the entire screen to be this colour.
	SDL_RenderClear(_renderer);

	// Show the result of the Renderer stuff from before.
	SDL_RenderPresent(_renderer);

	for (int i = 0; i < _drawTargets.size() - 1; i++)
	{
		_drawTargets[i]->Render(_renderer);
	}
}

void EngineManager::Clean()
{
	Debug::LogWarn("GameManager's Clean Function isnt implemented yet!");
}

void EngineManager::AddDrawTarget(Renderer* drawTarget)
{
	_drawTargets.push_back(drawTarget);
}

bool EngineManager::IsActive() 
{
	return _isActive;
}