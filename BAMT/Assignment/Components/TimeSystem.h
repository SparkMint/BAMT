#ifndef ASSIGNMENT_TIME_SYSTEM
#define ASSIGNMENT_TIME_SYSTEM

#include "Component.h"

class TimeSystem : public Component
{
	public:
		float currentTimeSeconds = 0;
		float timeLimitSeconds = 45;

		void Start() override;
		void Update(float* timeStep) override;

		void Stop();
		void Reset();
};
#endif