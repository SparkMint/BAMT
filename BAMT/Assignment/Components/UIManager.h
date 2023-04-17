#ifndef ASSIGNMENT_UI_MANAGER
#define ASSIGNMENT_UI_MANAGER

#include "Component.h"
#include "TextRenderer.h"
#include "WeaponSystem/WeaponData.h"

class UIManager : public Component
{
	public:
		void Start() override;
		void Update(float* timeStep) override;

		TextRenderer* scoreText = nullptr;
		TextRenderer* multiplierText = nullptr;
		TextRenderer* multiplierPowerupText = nullptr;
		TextRenderer* timeText = nullptr;
		TextRenderer* weaponText = nullptr;
		TextRenderer* gameOverText = nullptr;

		void UpdateScoreUI(int score);
		void UpdateMultiplierUI(int multiplier) const;
		void UpdateMultiplierPowerupUI(bool active);
		void UpdateTimeText(int time);
		void UpdateWeaponUI(WeaponData* data);
};

#endif