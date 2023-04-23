#include "TimeSystem.h"

void TimeSystem::Start()
{
	currentTimeSeconds = timeLimitSeconds;
}

void TimeSystem::Update(float* timeStep)
{
	if (currentTimeSeconds > 0)
	{
		currentTimeSeconds -= *timeStep;
	}
}

void TimeSystem::Stop()
{
	enabled = false;
}

void TimeSystem::Reset()
{
	enabled = true;
	currentTimeSeconds = timeLimitSeconds;
}