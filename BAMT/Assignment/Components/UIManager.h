#ifndef ASSIGNMENT_UI_MANAGER
#define ASSIGNMENT_UI_MANAGER

#include "Component.h"
#include "ScoreSystem.h"
#include "TextRenderer.h"
#include "TimeSystem.h"
#include "WeaponSystem/WeaponData.h"

class UIManager : public Component
{
	public:
		void Start() override;
		void Update(float* timeStep) override;

		ScoreSystem* scoreSystem = nullptr;
		TimeSystem* timeSystem = nullptr;

		TextRenderer* scoreText = nullptr;
		TextRenderer* multiplierText = nullptr;
		TextRenderer* multiplierPowerupText = nullptr;
		TextRenderer* timeText = nullptr;
		TextRenderer* weaponText = nullptr;
		TextRenderer* gameOverText = nullptr;

		void UpdateScoreUI(int score) const;
		void UpdateMultiplierUI(int multiplier) const;
		void UpdateMultiplierPowerupUI(bool active);
		void UpdateTimeUI(int time) const;
		void UpdateWeaponUI(WeaponData* data) const;

		void Stop() const;
		void Reset() const;
};

#endif