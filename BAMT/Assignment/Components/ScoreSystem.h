#ifndef ASSIGNMENT_SCORE_SYSTEM
#define ASSIGNMENT_SCORE_SYSTEM

#include "Component.h"
#include "TextRenderer.h"

class ScoreSystem : public Component
{
	TextRenderer* scoreText = nullptr;
	TextRenderer* multiplierText = nullptr;

	float time = 0;
	float multiplierChangeTime = 10;

	int score = 0;
	int scoreMultiplier = 1;

	const int noScoreMultiplier = 1;
	const int lowScoreMultiplier = 2;
	const int medScoreMultiplier = 4;
	const int highScoreMultiplier = 8;

	public:
		void Start() override;
		void Update(float* timeStep) override;

		void AddScore(int scoreAmount);

		bool doubleMultiplier;
		void LowerScoreMultiplier();
		void RaiseScoreMultiplier();

		void UpdateMultiplierText();
};
#endif