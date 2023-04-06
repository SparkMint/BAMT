#include "KeyboardMovement.h"

void KeyboardMovement::Start()
{
	 _rigidBody = entity->GetComponent<RigidBody>();

	 if (_rigidBody == nullptr)
	 {
		 Debug::LogError("KeyboardMovement cannot detect a RigidBody! Adding one now...", this);
		 _rigidBody = entity->AddComponent<RigidBody>();
	 }
}

void KeyboardMovement::Update(float* timeStep)
{
	if (Input::GetKeyHold(SDLK_w))
	{
		_rigidBody->AddReactionForce(VECTOR2_UP, movementSpeed);
	}
	if (Input::GetKeyHold(SDLK_s))
	{
		_rigidBody->AddReactionForce(VECTOR2_DOWN, movementSpeed);
	}
	if (Input::GetKeyHold(SDLK_a))
	{
		_rigidBody->AddReactionForce(VECTOR2_LEFT, movementSpeed);
	}
	if (Input::GetKeyHold(SDLK_d))
	{
		_rigidBody->AddReactionForce(VECTOR2_RIGHT, movementSpeed);
	}
}