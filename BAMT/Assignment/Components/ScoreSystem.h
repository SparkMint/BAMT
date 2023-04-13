#ifndef ASSIGNMENT_SCORE_SYSTEM
#define ASSIGNMENT_SCORE_SYSTEM

#include "../../Core/ECS/Component.h"

class ScoreSystem : public Component
{
	float time = 0;
	float multiplierChangeTime = 10;

	int score = 0;
	int scoreMultiplier = 1;

	const int noScoreMultiplier = 1;
	const int lowScoreMultiplier = 2;
	const int medScoreMultiplier = 4;
	const int highScoreMultiplier = 8;

	public:
		bool doubleMultiplier;
		void AddScore(int scoreAmount);
		void Start() override;
		void Update(float* timeStep) override;

		void LowerScoreMultiplier();
		void RaiseScoreMultiplier();

};
#endif