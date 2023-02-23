#ifndef BAMT_PLAYER_INPUT
#define BAMT_PLAYER_INPUT
#include "Component.h"
#include "Transform.h"

class PlayerInput : public Component
{
	public:
		/// <summary>
		/// Transform of the entity we are attached to.
		/// </summary>
		Transform* transform;

		/// <summary>
		/// How fast this object can move.
		/// </summary>
		int movementSpeed = 2;

		void Start() override;

		void Update() override;

		void Render(SDL_Renderer* renderer) override;
};
#endif