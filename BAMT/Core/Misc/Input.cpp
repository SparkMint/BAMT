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


	std::unordered_map<int, bool> _mouseStateLastFrame;
	std::unordered_map<int, bool> _mouseStates;

	void GetInputs()
	{
		_keyStatesLastFrame = _keyStates;
		_mouseStateLastFrame = _mouseStates;
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

				case SDL_MOUSEBUTTONDOWN:
					_mouseStates[event.button.button] = true;
					break;

				case SDL_MOUSEBUTTONUP:
					_mouseStates[event.button.button] = false;
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

	bool GetMouseButtonHold(const int button)
	{
		return _mouseStates[button];
	}

	bool GetMouseButtonDown(const int button)
	{
		return !_mouseStateLastFrame[button] && _mouseStates[button];
	}

	Vector2 GetMousePosition()
	{
		// Get the mouses X and Y position.
		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);

		// Get the scale between the Real and Reference Width and Height.
		constexpr float scaleX = (float)BAMT_RESOLUTION_WIDTH / (float)BAMT_REFERENCE_RESOLUTION_WIDTH;
		constexpr float scaleY = (float)BAMT_RESOLUTION_HEIGHT / (float)BAMT_REFERENCE_RESOLUTION_HEIGHT;

		// Get the lowest of the two scales to use.
		const float scale = fminf(scaleX, scaleY);

		// Get the scaled width and height using that new scale.
		const float scaledWidth = (float)BAMT_REFERENCE_RESOLUTION_WIDTH * scale;
		const float scaledHeight = (float)BAMT_REFERENCE_RESOLUTION_HEIGHT * scale;

		// Get the gap between the mouse and the position ingame to line them up properly.
		const float gapX = ((float)BAMT_RESOLUTION_WIDTH - scaledWidth) / 1.5f;
		const float gapY = ((float)BAMT_RESOLUTION_HEIGHT - scaledHeight) / 1.5f;

		// Calculate the actual mouse position.
		const float actualMouseX = ((float)mouseX / scale - gapX) / BAMT_WORLD_SCALE;
		const float actualMouseY = ((float)mouseY / scale - gapY) / BAMT_WORLD_SCALE;

		// Return it!
		return { actualMouseX, actualMouseY };
	}
}