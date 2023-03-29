#include "PhysicsCube.h"

void PhysicsCube::Start()
{
	// Transform Setup
	transform->SetPosition(&initialPosition);

	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();
	rigidBody->colliderWidth = width;
	rigidBody->colliderHeight = height;
	rigidBody->mass = mass;
	rigidBody->maxVelocity = maxSpeed;
	rigidBody->drag = dragForce;
	rigidBody->bounciness = bounciness;
	// PhysicsCube Movement Setup
	playerMovement = AddComponent<PhysicsMovement>();
	playerMovement->movementSpeed = movementSpeed;

	// Renderer Setup
	//rectRenderer = AddComponent<RectRenderer>(width, height, fillRect);

	spriteRend = AddComponent<SpriteRenderer>(width, height, "Logo.png");
}