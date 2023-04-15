#include "GameManager.h"

void GameManager::Start()
{
	scoreSystem = AddComponent<ScoreSystem>();

	spawnSystem = AddComponent<EnemySpawnSystem>();

	timeSystem = AddComponent<TimeSystem>();

	player = scene->AddEntity<Player>();
	spawnSystem->SetDefaultTarget(player);

	Entity::Start();
}

void GameManager::Update(float* timeStep)
{
	Entity::Update(timeStep);
}