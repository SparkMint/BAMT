#define _CRT_SECURE_NO_WARNINGS
#include "EngineManager.h"

#include "Input.h"

#pragma region Constructors
EngineManager::EngineManager()
{
	Debug::Log("Engine Created.", this);
}
EngineManager::~EngineManager() 
{
	Debug::Log("Engine Destroyed.", this);
	_isActive = false;
}
#pragma endregion Constructors

void EngineManager::Initialize(const char* windowName, int windowWidth, int windowHeight, bool fullScreen, int deltaTime)
{
	const SDL_WindowFlags windowFlag = fullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

	_windowTitle = windowName;

	// Create an instance of a window.
	_window = SDL_CreateWindow(
		windowName,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		windowWidth, windowHeight,
		windowFlag);

	// Create an instance of a Renderer.
	_renderer = SDL_CreateRenderer(_window, -1, 0);

	// Create a new TickTimer.
	_tickTimer = new TickTimer();

	_deltaTime = deltaTime;
	Debug::Log("Delta Time = " + std::to_string(deltaTime));

	// Check if the window was successfully created.
	if (_window) Debug::Log("Engine Window Instance Created Successfully.", _window);
	else Debug::LogError("Engine Window Instance is Null!");
	
	// Check if the renderer was successfully created.
	if (_renderer) Debug::Log("Engine Renderer Instance Created Successfully.", _renderer);
	else Debug::LogError("Engine Renderer Instance is Null!");

	// Create a command thread.
	//Debug::CreateCommandThread();

	// Sets this GameManager to being Active.
	_isActive = true;
	Debug::Log("Engine Successfully Started.", this);
}

void EngineManager::RunLoop()
{
	while (IsActive())
	{
		_tickTimer->ResetTimer();

		Input::GetInputs();

		// If the player has given the command to stop. Stop the engine.
		if (Input::CheckIfShouldQuit())
		{
			Stop();
			break;
		}

		Update(&_timeStep);

		Render();

		// TODO: Implement this.
		Clean();

		SetWindowTitle();

		if (_tickTimer->GetTicks() < _deltaTime)
		{
			SDL_Delay(_deltaTime - _tickTimer->GetTicks());
		}
		_timeStep = _tickTimer->GetTicks() / 1000.f;
	}
}

void EngineManager::Render()
{
	// Sets the colour of the renderer to black.
	SDL_SetRenderDrawColor(_renderer, 0,0,0,255);

	// Clears the entire screen to be this colour.
	SDL_RenderClear(_renderer);

	// TODO: Have this run only when needed.
	SortEntities();

	for (const Entity* ent : _entityList)
	{
		if (ent->active)
			ent->Render(_renderer);
	}
	// Show the result of the Renderer stuff from before.
	SDL_RenderPresent(_renderer);
}

void EngineManager::Clean()
{
	//Debug::LogWarn("GameManager's Clean Function isnt implemented yet!");
}

void EngineManager::Stop()
{
	Debug::Log("Engine Stopping...", this);

	for (auto* ent : _entityList)
	{
		delete(ent);
	}
	SDL_Quit();
	delete(_tickTimer);
	delete(this);
}

void EngineManager::SetWindowTitle() const
{
	const int framesPerSecond = 1000 / _deltaTime - _tickTimer->GetTicks();
	const std::string windowString = _windowTitle + " | FPS : " + std::to_string(framesPerSecond);
	SDL_SetWindowTitle(_window, windowString.c_str());
}

bool EngineManager::IsActive() const
{
	return _isActive;
}

void EngineManager::RemoveEntity(Entity* ent)
{
	auto entity = remove(_entityList.begin(), _entityList.end(), ent);
	delete(ent);
}

void EngineManager::SortEntities()
{
	std::sort(_entityList.begin(), _entityList.end(), [](const Entity* a, const Entity* b)
	{return a->renderLayer < b->renderLayer;});
}

void EngineManager::Update(float* timeStep)
{
	for (Entity* ent : _entityList)
	{
		if (ent->active)
			ent->Update(timeStep);
	}
}
