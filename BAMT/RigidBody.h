#ifndef BAMT_RIGID_BODY
#define BAMT_RIGID_BODY

#include "Entity.h"
#include "Component.h"
#include "Transform.h"

class RigidBody : public Component
{
	Transform* _transform = nullptr;
	Vector2 _velocity;

	public:
		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;

		/// <summary>
		/// Simulates the next position this RigidBody will move to.
		/// </summary>
		void Simulate();

		/// <summary>
		/// Pushes this RigidBody in a specified direction.
		/// </summary>
		void AddForce(Vector2 direction, float force);

		Vector2 gravity;
		float linearDrag;
};
#endif