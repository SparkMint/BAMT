#ifndef ASSIGNMENT_PLAYER_MOVEMENT
#define ASSIGNMENT_PLAYER_MOVEMENT

#include "Input.h"
#include "RigidBody.h"
#include "Component.h"

class KeyboardMovement : public Component
{
	RigidBody* _rigidBody = nullptr;

	public:
		float baseMovementSpeed = 1;
		float powerupMovementSpeed = 2;
		float currentMovementSpeed = 1;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif