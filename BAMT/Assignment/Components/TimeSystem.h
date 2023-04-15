#ifndef ASSIGNMENT_TIME_SYSTEM
#define ASSIGNMENT_TIME_SYSTEM

#include "Component.h"
#include "TextRenderer.h"

class TimeSystem : public Component
{
	float time = 0;
	TextRenderer* timeText = nullptr;

	public:
		float timeLimitSeconds = 45;

		void Start() override;
		void Update(float* timeStep) override;
		void DisplayTime();
};
#endif