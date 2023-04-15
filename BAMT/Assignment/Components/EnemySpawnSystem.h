#ifndef ASSIGNMENT_ENEMY_SPAWN_SYSTEM
#define ASSIGNMENT_ENEMY_SPAWN_SYSTEM

#include <vector>
#include "Component.h"
#include "../Entities/Enemy.h"
#include "WeaponSystem/WeaponData.h"

class EnemySpawnSystem : public Component
{
	float time = 0;

	EntityPooler* enemyPool = nullptr;

	int maxZombieCount = 10;
	int maxRangerCount = 5;
	int maxTankCount = 3;

	public:
		std::vector<Vector2> spawnPoints;

		float spawnSpeedSeconds = 1.0f;

		void Start() override;
		void Update(float* timeStep) override;

		void SpawnEnemy() const;
		void SetDefaultTarget(Entity* newTarget);
		void AddSpawnPoint(Vector2 newSpawnPoint);
};
#endif