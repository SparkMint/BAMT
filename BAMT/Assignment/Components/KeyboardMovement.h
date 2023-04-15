#ifndef ASSIGNMENT_PLAYER_MOVEMENT
#define ASSIGNMENT_PLAYER_MOVEMENT

#include "Input.h"
#include "RigidBody.h"
#include "Component.h"

class KeyboardMovement : public Component
{
	RigidBody* _rigidBody = nullptr;

	public:
		float baseMovementSpeed = 2;
		float powerupMovementSpeed = 4;
		float currentMovementSpeed = 2;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif