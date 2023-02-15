#ifndef BAMT_RECTANGLE
#define BAMT_RECTANGLE

#include "Renderer.h"
#include "SDL.h"


class RectRenderer : public Renderer 
{
	public:
		RectRenderer(float xPos, float yPos, float width, float height);
		void Render(SDL_Renderer* renderer) override;

	private:
		float x;
		float y;
		float w;
		float h;
};
#endif // !BAMT_RECTANGLE

