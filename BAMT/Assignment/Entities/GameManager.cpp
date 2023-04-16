#include "GameManager.h"

void GameManager::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	auto* gameOverEnt = scene->AddEntity();
	gameOverText = gameOverEnt->AddComponent<TextRenderer>();
	gameOverText->SetFont("Comfortaa.ttf");
	gameOverText->SetText("GAME OVER");
	gameOverText->colour = BAMT_COLOUR_RED;
	gameOverText->width = gameOverText->height = 2;
	gameOverEnt->transform->SetPosition(width / 6, height / 2);
	gameOverEnt->renderLayer = 1;
	gameOverText->enabled = false;

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

	if(timeSystem->currentTimeSeconds <= 0)
	{
		EndGame();
	}
}

void GameManager::EndGame()
{
	player->active = false;
	spawnSystem->DisableAllEnemies();
	gameOverText->enabled = true;
}