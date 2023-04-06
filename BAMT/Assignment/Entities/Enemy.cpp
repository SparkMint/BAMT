#include "Enemy.h"

void Enemy::Start()
{
	Entity::Start();

	tag = enemyTag;

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
	spriteRenderer = AddComponent<SpriteRenderer>(width, height, "default.png");


	// Player Movement Setup
	movement = AddComponent<EnemyMovement>();
	movement->movementSpeed = movementSpeed;

	// Set up the Projectile pool
	entityPool = AddComponent<EntityPooler>();
	for (int i = 0; i < projectilePoolCount; ++i)
	{
		auto* projectile = scene->AddEntity();
		projectile->AddComponent<Projectile>();
		entityPool->AddEntityToPool(projectile);
	}

	// Weapon Setup
	weapon = AddComponent<EnemyWeapon>();
	weapon->weaponData = &weaponData;
}

void Enemy::Update(float* timeStep)
{
	Entity::Update(timeStep);
}

void Enemy::UpdateTarget(Entity* newTarget)
{
	target = newTarget;

	movement->target = newTarget;
	weapon->target = newTarget;
}
