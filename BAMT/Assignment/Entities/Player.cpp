#include "Player.h"

void Player::Start()
{
	tag = playerTag;

	// Transform Setup
	transform->SetPosition(&initialPosition);

	for (auto entity : scene->entityList)
	{
		if (entity->tag != "ScoreSystem") continue;

		auto* potentialScoreSystem = entity->GetComponent<ScoreSystem>();
		if (potentialScoreSystem == nullptr) continue;

		scoreSystem = potentialScoreSystem;
		Debug::Log("Found Score System");
	}
	if (scoreSystem == nullptr) Debug::LogWarn("No scoreSystem found on the player! Score will not be counted!", this);

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
	playerMovement->baseMovementSpeed = movementSpeed;
	playerMovement->currentMovementSpeed = movementSpeed;
	playerMovement->powerupMovementSpeed = movementSpeed * 2;

	// Set up the Projectile pool
	entityPool = AddComponent<EntityPooler>();
	for (int i = 0; i < projectilePoolCount; ++i)
	{
		auto* projectile = scene->AddEntity();
		projectile->AddComponent<Projectile>();
		entityPool->AddEntityToPool(projectile);

		if (scoreSystem == nullptr) continue;
		projectile->GetComponent<Projectile>()->scoreSystem = scoreSystem;
	}

	playerHealth = AddComponent<PlayerHealth>();
	playerHealth->scoreSystem = scoreSystem;

	// Pistol Setup
	weapon = AddComponent<PlayerWeapon>();
	weapon->weaponData = &pistolData;

	powerupReciever = AddComponent<PowerupReciever>();
	powerupReciever->scoreSystem = scoreSystem;
}