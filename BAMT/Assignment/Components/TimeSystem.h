#ifndef ASSIGNMENT_TIME_SYSTEM
#define ASSIGNMENT_TIME_SYSTEM

#include "Component.h"
#include "TextRenderer.h"

class TimeSystem : public Component
{
	TextRenderer* timeText = nullptr;

	public:
		float currentTimeSeconds = 0;
		float timeLimitSeconds = 45;

		void Start() override;
		void Update(float* timeStep) override;
		void DisplayTime();
};
#endif