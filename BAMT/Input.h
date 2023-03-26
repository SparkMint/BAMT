#ifndef BAMT_INPUT
#define BAMT_INPUT

#include "SDL.h"

namespace Input 
{
	/// <summary>
	/// Receives Inputs.
	/// </summary>
	void GetInputs();

	/// <summary>
	/// Returns the state of the requested key.
	/// </summary>
	bool GetKeyHold(SDL_Keycode key);

	/// <summary>
	/// Returns the state of the requested key.
	///	Only returns true if it was just pressed. Not if Held.
	/// </summary>
	bool GetKeyDown(const SDL_Keycode key);
}
#endif