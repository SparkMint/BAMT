#include "Player.h"

void Player::Start()
{
	tag = playerTag;

	// Transform Setup
	transform->SetPosition(&initialPosition);

	for (auto entity : scene->entityList)
	{
		auto* potentialScoreSystem = entity->GetComponent<ScoreSystem>();
		if (potentialScoreSystem == nullptr) continue;

		scoreSystem = potentialScoreSystem;
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

	powerupReciever = AddComponent<PowerupReciever>();
	powerupReciever->scoreSystem = scoreSystem;
}

void Player::Stop()
{
	weapon->entityPool->DisableAllEntities();
	playerMovement->Stop();

	active = false;
}

void Player::Reset()
{
	transform->SetPosition(&initialPosition);
	rigidBody->velocity = VECTOR2_ZERO;
	weapon->weaponData = &weapon->defaultWeapon;
	playerMovement->Reset();

	active = true;
}