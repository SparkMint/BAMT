#include "KeyboardMovement.h"

void KeyboardMovement::Start()
{
	 _rigidBody = entity->GetComponent<RigidBody>();

	 if (_rigidBody == nullptr)
	 {
		 Debug::LogError("KeyboardMovement cannot detect a RigidBody! Adding one now...", this);
		 _rigidBody = entity->GetComponent<RigidBody>();
	 }
}

void KeyboardMovement::Update(float* timeStep)
{
	if (Input::GetKeyHold(SDLK_w))
	{
		_rigidBody->AddForce(VECTOR2_UP, movementSpeed * *timeStep);
	}
	if (Input::GetKeyHold(SDLK_s))
	{
		_rigidBody->AddForce(VECTOR2_DOWN, movementSpeed * *timeStep);
	}
	if (Input::GetKeyHold(SDLK_a))
	{
		_rigidBody->AddForce(VECTOR2_LEFT, movementSpeed * *timeStep);
	}
	if (Input::GetKeyHold(SDLK_d))
	{
		_rigidBody->AddForce(VECTOR2_RIGHT, movementSpeed * *timeStep);
	}
	
}