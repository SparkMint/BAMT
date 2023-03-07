#include "Input.h"

#include "Debug.h"

namespace Input
{
	/// <summary>
	/// All Keys that SDL supports.
	/// </summary>
	bool Keys[512];

	bool shouldQuit = false;

	void GetInputs()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					shouldQuit = true;

				case SDL_KEYDOWN:
					if (event.key.keysym.sym >= 0 && event.key.keysym.sym <= 512) 
						Keys[event.key.keysym.sym] = true;
					break;

				case SDL_KEYUP:
					if (event.key.keysym.sym >= 0 && event.key.keysym.sym <= 512)
						Keys[event.key.keysym.sym] = false;
					break;

				default: 
					break;
			}
		}
	}

	bool GetKeyDown(const SDL_Keycode key)
	{
		if (key >= 0 && key <= 512)
		{
			return Keys[key];
		}
		Debug::LogError("The Key: " + std::to_string(key) + " is not valid.");
		return false;
		
	}

	bool CheckIfShouldQuit()
	{
		return shouldQuit;
	}
}
