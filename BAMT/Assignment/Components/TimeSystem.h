#ifndef ASSIGNMENT_TIME_SYSTEM
#define ASSIGNMENT_TIME_SYSTEM

#include "Component.h"
#include "UIManager.h"

class TimeSystem : public Component
{
	public:
		UIManager* uiManager = nullptr;

		float currentTimeSeconds = 0;
		float timeLimitSeconds = 45;

		void Start() override;
		void Update(float* timeStep) override;

		void Stop();
		void Reset();
};
#endif