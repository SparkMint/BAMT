#ifndef BAMT_TRIANGLE_RENDERER
#define BAMT_TRIANGLE_RENDERER

#include "Component.h"
#include "Debug.h"
#include "SDL.h"
#include "Transform.h"

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
		void Update() override;
		void LateUpdate() override;

		/// <summary>
		/// Renders the Triangle.
		/// </summary>
		/// <param name="renderer">- The renderer that should render this triangle.</param>
		void Render(SDL_Renderer* renderer);
};
#endif