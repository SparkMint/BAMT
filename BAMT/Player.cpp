#include "Player.h"

void Player::Start()
{
	// Transform Setup
	transform = AddComponent<Transform>();
	transform->SetPosition(&initialPosition);

	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();
	rigidBody->colliderWidth = rendererWidth;
	rigidBody->colliderHeight = rendererHeight;
	rigidBody->mass = mass;
	rigidBody->maxVelocity = maxSpeed;
	rigidBody->drag = dragForce;
	rigidBody->bounciness = bounciness;
	// Player Movement Setup
	playerMovement = AddComponent<PlayerMovement>();
	playerMovement->movementSpeed = movementSpeed;

	// Renderer Setup
	rectRenderer = AddComponent<RectRenderer>(rendererWidth, rendererHeight, fillRect);
	//rectRenderer->enabled = false;
}