#ifndef ASSIGNMENT_POWERUP_RECIEVER
#define ASSIGNMENT_POWERUP_RECIEVER

#include "KeyboardMovement.h"
#include "Component.h"
#include "Powerup.h"
#include "ScoreSystem.h"

enum PowerupType;

class PowerupReciever : public Component
{
	float speedTime = 0;
	float doublePointsTime = 0;

	float powerupEffectTime = 15;

	public:
		KeyboardMovement* movementSystem = nullptr;
		ScoreSystem* scoreSystem = nullptr;

		void Start() override;
		void Update(float* timeStep) override;
		void ApplyPowerupEffects(PowerupType effect);
};
#endif