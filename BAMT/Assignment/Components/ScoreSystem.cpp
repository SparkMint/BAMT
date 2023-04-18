#include "ScoreSystem.h"

void ScoreSystem::Start()
{
}

void ScoreSystem::Update(float* timeStep)
{
	if(time < multiplierChangeTime)	time += *timeStep;
	else RaiseScoreMultiplier();

	int multiplier = scoreMultiplier;
	
	if (doubleMultiplier) multiplier = multiplier * 2;
	 
	if (uiManager != nullptr)
	{
		uiManager->UpdateMultiplierPowerupUI(doubleMultiplier);
		uiManager->UpdateMultiplierUI(multiplier);
	}
}
	
void ScoreSystem::AddScore(int scoreAmount)
{
	if (doubleMultiplier) score += (scoreAmount * scoreMultiplier) * 2;
	else score += scoreAmount * scoreMultiplier;

	if (uiManager != nullptr) uiManager->UpdateScoreUI(score);

	Debug::Log("Score: " + std::to_string(score));
	if (doubleMultiplier) Debug::Log("Multiplier was: " + std::to_string(scoreMultiplier * 2) + " with double powerup!");
	else Debug::Log("Multiplier was: " + std::to_string(scoreMultiplier) + ".");
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
}

void ScoreSystem::Reset()
{
	score = 0;
	doubleMultiplier = false;
	scoreMultiplier = 1;
}