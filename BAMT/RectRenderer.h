#ifndef BAMT_RECTANGLE_RENDERER
#define BAMT_RECTANGLE_RENDERER

#include "Component.h"
#include "SDL.h"
#include "Transform.h"

class RectRenderer : public Component
{
	SDL_Rect* rect;
	bool fillRect;

	public:
		/// <summary>
		/// Constructs a rectangle with specified inputs.
		/// </summary>
		/// <param name="width">- The width of the Rectangle.</param>
		/// <param name="height">- The width of the Rectangle.</param>
		/// <param name="fill">- Should the rectangle be filled?</param>
		RectRenderer(int width = 0, int height = 0, bool fill = false);

		/// <summary>
		/// Transform of the entity we are attached to.
		/// </summary>
		Transform* transform;

		void Start() override;
		void Update() override;
		void Render() override;

		/// <summary>
		/// Renders the Rectangle using an SDL Renderer.
		/// </summary>
		void DrawRectangle(SDL_Renderer* renderer);

		void UpdateSize(int x, int y);
};
#endif