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
	if (uiManager != nullptr) uiManager->UpdateTimeText((int)currentTimeSeconds);
}

void TimeSystem::Stop()
{
	if (uiManager != nullptr) uiManager->gameOverText->enabled = true;
	enabled = false;
}

void TimeSystem::Reset()
{
	enabled = true;
	currentTimeSeconds = timeLimitSeconds;
	if (uiManager != nullptr) uiManager->gameOverText->enabled = false;
}