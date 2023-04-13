#ifndef BAMT_PINBALL_GAME_LEVEL
#define BAMT_PINBALL_GAME_LEVEL

#include "../Entities/StaticCollider.h"
#include "../../Core/ECS/Scene.h"
#include "../../Core/Entities/CoordinateGrid.h"
#include "../Entities/Player.h"
#include "../Components/ScoreSystem.h"
#include "../Entities/Enemy.h"

class PinballGameLevel : public Scene
{
	float time = 0;

	Player* _player = nullptr;

	EntityPooler* enemyPool = nullptr;

	int maxRangedCount = 10;
	int maxZombieCount = 20;
	int maxTankCount = 8;
	std::vector<Entity*> spawnPoints;

	public:
		float enemySpawnSpeedSeconds = 1;

		ScoreSystem* scoreSystem = nullptr;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif