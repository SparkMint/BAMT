#include "ScoreSystem.h"

#include "../../Core/ECS/Entity.h"

void ScoreSystem::AddScore(int scoreAmount)
{
	if(doubleMultiplier) score += (scoreAmount * scoreMultiplier) * 2;
	else score += scoreAmount * scoreMultiplier;
	Debug::Log("-------------");
	Debug::Log("Score Summary");
	Debug::Log("Enemy Value: " + std::to_string(scoreAmount));
	Debug::Log("Score is now: " + std::to_string(score));

	if(doubleMultiplier) Debug::Log("Multiplier was: " + std::to_string(scoreMultiplier * 2) + " with double powerup!");
	else Debug::Log("Multiplier was: " + std::to_string(scoreMultiplier) + ".");
	Debug::Log("-------------\n");
}

void ScoreSystem::Start()
{
	entity->tag = "ScoreSystem";
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

void ScoreSystem::LowerScoreMultiplier()
{
	time = 0;
	if(scoreMultiplier == lowScoreMultiplier)
		scoreMultiplier = noScoreMultiplier;

	else if (scoreMultiplier == medScoreMultiplier)
		scoreMultiplier = lowScoreMultiplier;

	else if (scoreMultiplier == highScoreMultiplier)
		scoreMultiplier = medScoreMultiplier;


	Debug::Log("Score Multiplier lowered!");
}

void ScoreSystem::RaiseScoreMultiplier()
{
	time = 0;
	if (scoreMultiplier == noScoreMultiplier)
		scoreMultiplier = lowScoreMultiplier;

	else if (scoreMultiplier == lowScoreMultiplier)
		scoreMultiplier = medScoreMultiplier;

	else if (scoreMultiplier == medScoreMultiplier)
		scoreMultiplier = highScoreMultiplier;

	Debug::Log("Score Multiplier Raised!");
}