#ifndef BAMT_RECTANGLE_RENDERER
#define BAMT_RECTANGLE_RENDERER

#include "BAMT.h"
#include "SDL.h"

class RectRenderer : public Renderer 
{
	public:
		/// <summary>
		/// Constructs a rectangle with specified inputs.
		/// </summary>
		/// <param name="xPos">- The X Coordinate on the window.</param>
		/// <param name="yPos">- The Y Coordinate on the window.</param>
		/// <param name="width">- The width of the Rectangle.</param>
		/// <param name="height">- The width of the Rectangle.</param>
		/// <param name="fill">- Should the rectangle be filled?</param>
		RectRenderer(float xPos = 0, float yPos = 0, float width = 0, float height = 0, bool fill = false);

		void Render(SDL_Renderer* renderer) override;

	private:
		SDL_Rect* rect;
		bool fillRect;
};
#endif // !BAMT_RECTANGLE_RENDERER

