#ifndef BAMT_ENGINE_MANAGER
#define BAMT_ENGINE_MANAGER

#define BAMT_TIMESTEP_LIMIT 0.05f

#include "EngineSettings.h"
#include "Entity.h"
#include "SDL.h"
#include <SDL_image.h>
#include "Debug.h"
#include "TickTimer.h"
#include "Scene.h"

#include <vector>
#include <algorithm>

class EngineManager
{
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
	TickTimer* _tickTimer = nullptr;

	std::vector<Scene*> _sceneList;

	std::string _windowTitle;
	bool _isActive = false;
	bool fullScreen = false;
	int _deltaTime = 16;
	float _timeStep = 0;

	public:
		/// <summary>
		/// Returns if the Engine is active or not.
		/// </summary>
		bool IsActive() const;

		/// <summary>
		/// Creates an SDL Window and SDL Renderer and configures them.
		/// </summary>
		void Initialize(const char* windowName = "BAMT ENGINE",
			int windowWidth = 640, int windowHeight = 480,
			bool fullscreen = false,
			int deltaTime = 16);

		/// <summary>
		/// Loops Through Engine Logic.
		/// </summary>
		void RunLoop();

		/// <summary>
		/// Gets and runs special input functions.
		/// </summary>
		void DoInputLogic();

		/// <summary>
		/// Updates all active Scenes.
		/// </summary>
		void Update(float* timeStep) const;

		/// <summary>
		/// Renders all active scenes.
		/// </summary>
		void Render(SDL_Renderer* renderer) const;

		/// <summary>
		/// Stops the Engine.
		/// </summary>
		void Stop();

		void SetWindowTitle() const;

		/// SCENE FACTORY DECLARATION
		
		/// <summary>
		/// Creates an Entity of the specified type and adds it to the Entity List.
		/// </summary>
		template<class T = Scene, typename... TArgs>
		T* AddScene(TArgs&&... mArgs);

		/// <summary>
		/// Destroys a specified Entity and removes it from the Entity List.
		/// </summary>
		void RemoveScene(Scene* scene);

		//Constructor/Destructor
		EngineManager();
		~EngineManager();
};

/// SCENE FACTORY IMPLEMENTATION
// Putting it anywhere else is impossible due to the Template Stuff.

template<class T, typename... TArgs>
inline T* EngineManager::AddScene(TArgs&&... mArgs)
{
	// Create a new instance of this type and pass its arguments.
	T* scene = new T(std::forward<TArgs>(mArgs)...);

	// Use Dynamic Casting to find if the type given is derived from Entity.
	Scene* sceneBase = dynamic_cast<Scene*>(scene);
	if (sceneBase != nullptr)
	{
		_sceneList.emplace_back(sceneBase);
		sceneBase->engine = this;
		sceneBase->Start();
		Debug::Log("Scene Successfully Created!", scene);
		return scene;
	}

	Debug::LogError("This scene could not be created successfully!", scene);
	delete(scene);
	return nullptr;
}

inline void EngineManager::RemoveScene(Scene* scene)
{
	auto sceneToRemove = remove(_sceneList.begin(), _sceneList.end(), scene);
	delete(scene);
}

#endif