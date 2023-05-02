#include "TimeSystem.h"

#include "Entity.h"

void TimeSystem::Start()
{
	currentTimeSeconds = timeLimitSeconds;

	scoreSystem = entity->GetComponent<ScoreSystem>();
}

void TimeSystem::Update(float* timeStep)
{
	if (currentTimeSeconds > 0)
	{
		currentTimeSeconds -= *timeStep;
	}

	if (scoreSystem == nullptr) return;
	if(!timeExtended && scoreSystem->score > timeExtendScoreRequirement)
	{
		timeExtended = true;
		currentTimeSeconds += 15;
	}
}

void TimeSystem::Stop()
{
	enabled = false;
	timeExtended = false;
}

void TimeSystem::Reset()
{
	enabled = true;
	timeExtended = false;
	currentTimeSeconds = timeLimitSeconds;
}