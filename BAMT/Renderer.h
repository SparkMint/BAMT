#ifndef BAMT_RENDERER
#define BAMT_RENDERER

#include "SDL.h"

class Renderer 
{
	public:
		Renderer();
		virtual void Render(SDL_Renderer* renderer);
};
#endif // !BAMT_RENDERER