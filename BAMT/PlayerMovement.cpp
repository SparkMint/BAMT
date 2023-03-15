#include "PlayerMovement.h"

#include "EngineManager.h"

void PlayerMovement::Start()
{
	 _transform = entity->GetComponent<Transform>();
	 _rigidBody = entity->AddComponent<RigidBody>();
	 _rigidBody->maxVelocity = 100000;
	 _rigidBody->drag = 1;
	 _rigidBody->gravity = { 0, 1000};

	// If we don't have a transform on this object for some reason.
	// Disable this component to prevent errors.
	 if (_transform == nullptr)
	 {
		 Debug::LogError("PlayerMovement Component Disabled. Transform Missing!");

		 enabled = false;
	 }

	 if (_rigidBody == nullptr)
	 {
		 Debug::LogError("PlayerMovement Component Disabled. RigidBody Missing!");

		 enabled = false;
	 }
}

void PlayerMovement::Update(float* timeStep)
{
	if (Input::GetKeyDown(SDLK_w))
	{
		_rigidBody->AddForce(VECTOR2_UP, accelerationSpeed);
	}
	if (Input::GetKeyDown(SDLK_s))
	{
		_rigidBody->AddForce(VECTOR2_DOWN, accelerationSpeed);
	}
	if (Input::GetKeyDown(SDLK_a))
	{
		_rigidBody->AddForce(VECTOR2_LEFT, accelerationSpeed);
	}
	if (Input::GetKeyDown(SDLK_d))
	{
		_rigidBody->AddForce(VECTOR2_RIGHT, accelerationSpeed);
	}
}

void PlayerMovement::Render(SDL_Renderer* renderer) {}