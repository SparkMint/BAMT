#ifndef BAMT_ENGINE_MANAGER
#define BAMT_ENGINE_MANAGER

#include "SDL.h"
#include "Renderer.h"
#include "Debug.h"
#include "TickTimer.h"

#include <iostream>
#include <vector>


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


		/// <summary>
		/// Creates an SDL Window and Renderer and configures them.
		/// </summary>
		/// <param name="windowName">- The name of the window.</param>
		/// <param name="windowWidth">- The size of the window in width.</param>
		/// <param name="windowHeight">- The size of the window in height.</param>
		/// <param name="fullscreen">- Should the window be in fullscreen?</param>
		void Initialize(const char* windowName = "BAMT ENGINE", int windowWidth = 640, int windowHeight = 480, bool fullscreen = false);

		/// <summary>
		/// 
		/// </summary>
		void Update();

		/// <summary>
		/// 
		/// </summary>
		void Render();

		/// <summary>
		/// 
		/// </summary>
		void Clean();

		/// <summary>
		/// Stops Stuff attached to the EngineManager.
		/// </summary>
		void Stop();

		/// <summary>
		/// Checks if this instance is active.
		/// </summary>
		/// <returns>- Active state of the EngineManager.</returns>
		bool IsActive();

		Entity* AddEntity();
		void RemoveEntity(Entity* ent);
		void UpdateEntities();
		void LateUpdateEntities();

		/// <summary>
		/// Default Constructor.
		/// </summary>
		EngineManager();

		/// <summary>
		/// Default Destructor.
		/// </summary>
		~EngineManager();
};
#endif // !GAME_MANAGER