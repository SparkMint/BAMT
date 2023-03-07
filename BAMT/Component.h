#ifndef BAMT_COMPONENT
#define BAMT_COMPONENT
#include <SDL_render.h>

class Entity;

class Component 
{
	public:
		/// <summary>
		/// The entity we are attached to.
		/// </summary>
		Entity* entity = nullptr;

		/// <summary>
		/// Should this component run its logic?
		/// </summary>
		bool enabled = true;

		/// <summary>
		/// Called when this instance is loaded.
		/// </summary>
		virtual void Start() = 0;

		/// <summary>
		/// Called every tick.
		/// </summary>
		virtual void Update(float* timeStep) = 0;

		/// <summary>
		/// Used for rendering.
		/// </summary>
		virtual void Render(SDL_Renderer* renderer) = 0;
};
#endif