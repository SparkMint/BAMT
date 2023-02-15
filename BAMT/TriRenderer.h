#ifndef BAMT_TRIANGLE_RENDERER
#define BAMT_TRIANGLE_RENDERER

#include "BAMT.h"
#include "SDL.h"

class TriRenderer : public Renderer
{
public:
	TriRenderer(SDL_Point* p1 = new SDL_Point{ 100,100 }, SDL_Point* p2 = new SDL_Point{ 200,200 }, SDL_Point* p3 = new SDL_Point{ 100,200 });
	void Render(SDL_Renderer* renderer) override;

private:
	SDL_Point* point1;
	SDL_Point* point2;
	SDL_Point* point3;
};
#endif // !BAMT_TRIANGLE_RENDERER