#ifndef BAMT_RIGID_BODY
#define BAMT_RIGID_BODY

#include "Scene.h"
#include "Entity.h"
#include "Component.h"
#include "Transform.h"

class RigidBody : public Component
{
	Vector2 _velocity;

	// Stored Current timestep.
	float _timeStep = 0;

	/// <summary>
	/// Simulates the next position this RigidBody will move to.
	/// </summary>
	Vector2 Simulate(const float* timeStep, Vector2 velocity, Vector2 position);

	public:
		RigidBody();
		~RigidBody();

		/// <summary>
		/// Pointer to this RigidBodies transform.
		/// </summary>
		Transform* transform = nullptr;

		/// <summary>
		/// List of all objects currently colliding with this object.
		/// </summary>
		std::vector<RigidBody*> collisionList;

		/// <summary>
		/// If active, no external forces can affect this RigidBody.
		/// </summary>
		bool isKinematic = false;

		/// <summary>
		/// Activates Debug Logging for this RigidBody.
		/// </summary>
		bool debugMode = false;

		/// <summary>
		/// Width of the collider of this object.
		/// </summary>
		float colliderWidth = 1.0f;

		/// <summary>
		/// Width of the collider of this object.
		/// </summary>
		float colliderHeight = 1.0f;

		/// <summary>
		/// How heavy this RigidBody is. Or how hard it is to move.
		/// </summary>
		float mass = 1.0f;

		/// <summary>
		/// Slows the RigidBody down.
		/// </summary>
		float drag = 1.0f;

		/// <summary>
		/// How bouncy should this object be?
		/// </summary>
		float bounciness = 1.0f;

		/// <summary>
		/// The maximum speed this RigidBody can move.
		/// </summary>
		float maxVelocity = 1.0f;

		/// <summary>
		/// Pushes this RigidBody in a specified direction.
		/// </summary>
		void AddForce(Vector2 direction, float force);

		/// <summary>
		/// Pushes this RigidBody in a specified direction using an Impulse Force.
		/// </summary>
		void AddImpulseForce(Vector2 direction, float force);

		/// <summary>
		/// Returns the Velocity of this RigidBody
		/// </summary>
		Vector2 GetVelocity() const;

		void Start() override;
		void Update(float* timeStep) override;


};
#endif