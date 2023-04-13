#ifndef BAMT_PLAYER_MOVEMENT
#define BAMT_PLAYER_MOVEMENT

#include "../../Core/Misc/Input.h"
#include "../../Core/Components/RigidBody.h"
#include "../../Core/ECS/Component.h"

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