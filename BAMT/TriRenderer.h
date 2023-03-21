#ifndef BAMT_TRIANGLE_RENDERER
#define BAMT_TRIANGLE_RENDERER

#include "Entity.h"
#include "Component.h"
#include "SDL.h"
#include "Transform.h"
#include "Debug.h"

class TriRenderer : public Component
{
	public:
		TriRenderer(int size = 0);

		/// <summary>
		/// Transform of the entity we are attached to.
		/// </summary>
		Transform* transform;

		/// <summary>
		/// Size of the Triangle.
		/// </summary>
		int size = 0;

		// Component overrides.
		void Start() override;
		void Render(SDL_Renderer* renderer) override;
};
#endif