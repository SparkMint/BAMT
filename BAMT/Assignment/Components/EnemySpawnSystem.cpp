#include "EnemySpawnSystem.h"

void EnemySpawnSystem::Start()
{
	enemyPool = entity->AddComponent<EntityPooler>();

	for (int i = 0; i < maxZombieCount; ++i)
	{
		auto* enemy = entity->scene->AddEntity<Enemy>();
		enemy->maxHealth = 2;
		enemy->movementSpeed = 15;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .4f;
		enemy->height = .4f;

		// RB Stuff
		enemy->maxSpeed = 40;
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
		enemy->maxHealth = 3;
		enemy->movementSpeed = 1;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .5f;
		enemy->height = .5f;

		// RB Stuff
		enemy->maxSpeed = 40;
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
		enemy->maxHealth = 8;
		enemy->movementSpeed = 5;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .8f;
		enemy->height = .8f;

		// RB Stuff
		enemy->maxSpeed = 40;
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

void EnemySpawnSystem::SpawnEnemy() const
{
	if(spawnPoints.empty())
	{
		Debug::LogWarn("EnemySpawnSystem does not have any spawn points specified.");
		return;
	}

	Entity* enemyBase = enemyPool->GetRandomAvaliableObject();

	const auto enemy = dynamic_cast<Enemy*>(enemyBase);
	if (enemy == nullptr) return;
	enemy->Init();

	const int spawnPoint = rand() % spawnPoints.size();
	enemy->transform->SetPosition(&spawnPoints[spawnPoint]);

	enemy->active = true;
}