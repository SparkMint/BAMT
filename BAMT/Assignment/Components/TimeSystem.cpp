#include "TimeSystem.h"

void TimeSystem::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	time = timeLimitSeconds;

	auto* textEnt = entity->scene->AddEntity();
	timeText = entity->AddComponent<TextRenderer>();
	timeText->SetFont("Comfortaa.ttf");
	timeText->width = timeText->height = .5f;
	entity->transform->SetPosition(width / 4, 1);
	entity->renderLayer = 1;

	DisplayTime();
}

void TimeSystem::Update(float* timeStep)
{
	if (time > 0)
	{
		time -= *timeStep;
		DisplayTime();
	}
	else
	{
		// TODO: Add end game.
	}
}

void TimeSystem::DisplayTime()
{
	Debug::Log("Time is " + std::to_string((int)time));
	std::string timeToText = "Time Remaining : " + std::to_string((int)time);
	timeText->SetText(timeToText.c_str());
}