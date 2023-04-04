#include "Player.h"

void Player::Start()
{
	// Transform Setup
	transform->SetPosition(&initialPosition);

	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();
	rigidBody->width = width;
	rigidBody->height = height;
	rigidBody->mass = mass;
	rigidBody->maxVelocity = maxSpeed;
	rigidBody->drag = dragForce;
	rigidBody->bounciness = bounciness;
	tag = "Player";
	// Player Movement Setup
	playerMovement = AddComponent<KeyboardMovement>();
	playerMovement->movementSpeed = movementSpeed;

	// Renderer Setup
	//rectRenderer = AddComponent<RectRenderer>(width, height, fillRect);

	mouseAim = AddComponent<MouseAim>();

	spriteRend = AddComponent<SpriteRenderer>(width, height, "Logo.png");

	pistolWeapon = AddComponent<PlayerWeapon>();
	pistolWeapon->projectileSpeed = 100;
	pistolWeapon->projectileSize = .2f;
	pistolWeapon->fireRate = .02f;
	pistolWeapon->projectileSprite = pistolSprite;
}
