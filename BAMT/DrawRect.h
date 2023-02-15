#ifndef DRAWRECT
#define DRAWRECT

#include "BAMT.h"
#include "SDL.h"
#include "Draw.h"

class Draw;

class DrawRect : public Draw 
{
	public:
		DrawRect(float xPos, float yPos, float width, float height);
		void Render(SDL_Renderer* renderer) override;

	private:
		float x;
		float y;
		float w;
		float h;
};
#endif // !DRAWRECT

