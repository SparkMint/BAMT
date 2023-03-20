#ifndef BAMT_RIGID_BODY
#define BAMT_RIGID_BODY

#include "Entity.h"
#include "Component.h"
#include "RectRenderer.h"
#include "Transform.h"

class RigidBody : public Component
{
	Vector2 _velocity;

	/// <summary>
	/// Simulates the next position this RigidBody will move to.
	/// </summary>
	Vector2 Simulate(const float* timeStep, Vector2 velocity, Vector2 position);

	public:
		RigidBody();
		~RigidBody();

		Transform* transform = nullptr;
		RectRenderer* debugRenderer = nullptr;

		std::vector<RigidBody*> collisionList;

		bool debugMode;

		/// <summary>
		/// Determines if the RigidBody can be simulated or not.
		///	This also prevents this object from detecting collisions.
		///	Other objects will still detect it.
		/// </summary>
		bool isStatic;


		/// <summary>
		/// If active, no external forces can affect this RigidBody.
		/// </summary>
		bool isKinematic;

		float colliderWidth;
		float colliderHeight;

		Vector2 gravity;
		float maxVelocity;
		float drag;

		void Start() override;
		void Update(float* timeStep) override;

		void ReactToCollisions(const RigidBody* otherRigidBody);

		/// <summary>
		/// Pushes this RigidBody in a specified direction.
		/// </summary>
		void AddForce(Vector2 direction, float force);


};

#endif