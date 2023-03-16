#ifndef BAMT_ENGINE_MANAGER
#define BAMT_ENGINE_MANAGER

#include "Entity.h"
#include "SDL.h"
#include "Debug.h"
#include "TickTimer.h"

#include <vector>
#include <algorithm>

class EngineManager
{
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
	TickTimer* _tickTimer = nullptr;

	std::vector<Entity*> _entityList;

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
		/// Runs the engine loop.
		/// </summary>
		void RunLoop();

		/// <summary>
		/// Checks for special engine specific inputs.
		/// </summary>
		void CheckEngineInputs();

		/// <summary>
		/// Calls the Update function on all Entities attached to the Engine.
		/// </summary>
		void Update(float* timeStep) const;

		/// <summary>
		/// Renders the scene.
		/// </summary>
		void Render();

		/// <summary>
		/// Cleans any unused data from the Engine. TODO: Get this functioning.
		/// </summary>
		void Clean();

		/// <summary>
		/// Stops the Engine.
		/// </summary>
		void Stop();

		void SetWindowTitle() const;
		
		/// <summary>
		/// Creates an Entity of the specified type and adds it to the Entity List.
		/// </summary>
		template<class T = Entity, typename... TArgs>
		T* AddEntity(TArgs&&... mArgs);

		/// <summary>
		/// Destroys a specified Entity and removes it from the Entity List.
		/// </summary>
		void RemoveEntity(Entity* ent);

		/// <summary>
		/// Sorts all Entities in the _entityList by its renderLayer number.
		/// </summary>
		void SortEntities();


		//Constructor/Destructor
		EngineManager();
		~EngineManager();
};

// Implementation for Templates is easiest within the header file.
// Its annoying, but its the only way I can get this to work.

template<class T, typename... TArgs>
inline T* EngineManager::AddEntity(TArgs&&... mArgs)
{
	// Create a new instance of this type and pass its arguments.
	T* ent = new T(std::forward<TArgs>(mArgs)...);

	// Use Dynamic Casting to find if the type given is derived from Entity.
	Entity* entityBase = dynamic_cast<Entity*>(ent);
	if (entityBase != nullptr)
	{
		// Add the entity to our entity list.
		_entityList.emplace_back(entityBase);

		entityBase->engine = this;

		entityBase->Start();
		return ent;
	}

	// If it got here, the type we got wasn't an entity type.
	Debug::LogError("This entity could not be created successfully!", ent);
	delete(ent);
	return nullptr;
}
#endif