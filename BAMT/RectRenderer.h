#ifndef BAMT_RECTANGLE_RENDERER
#define BAMT_RECTANGLE_RENDERER

#include "Colour.h"
#include "SDL.h"
#include "Debug.h"
#include "Renderer.h"

class Component;

class RectRenderer : public Renderer
{
	SDL_Rect* rect = nullptr;

	public:
		bool fillRect = false;
		float width = 1;
		float height = 1;

		Vector2 lastPosition;
		float minimumMovement = 0.02;


		/// <summary>
		/// Constructs a rectangle with specified inputs.
		/// </summary>
		/// <param name="Width">- The width of the Rectangle.</param>
		/// <param name="Height">- The width of the Rectangle.</param>
		/// <param name="Fill">- Should the rectangle be filled?</param>
		RectRenderer(float Width = 0, float Height = 0, bool Fill = false);

		void Start() override;
		void Render(SDL_Renderer* renderer) override;
		void UpdateSize(float x, float y) const;
};
#endif