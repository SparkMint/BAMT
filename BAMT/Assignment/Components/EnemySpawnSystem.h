#ifndef ASSIGNMENT_ENEMY_SPAWN_SYSTEM
#define ASSIGNMENT_ENEMY_SPAWN_SYSTEM

#include <vector>
#include "Component.h"
#include "../Entities/Enemy.h"
#include "EnemyData.h"

class EnemySpawnSystem : public Component
{
	float time = 0;

	EntityPooler* enemyPool = nullptr;

	int maxZombieCount = 20;
	int maxRangerCount = 5;
	int maxTankCount = 3;

	public:
		std::vector<Vector2> spawnPoints;

		float spawnSpeedSeconds = 0.6f;

		void Start() override;
		void Update(float* timeStep) override;

		void SpawnEnemy() const;
		void SetDefaultTarget(Entity* newTarget) const;
		void AddSpawnPoint(Vector2 newSpawnPoint);

		void Stop();
		void Reset();
};
#endif