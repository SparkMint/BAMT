#ifndef ASSIGNMENT_GAME_MANAGER
#define ASSIGNEMNT_GAME_MANAGER

#include "Entity.h"
#include "Player.h"
#include "../Components/ScoreSystem.h"
#include "../Components/TimeSystem.h"
#include "../Components/EnemySpawnSystem.h"

class GameManager : public Entity
{
	public:
		ScoreSystem* scoreSystem = nullptr;
		EnemySpawnSystem* spawnSystem = nullptr;
		TimeSystem* timeSystem = nullptr;
		TextRenderer* gameOverText = nullptr;

		Player* player = nullptr;


		void Start() override;
		void Update(float* timeStep) override;

		void EndGame();
};
#endif