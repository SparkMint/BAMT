#include "EnemySpawnSystem.h"

void EnemySpawnSystem::Start()
{
	enemyPool = entity->AddComponent<EntityPooler>();

	for (int i = 0; i < maxZombieCount; ++i)
	{
		auto* enemy = entity->scene->AddEntity<Enemy>();
		enemy->maxHealth = 3;
		enemy->movementSpeed = 10;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .3f;
		enemy->height = .3f;

		// RB Stuff
		enemy->maxSpeed = 20;
		enemy->mass = .6f;
		enemy->dragForce = 5;
		enemy->bounciness = .2f;
		enemy->weaponData = WEAPON_DATA_ZOMBIE;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->active = false;
	}

	for (int i = 0; i < maxRangerCount; ++i)
	{
		auto* enemy = entity->scene->AddEntity<Enemy>();
		enemy->maxHealth = 8;
		enemy->movementSpeed = 3;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .5f;
		enemy->height = .5f;

		// RB Stuff
		enemy->maxSpeed = 20;
		enemy->mass = .6f;
		enemy->dragForce = 5;
		enemy->bounciness = .4f;
		enemy->weaponData = WEAPON_DATA_RANGER;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->active = false;
	}

	for (int i = 0; i < maxTankCount; ++i)
	{
		auto* enemy = entity->scene->AddEntity<Enemy>();
		enemy->maxHealth = 10;
		enemy->movementSpeed = 10;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .8f;
		enemy->height = .8f;

		// RB Stuff
		enemy->maxSpeed = 20;
		enemy->mass = 10;
		enemy->dragForce = 5;
		enemy->bounciness = .2f;
		enemy->weaponData = WEAPON_DATA_TANK;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->active = false;
	}
}

void EnemySpawnSystem::Update(float* timeStep)
{
	if (time < spawnSpeedSeconds)
	{
		time += *timeStep;
	}
	else
	{
		time = 0;
		SpawnEnemy();
	}
}

void EnemySpawnSystem::SetDefaultTarget(Entity* newTarget)
{
	if (enemyPool == nullptr) return;

	for (Entity* entity : enemyPool->GetPoolVector())
	{
		auto enemy = dynamic_cast<Enemy*>(entity);

		if (enemy == nullptr) continue;
		enemy->UpdateTarget(newTarget);
	}
}

void EnemySpawnSystem::AddSpawnPoint(Vector2 newSpawnPoint)
{
	spawnPoints.push_back(newSpawnPoint);
}

void EnemySpawnSystem::DisableAllEnemies()
{
	for (auto enemy : enemyPool->GetPoolVector())
	{
		enemy->active = false;
	}
}

void EnemySpawnSystem::SpawnEnemy() const
{

	if(spawnPoints.empty())
	{
		Debug::LogWarn("EnemySpawnSystem does not have any spawn points specified.");
		return;
	}
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	Entity* enemyBase = enemyPool->GetRandomAvaliableObject();

	const auto enemy = dynamic_cast<Enemy*>(enemyBase);
	if (enemy == nullptr) return;
	enemy->Init();

	const int spawnPoint = rand() % spawnPoints.size();
	enemy->transform->SetPosition(&spawnPoints[spawnPoint]);

	enemy->active = true;
}
