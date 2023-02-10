#ifndef GAMEMANAGER
#define GAMEMANAGER
#include "SDL.h"
#include "Debug.h"
#include "Input.h"

#include <iostream>

class GameManager
{
	private:
		bool isActive;
		SDL_Window* window;
		SDL_Renderer* renderer;

	public:
		void Initialise(const char* windowName = "BAMT ENGINE", int windowWidth = 640, int windowHeight = 480, bool fullscreen = false);
		void Update();
		void Render();
		void Clean();

		bool IsActive();

		GameManager();
		~GameManager();
};
#endif // !GAME
