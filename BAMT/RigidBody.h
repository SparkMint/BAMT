#ifndef BAMT_RIGID_BODY
#define BAMT_RIGID_BODY

#include "Entity.h"
#include "Component.h"
#include "Transform.h"

class RigidBody : public Component
{
	Transform* _transform = nullptr;
	Vector2 _velocity;

	/// <summary>
	/// Simulates the next position this RigidBody will move to.
	/// </summary>
	Vector2 Simulate(const float* timeStep, Vector2 velocity, Vector2 position);

	public:
		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;

		/// <summary>
		/// Pushes this RigidBody in a specified direction.
		/// </summary>
		void AddForce(Vector2 direction, float force);

		Vector2 gravity;
		float maxVelocity;
		float drag;
};
#endif