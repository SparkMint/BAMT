#include "Enemy.h"

void Enemy::Start()
{
	Entity::Start();

	for (auto entity : scene->entityList)
	{
		auto* potentialUI = entity->GetComponent<UIManager>();
		auto* potentialScoreSystem = entity->GetComponent<ScoreSystem>();

		if (potentialUI != nullptr)	uiManager = potentialUI;
		if (potentialScoreSystem != nullptr) scoreSystem = potentialScoreSystem;
	}

	if (uiManager == nullptr) Debug::LogWarn("No UI was found in this scene!", this);
	if (scoreSystem == nullptr) Debug::LogWarn("No ScoreSystem was found in this scene!", this);

	// Transform Setup
	transform->SetPosition(&initialPosition);

	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();

	// Player Movement Setup
	movement = AddComponent<EnemyMovement>();

	// Sprite Renderer Setup
	spriteRenderer = AddComponent<SpriteRenderer>(width, height, "default.png");

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

	health = AddComponent<EnemyHealth>(0);
}

void Enemy::Init()
{
	tag = enemyTag;

	rigidBody->width = width;
	rigidBody->height = height;
	rigidBody->mass = mass;
	rigidBody->maxVelocity = maxSpeed;
	rigidBody->drag = dragForce;
	rigidBody->bounciness = bounciness;
	rigidBody->velocity = VECTOR2_ZERO;

	spriteRenderer->SetSprite(sprite.c_str());
	spriteRenderer->height = height;
	spriteRenderer->width = width;

	movement->movementSpeed = movementSpeed;

	health->SetHealth(maxHealth);
	health->maxHealth = maxHealth;

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

void Enemy::Stop()
{
	weapon->entityPool->DisableAllEntities();
	health->DisablePowerup();

	active = false;
}

void Enemy::Restart()
{
	Init();
}