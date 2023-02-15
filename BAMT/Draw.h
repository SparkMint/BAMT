#ifndef DRAW
#define DRAW

#include "BAMT.h"
#include "SDL.h"

class Draw 
{
	public:
		Draw();
		virtual void Render(SDL_Renderer* renderer);
};
#endif // !DRAW