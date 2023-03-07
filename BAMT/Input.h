#ifndef BAMT_INPUT
#define BAMT_INPUT

#include "SDL.h"

namespace Input 
{
	/// <summary>
	/// Receives Inputs.
	/// </summary>
	void GetInputs();

	bool GetKeyDown(SDL_Keycode key);

	bool CheckIfShouldQuit();
}
#endif