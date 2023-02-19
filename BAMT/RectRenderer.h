#ifndef BAMT_RECTANGLE_RENDERER
#define BAMT_RECTANGLE_RENDERER

#include "Renderer.h"
#include "SDL.h"

class RectRenderer : public Component
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
		RectRenderer(int xPos = 0, int yPos = 0, int width = 0, int height = 0, bool fill = false);

		void Start() override;
		void Update() override;
		void LateUpdate() override;

		void Render(SDL_Renderer* renderer);

	private:
		SDL_Rect* rect;
		bool fillRect;
};
#endif // !BAMT_RECTANGLE_RENDERER