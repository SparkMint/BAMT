#ifndef BAMT_ENGINE_MANAGER
#define BAMT_ENGINE_MANAGER

#include "SDL.h"
#include "Debug.h"
#include "TickTimer.h"
#include <vector>

#include "Entity.h"


/// <summary>
/// Responsible for running the game loop and creating a SDL Window/Renderer to be used elsewhere.
/// </summary>
class EngineManager
{
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
		std::vector<Entity*> entityList;

		bool _isActive;

	public:
		TickTimer* tickTimer;

		bool IsActive();

		/// <summary>
		/// Creates an SDL Window and Renderer and configures them.
		/// </summary>
		/// <param name="windowName">- The name of the window.</param>
		/// <param name="windowWidth">- The size of the window in width.</param>
		/// <param name="windowHeight">- The size of the window in height.</param>
		/// <param name="fullscreen">- Should the window be in fullscreen?</param>
		void Initialize(const char* windowName = "BAMT ENGINE", int windowWidth = 640, int windowHeight = 480, bool fullscreen = false);

		void Update();

		void Render();

		void LateUpdate();

		void Clean();

		void Stop();


		// ECS Stuff.
		template<class T, typename... TArgs>
		T* AddEntity(TArgs&&... mArgs);
		void RemoveEntity(Entity* ent);


		//Constructor/Destructor
		EngineManager();
		~EngineManager();
};

// Implementation for AddEntity here because templates are stupid and seem to never work
// where I want them to.
template<class T, typename... TArgs>
inline T* EngineManager::AddEntity(TArgs&&... mArgs)
{
	Debug::Log("Creating Entity...");
	// Create a new instance of this type and pass its arguments.
	T* ent = (new T(std::forward<TArgs>(mArgs)...));

	// Try use Dynamic Casting to get the base component.
	Entity* entityBase = dynamic_cast<Entity*>(ent);
	if (entityBase != nullptr)
	{
		entityList.push_back(entityBase);
		entityBase->renderer = _renderer;
		Debug::Log("Entity Successfully Created!");
		return ent;
	}

	// If it got here, the type we got wasn't an entity type.
	Debug::Log("Entity was not created!");
	delete(ent);
	return nullptr;
}
#endif // !GAME_MANAGER