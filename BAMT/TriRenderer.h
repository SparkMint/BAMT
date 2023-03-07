#ifndef BAMT_TRIANGLE_RENDERER
#define BAMT_TRIANGLE_RENDERER

#include "Component.h"
#include "SDL.h"
#include "Transform.h"
#include "Entity.h"
#include "Debug.h"

class TriRenderer : public Component
{
	public:
		TriRenderer(short int size = 0);

		/// <summary>
		/// Transform of the entity we are attached to.
		/// </summary>
		Transform* transform;

		/// <summary>
		/// Size of the Triangle.
		/// </summary>
		short int size = 0;

		// Component overrides.
		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;
};
#endif