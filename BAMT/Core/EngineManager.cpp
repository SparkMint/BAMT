#define _CRT_SECURE_NO_WARNINGS
#include "EngineManager.h"


#pragma region Constructors
EngineManager::EngineManager()
{
	Debug::Log("Engine Instance Created.", this);
}
EngineManager::~EngineManager() 
{
	Debug::Log("Engine Instance Destroyed.", this);
	_isActive = false;
}
#pragma endregion Constructors

void EngineManager::Initialize(const char* windowName, int windowWidth, int windowHeight, bool fullscreen, int deltaTime)
{
	Debug::Log("ENGINE INIT STARTED! \n");

	const SDL_WindowFlags windowFlag = fullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
	fullScreen = fullscreen;
	_windowTitle = windowName;

	// Create an instance of a window.
	_window = SDL_CreateWindow(
		windowName,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		windowWidth, windowHeight,
		windowFlag);

	// Check if the window was successfully created.
	if (_window)
	{
		Debug::Log("WINDOW INFO");
		Debug::Log("------------------------");
		Debug::Log("Window", _window);
		Debug::Log("Resolution: " + std::to_string(BAMT_RESOLUTION_WIDTH) + " x " + std::to_string(BAMT_RESOLUTION_HEIGHT));
		Debug::Log("------------------------\n");
	}
	else Debug::LogError("Couldn't reate a Window!\n");

	// Create an instance of a Renderer and Check if the renderer was successfully created.
	_renderer = SDL_CreateRenderer(_window, -1, 0);
	// Forces the window to display the game in this aspect ratio.
	SDL_RenderSetLogicalSize(_renderer, BAMT_REFERENCE_RESOLUTION_WIDTH, BAMT_REFERENCE_RESOLUTION_HEIGHT);
	if (_renderer)
	{
		Debug::Log("RENDERER INFO");
		Debug::Log("------------------------");
		Debug::Log("Renderer", _window);
		Debug::Log("Window im rendering on: ", _window);
		Debug::Log("Logical Resolution: " + std::to_string(BAMT_REFERENCE_RESOLUTION_WIDTH) + " x " + std::to_string(BAMT_REFERENCE_RESOLUTION_HEIGHT));
		Debug::Log("------------------------\n");

	}
	else Debug::LogError("Couldn't create a Renderer!\n");

	// Create a new TickTimer.
	_tickTimer = new TickTimer();
	_deltaTime = deltaTime;

	Debug::Log("TICK INFO");
	Debug::Log("------------------------");
	Debug::Log("Timer", _tickTimer);
	Debug::Log("Delta Time: " + std::to_string(deltaTime) + "ms");
	Debug::Log("------------------------\n");

	Debug::Log("TEXTURE ATLAS");
	Debug::Log("------------------------");
	// Create a command thread.
	textureAtlas = new TextureAtlas();
	textureAtlas->FindSprites(textureFileRootDir, textureAtlas->png_files);
	textureAtlas->LoadTextures(_renderer);
	Debug::Log("Textures finished Loading!");
	Debug::Log("------------------------\n");

	// Give the input system a reference to this engine.
	Input::SetRenderer(_renderer);

	// Sets this GameManager to being Active.
	_isActive = true;

	Debug::Log("ENGINE INIT FINISHED!\n");
}

void EngineManager::RunLoop()
{
	while (IsActive())
	{
		int flags = SDL_GetWindowFlags(_window);

		_tickTimer->ResetTimer();

		DoInputLogic();

		if(flags & SDL_WINDOW_INPUT_FOCUS)
			Update(&_timeStep);

		Render(_renderer);

		SetWindowTitle();

		if (_tickTimer->GetTicks() < _deltaTime)
		{
			SDL_Delay(_deltaTime - _tickTimer->GetTicks());
		}
		_timeStep = _tickTimer->GetTicks() / 1000.f;

		if(_timeStep > BAMT_TIMESTEP_LIMIT)
		{
			Debug::LogWarn("Timestep too high! Value: " + std::to_string(_timeStep) + ". Clamping to " + std::to_string(0));
			Debug::LogWarn("Physics and other features might not work as intended!");

			_timeStep = 0;
		}
	}
	// After the loop has been broken out of, clear all memory.
	Stop();
}

void EngineManager::DoInputLogic()
{
	// Get all Inputs for this frame.
	Input::GetInputs();

	// If the player has given the command to stop. Stop the scene.
	if (Input::GetKeyHold(SDL_QUIT)) { _isActive = false; }

	// Fullscreen Toggle
	if(Input::GetKeyDown(SDLK_F11))
	{
		fullScreen = !fullScreen;
		const SDL_WindowFlags windowFlag = fullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
		SDL_SetWindowFullscreen(_window, windowFlag);
	}
	// Toggle Logs
	if (Input::GetKeyDown(SDLK_F6)){ Debug::ToggleLogs(); }
	// Toggle Warnings
	if (Input::GetKeyDown(SDLK_F7)){ Debug::ToggleWarns(); }
	// Toggle Errors
	if (Input::GetKeyDown(SDLK_F8)){ Debug::ToggleErrors(); }
}

void EngineManager::Update(float* timeStep) const
{
	//Debug::Log("TimeStep: " + std::to_string(*timeStep));
	for(auto* scene : _sceneList)
	{
		if (scene == nullptr) continue;
		if(scene->active || scene->alwaysActive)
			scene->Update(timeStep);
	}
}

void EngineManager::Render(SDL_Renderer* renderer) const
{
	// Sets the colour of the renderer to black.
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);

	// Clears the entire screen to be this colour.
	SDL_RenderClear(renderer);

	for (const auto* scene : _sceneList)
	{
		if (scene->active || scene->alwaysActive)
			scene->Render(renderer);
	}

	// Show the result of the Renderer stuff from before.
	SDL_RenderPresent(renderer);
}

void EngineManager::Stop()
{
	Debug::Log("Engine Stopping...", this);

	// When we delete a scene, it will cascade, deleting all its contents too
	for (auto* scene : _sceneList)
	{
		delete(scene);
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