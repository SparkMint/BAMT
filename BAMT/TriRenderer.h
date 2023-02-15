#ifndef BAMT_TRIANGLE_RENDERER
#define BAMT_TRIANGLE_RENDERER

#include "BAMT.h"
#include "SDL.h"

class TriRenderer : public Renderer
{
public:
	/// <summary>
	/// Draws an Equilateral triangle.
	/// </summary>
	/// <param name="position">- Center Position of the Triangle.</param>
	/// <param name="size">- Size of the triangle.</param>
	TriRenderer(SDL_Point* position, int size);

	/// <summary>
	/// Draws a Triangle with specific points.
	/// </summary>
	/// <param name="p1"></param>
	/// <param name="p2"></param>
	/// <param name="p3"></param>
	TriRenderer(SDL_Point* p1 = new SDL_Point{ 100,100 }, SDL_Point* p2 = new SDL_Point{ 200,200 }, SDL_Point* p3 = new SDL_Point{ 100,200 });

	/// <summary>
	/// Renders the Triangle.
	/// </summary>
	/// <param name="renderer">- The renderer that should render this triangle.</param>
	void Render(SDL_Renderer* renderer) override;

private:
	SDL_Point* point1;
	SDL_Point* point2;
	SDL_Point* point3;
};
#endif // !BAMT_TRIANGLE_RENDERER