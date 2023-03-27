#include "Input.h"

#include <unordered_map>

#include "Debug.h"

namespace Input
{
	/// <summary>
	/// All Keys that SDL supports.
	/// </summary>
	std::unordered_map<int, bool> _keyStatesLastFrame;
	std::unordered_map<int, bool> _keyStates;

	void GetInputs()
	{
		_keyStatesLastFrame = _keyStates;
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					_keyStates[SDL_QUIT] = true;
					break;

				case SDL_WINDOWEVENT_MOVED:
					_keyStates[SDL_WINDOWEVENT_MOVED] = true;
					break;

				case SDL_KEYDOWN:
						_keyStates[event.key.keysym.sym] = true;
					break;

				case SDL_KEYUP:
						_keyStates[event.key.keysym.sym] = false;
					break;

				default: 
					break;
			}
		}
	}

	bool GetKeyHold(const SDL_Keycode key)
	{
		return _keyStates[key];
	}

	bool GetKeyDown(const SDL_Keycode key)
	{
		return !_keyStatesLastFrame[key] && _keyStates[key];
	}
}
