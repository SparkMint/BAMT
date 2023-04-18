#include "UIManager.h"

void UIManager::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	auto* gameOverEnt = entity->scene->AddEntity();
	gameOverText = gameOverEnt->AddComponent<TextRenderer>();
	gameOverText->SetFont("Comfortaa.ttf");
	gameOverText->SetText("GAME OVER");
	gameOverText->colour = BAMT_COLOUR_RED;
	gameOverText->width = gameOverText->height = 2;
	gameOverEnt->transform->SetPosition(width / 6, height / 2);
	gameOverEnt->renderLayer = 1;
	gameOverText->enabled = false;

	auto* weaponTextEnt = entity->scene->AddEntity();
	weaponText = weaponTextEnt->AddComponent<TextRenderer>();
	weaponText->SetFont("Comfortaa.ttf");
	weaponText->colour = BAMT_COLOUR_WHITE;
	weaponText->width = weaponText->height = .5f;
	weaponTextEnt->transform->SetPosition(15, .5f);
	weaponTextEnt->renderLayer = 1;


	auto* scoreTextEnt = entity->scene->AddEntity();
	scoreText = scoreTextEnt->AddComponent<TextRenderer>();
	scoreText->width = scoreText->height = .5f;
	scoreText->SetFont("Comfortaa.ttf");
	scoreText->SetText("Score: 0");
	scoreTextEnt->transform->SetPosition(.5f, .5f);
	scoreTextEnt->renderLayer = 1;

	auto* multiplierTextEnt = entity->scene->AddEntity();
	multiplierText = multiplierTextEnt->AddComponent<TextRenderer>();
	multiplierText->width = multiplierText->height = .8f;
	multiplierText->SetFont("Comfortaa-Bold.ttf");
	multiplierText->SetText("X1");
	multiplierTextEnt->transform->SetPosition(.7f, 1.5f);
	multiplierTextEnt->renderLayer = 1;

	auto* doubleMultiplierEnt = entity->scene->AddEntity();
	multiplierPowerupText = doubleMultiplierEnt->AddComponent<TextRenderer>();
	multiplierPowerupText->width = multiplierPowerupText->height = .5f;
	multiplierPowerupText->SetFont("Comfortaa-Bold.ttf");
	multiplierPowerupText->SetText("DOUBLE MULTIPLIER!");
	multiplierPowerupText->colour = BAMT_COLOUR_YELLOW;
	doubleMultiplierEnt->transform->SetPosition(.7f, 2.5f);
	doubleMultiplierEnt->renderLayer = 1;

	auto* timeTextEnt = entity->scene->AddEntity();
	timeText = timeTextEnt->AddComponent<TextRenderer>();
	timeText->SetFont("Comfortaa.ttf");
	timeText->SetText("Time Remaining: 00");
	timeText->width = timeText->height = .5f;
	timeTextEnt->transform->SetPosition(5, .5f);
	timeTextEnt->renderLayer = 1;
}

void UIManager::Update(float* timeStep)
{

}

void UIManager::UpdateScoreUI(int score)
{
	if (scoreText == nullptr) return;
	std::string scoreString = "Score: " + std::to_string(score);
	scoreText->SetText(scoreString.c_str());
}

void UIManager::UpdateMultiplierUI(int multiplier) const
{
	if (multiplierText == nullptr) return;
	std::string multiplierString = "X" + std::to_string(multiplier);

	switch(multiplier)
	{
		case 1:
			multiplierText->colour = BAMT_COLOUR_WHITE;
			multiplierText->width = multiplierText->height = .6f;
			break;
		case 2:
			multiplierText->colour = BAMT_COLOUR_GREEN;
			multiplierText->width = multiplierText->height = .8f;
			break;
		case 4:
			multiplierText->colour = BAMT_COLOUR_YELLOW;
			multiplierText->width = multiplierText->height = 1;
			break;
		case 8:
			multiplierText->colour = BAMT_COLOUR_RED;
			multiplierText->width = multiplierText->height = 1.2f;
			break;
		case 16:
			multiplierText->colour = BAMT_COLOUR_CYAN;
			multiplierText->width = multiplierText->height = 1.4f;
			break;
	}

	multiplierText->SetText(multiplierString.c_str());
}

void UIManager::UpdateMultiplierPowerupUI(bool active)
{
	multiplierPowerupText->enabled = active;
}

void UIManager::UpdateTimeText(int time)
{
	if (timeText == nullptr) return;
	std::string timeString = "Time Remaining: " + std::to_string(time);
	timeText->SetText(timeString.c_str());
}

void UIManager::UpdateWeaponUI(WeaponData* data)
{
	if (weaponText == nullptr) return;
	std::string weaponString = "Weapon: " + data->weaponName;
	weaponText->SetText(weaponString.c_str());
}

void UIManager::Stop()
{
	gameOverText->enabled = true;
}

void UIManager::Reset()
{
	if (scoreText) UpdateScoreUI(0);
	gameOverText->enabled = false;
}