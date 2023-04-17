#include "EnemySpawnSystem.h"

void EnemySpawnSystem::Start()
{
	enemyPool = entity->AddComponent<EntityPooler>();

	for (int i = 0; i < maxZombieCount; ++i)
	{
		auto* enemy = entity->scene->AddEntity<Enemy>();
		enemy->maxHealth = 2;
		enemy->movementSpeed = 10;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .3f;
		enemy->height = .3f;

		// RB Stuff
		enemy->maxSpeed = 10;
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
		enemy->maxHealth = 4;
		enemy->movementSpeed = 3;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .5f;
		enemy->height = .5f;

		// RB Stuff
		enemy->maxSpeed = 10;
		enemy->mass = .6f;
		enemy->dragForce = 5;
		enemy->bounciness = .2f;
		enemy->weaponData = WEAPON_DATA_RANGER;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->active = false;
	}

	for (int i = 0; i < maxTankCount; ++i)
	{
		auto* enemy = entity->scene->AddEntity<Enemy>();
		enemy->maxHealth = 7;
		enemy->movementSpeed = 10;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .8f;
		enemy->height = .8f;

		// RB Stuff
		enemy->maxSpeed = 10;
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

void EnemySpawnSystem::SetDefaultTarget(Entity* newTarget) const
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

void EnemySpawnSystem::Stop()
{
	for (auto enemyEnt : enemyPool->GetPoolVector())
	{
		const auto enemy = dynamic_cast<Enemy*>(enemyEnt);
		if (enemy == nullptr) return;
		enemy->Stop();
	}
	enabled = false;
}

void EnemySpawnSystem::Reset()
{
	for (auto enemyEnt : enemyPool->GetPoolVector())
	{
		const auto enemy = dynamic_cast<Enemy*>(enemyEnt);
		if (enemy == nullptr) return;
		enemy->Restart();
	}
	enabled = true;
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
