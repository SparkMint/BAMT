#include "TimeSystem.h"

void TimeSystem::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	currentTimeSeconds = timeLimitSeconds;

	timeText = entity->AddComponent<TextRenderer>();
	timeText->SetFont("Comfortaa.ttf");
	timeText->width = timeText->height = .5f;
	entity->transform->SetPosition(width / 4, .5f);
	entity->renderLayer = 1;

	DisplayTime();
}

void TimeSystem::Update(float* timeStep)
{
	if (currentTimeSeconds > 0)
	{
		currentTimeSeconds -= *timeStep;
		DisplayTime();
	}
}

void TimeSystem::DisplayTime()
{
	std::string timeToText = "Time Remaining : " + std::to_string((int)currentTimeSeconds);
	timeText->SetText(timeToText.c_str());
}