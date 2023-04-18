#ifndef BAMT_ENGINE_MANAGER
#define BAMT_ENGINE_MANAGER
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "EngineSettings.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "ECS/Entity.h"
#include "SDL.h"
#include "Misc/Debug.h"
#include "Misc/TickTimer.h"
#include "ECS/Scene.h"
#include "Misc/Input.h"
#include <experimental/filesystem>

#include <vector>
#include <algorithm>

#include "Misc/AssetWarehouse.h"

class EngineManager
{
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
	TickTimer* _tickTimer = nullptr;
	std::experimental::filesystem::path textureFileRootDir = "Assets";

	std::vector<Scene*> _sceneList;

	std::string _windowTitle;
	bool _isActive = false;
	bool fullScreen = false;
	int _deltaTime = 16;
	float _timeStep = 0;

	public:
		AssetWarehouse* assetWarehouse = nullptr;

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

	std::string className = typeid(*scene).name();
	size_t startPos = className.find_last_of(" ") + 1;

	// Use Dynamic Casting to find if the type given is derived from Entity.
	Scene* sceneBase = dynamic_cast<Scene*>(scene);
	if (sceneBase != nullptr)
	{
		_sceneList.emplace_back(sceneBase);
		sceneBase->engine = this;
		sceneBase->Start();

		Debug::Log(className.substr(startPos) + " (Scene) was created.", scene);
		return scene;
	}

	Debug::LogError(className.substr(startPos) + " (Scene) could not be created successfully. Not derived off Scene class.", scene);
	delete(scene);
	return nullptr;
}

inline void EngineManager::RemoveScene(Scene* scene)
{
	auto sceneToRemove = remove(_sceneList.begin(), _sceneList.end(), scene);
	delete(scene);
}
#endif