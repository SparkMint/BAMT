#include "Player.h"

void Player::Start()
{
	tag = playerTag;

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

	// Sprite Renderer Setup
	spriteRenderer = AddComponent<SpriteRenderer>(width, height, "bamt.png");


	// Player Movement Setup
	playerMovement = AddComponent<KeyboardMovement>();
	playerMovement->movementSpeed = movementSpeed;

	// Mouse Aim Setup
	mouseAim = AddComponent<MouseAim>();

	// Set up the Projectile pool
	entityPool = AddComponent<EntityPooler>();
	for (int i = 0; i < projectilePoolCount; ++i)
	{
		auto* projectile = scene->AddEntity();
		projectile->AddComponent<Projectile>();
		entityPool->AddEntityToPool(projectile);
	}

	// Pistol Setup
	weapon = AddComponent<PlayerWeapon>();
	weapon->weaponData = &pistolData;
}