#ifndef BAMT_RECTANGLE_RENDERER
#define BAMT_RECTANGLE_RENDERER

#include "Component.h"
#include "SDL.h"
#include "Transform.h"
#include "Entity.h"
#include "Debug.h"

class RectRenderer : public Component
{
	bool fillRect = false;
	SDL_Rect* rect = nullptr;
	Transform* _transform = nullptr;

	public:
		/// <summary>
		/// Constructs a rectangle with specified inputs.
		/// </summary>
		/// <param name="width">- The width of the Rectangle.</param>
		/// <param name="height">- The width of the Rectangle.</param>
		/// <param name="fill">- Should the rectangle be filled?</param>
		RectRenderer(int width = 0, int height = 0, bool fill = false);

		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;

		void UpdateSize(int x, int y);
};
#endif