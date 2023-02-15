#ifndef BAMT_ENGINE_MANAGER
#define BAMT_ENGINE_MANAGER

#include "SDL.h"
#include "BAMT.h"

#include <iostream>
#include <vector>

class Renderer;

class EngineManager
{
	private:
		bool _isActive;
		SDL_Window* _window;
		SDL_Renderer* _renderer;
		std::vector<Renderer*> _renderTargets;
		int _tick = 0;

	public:

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

		void AddRenderTarget(Renderer* renderTarget);

		/// <summary>
		/// Checks if this instance is active.
		/// </summary>
		/// <returns>- Active state of the EngineManager.</returns>
		bool IsActive();

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
