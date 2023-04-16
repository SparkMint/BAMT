#include "ScoreSystem.h"

void ScoreSystem::Start()
{
	entity->tag = "ScoreSystem";

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
}

void ScoreSystem::Update(float* timeStep)
{
	if(time < multiplierChangeTime)
	{
		time += *timeStep;
	}
	else
	{
		RaiseScoreMultiplier();
	}
}

void ScoreSystem::AddScore(int scoreAmount)
{
	if (doubleMultiplier) score += (scoreAmount * scoreMultiplier) * 2;
	else score += scoreAmount * scoreMultiplier;

	Debug::Log("-------------");
	Debug::Log("Score Summary");
	Debug::Log("Enemy Value: " + std::to_string(scoreAmount));
	Debug::Log("Score is now: " + std::to_string(score));

	if (doubleMultiplier) Debug::Log("Multiplier was: " + std::to_string(scoreMultiplier * 2) + " with double powerup!");
	else Debug::Log("Multiplier was: " + std::to_string(scoreMultiplier) + ".");
	Debug::Log("-------------\n");

	std::string scoreString = "Score: " + std::to_string(score);

	scoreText->SetText(scoreString.c_str());
}

void ScoreSystem::LowerScoreMultiplier()
{
	time = 0;
	if(scoreMultiplier == lowScoreMultiplier)
	{
		scoreMultiplier = noScoreMultiplier;
	}
	else if (scoreMultiplier == medScoreMultiplier)
	{
		scoreMultiplier = lowScoreMultiplier;
	}

	else if (scoreMultiplier == highScoreMultiplier)
	{
		scoreMultiplier = medScoreMultiplier;
	}

	Debug::Log("Score Multiplier lowered!");
	UpdateMultiplierText();
}

void ScoreSystem::RaiseScoreMultiplier()
{
	time = 0;
	if (scoreMultiplier == noScoreMultiplier)
	{
		scoreMultiplier = lowScoreMultiplier;
	}
	else if (scoreMultiplier == lowScoreMultiplier)
	{
		scoreMultiplier = medScoreMultiplier;
	}
	else if (scoreMultiplier == medScoreMultiplier)
	{
		scoreMultiplier = highScoreMultiplier;
	}

	Debug::Log("Score Multiplier Raised!");
	UpdateMultiplierText();
}

void ScoreSystem::UpdateMultiplierText()
{
	int multiplierAmount = scoreMultiplier;
	if (doubleMultiplier) multiplierAmount *= 2;

	switch (multiplierAmount)
	{
		case 1:
			multiplierText->colour = BAMT_COLOUR_WHITE;
			multiplierText->width = multiplierText->height = .5f;
			break;
		case 2:
			multiplierText->colour = BAMT_COLOUR_GREEN;
			multiplierText->width = multiplierText->height = .6f;
			break;
		case 4:
			multiplierText->colour = BAMT_COLOUR_YELLOW;
			multiplierText->width = multiplierText->height = .8f;
			break;
		case 8:
			multiplierText->colour = BAMT_COLOUR_RED;
			multiplierText->width = multiplierText->height = 1;
			break;
		case 16:
			multiplierText->colour = BAMT_COLOUR_CYAN;
			multiplierText->width = multiplierText->height = 1.2f;
			break;
	}

	std::string multiplier = "X" + std::to_string(multiplierAmount);

	multiplierText->SetText(multiplier.c_str());
}