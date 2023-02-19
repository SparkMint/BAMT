#ifndef BAMT_RENDERER
#define BAMT_RENDERER

#include "SDL.h"
#include "Component.h"

class Renderer : public Component
{
	public:
		Renderer();
		virtual void Render(SDL_Renderer* renderer);
};
#endif // !BAMT_RENDERER