#include "Player.h"

void Player::Start()
{
	// Transform Setup
	transform = AddComponent<Transform>();
	transform->SetPosition(&initialPosition);

	// Collider Setup
	boxCollider = AddComponent<BoxCollider>(rendererWidth, rendererHeight);
	boxCollider->DebugMode(true);

	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();
	rigidBody->maxVelocity = maxSpeed;
	rigidBody->drag = dragForce;
	rigidBody->gravity = gravity;
	rigidBody->debugMode = true;
	// Player Movement Setup
	playerMovement = AddComponent<PlayerMovement>();
	playerMovement->movementSpeed = movementSpeed;

	// Renderer Setup
	rectRenderer = AddComponent<RectRenderer>(rendererWidth, rendererHeight, fillRect);
	rectRenderer->enabled = false;
}