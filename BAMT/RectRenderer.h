#ifndef BAMT_RECTANGLE_RENDERER
#define BAMT_RECTANGLE_RENDERER

#include "BAMT.h"
#include "SDL.h"

class RectRenderer : public Renderer 
{
	public:
		RectRenderer(float xPos, float yPos, float width, float height);
		void Render(SDL_Renderer* renderer) override;

	private:
		SDL_Rect* rect;
};
#endif // !BAMT_RECTANGLE_RENDERER

