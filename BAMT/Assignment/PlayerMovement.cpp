#include "PlayerMovement.h"

#include "../Core/EngineManager.h"
#include "../Core/Components/RectRenderer.h"

void PlayerMovement::Start()
{
	 _transform = entity->GetComponent<Transform>();
	 _rigidBody = entity->GetComponent<RigidBody>();


	// If we don't have a _transform on this object for some reason.
	// Disable this component to prevent errors.
	 if (_transform == nullptr)
	 {
		 Debug::LogError("PlayerMovement cannot detect a Transform! Adding one now...", this);
		 _transform = entity->AddComponent<Transform>();
		 //enabled = false;
	 }

	 if (_rigidBody == nullptr)
	 {
		 Debug::LogError("PlayerMovement cannot detect a RigidBody! Adding one now...", this);
		 _rigidBody = entity->GetComponent<RigidBody>();
		 //enabled = false;
	 }
}

void PlayerMovement::Update(float* timeStep)
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
	if(Input::GetKeyDown(SDLK_f))
	{
		if(entity->scene->gravity == _zeroGravity)
		{
			Debug::Log("Gravity Enabled!", this);
			entity->scene->gravity = _Gravity;
		}
		else
		{
			Debug::Log("Gravity Disabled!", this);
			entity->scene->gravity = _zeroGravity;
		}
	}
}

void PlayerMovement::Render(SDL_Renderer* renderer) {}