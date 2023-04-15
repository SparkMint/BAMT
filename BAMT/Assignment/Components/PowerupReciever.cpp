#include "PowerupReciever.h"

void PowerupReciever::Start()
{
	movementSystem = entity->GetComponent<KeyboardMovement>();
}

void PowerupReciever::Update(float* timeStep)
{
	if(speedTime > 0) speedTime -= *timeStep;
	else if (movementSystem != nullptr)
	{
		movementSystem->currentMovementSpeed = movementSystem->baseMovementSpeed;
	}

	if(doublePointsTime > 0) doublePointsTime -= *timeStep;
	else
	{
		scoreSystem->doubleMultiplier = false;
		scoreSystem->UpdateMultiplierText();
	}
}

void PowerupReciever::ApplyPowerupEffects(PowerupType effect)
{
	switch(effect)
	{
		case speed:
			if (movementSystem == nullptr)
			{
				Debug::LogWarn("Speed Modifier cannot be applied due to there being no KeyboardMovement Referenced!", this);
				break;
			}
			Debug::Log("Speed Boost Collected!");
			movementSystem->currentMovementSpeed = movementSystem->powerupMovementSpeed;
			speedTime = powerupEffectTime;
			break;

		case doublePoints:
			if (scoreSystem == nullptr)
			{
				Debug::LogWarn("Score Multiplier cannot be applied due to there being no scoreSystem Referenced!", this);
				break;
			}
			Debug::Log("Score Multiplier Doubled!");
			scoreSystem->doubleMultiplier = true;
			scoreSystem->UpdateMultiplierText();
			doublePointsTime = powerupEffectTime;
			break;

		default: 
			Debug::Log("Powerup didn't have a valid type!", this);
			break;
	}
}