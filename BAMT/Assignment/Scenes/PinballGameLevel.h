#ifndef BAMT_PINBALL_GAME_LEVEL
#define BAMT_PINBALL_GAME_LEVEL

#include "../../Core/EngineSettings.h"
#include "../../Core/ECS/Scene.h"
#include "../../Core/Entities/CoordinateGrid.h"
#include "../Entities/Player.h"
#include "../Entities/StaticCollider.h"
#include "../Entities/Enemy.h"

class PinballGameLevel : public Scene
{
	Player* _player = nullptr;

	EntityPooler* enemyPool = nullptr;
	int maxEnemyCount = 5;

	public:
		void Start() override;
};
#endif