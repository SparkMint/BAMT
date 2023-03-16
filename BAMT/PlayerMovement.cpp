#include "PlayerMovement.h"

#include "EngineManager.h"
#include "RectRenderer.h"

void PlayerMovement::Start()
{
	 _transform = entity->GetComponent<Transform>();
	 _rigidBody = entity->AddComponent<RigidBody>();

	 _distanceTest = entity->engine->AddEntity<>();
	 _distanceTest->AddComponent<Transform>()->Translate(200, 200);
	 _distanceTest->AddComponent<RectRenderer>()->UpdateSize(10, 10);
	 _distanceTest->GetComponent<RectRenderer>()->fillRect = true;


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
	 else
	 {
		 _rigidBody->maxVelocity = 10000;
		 _rigidBody->drag = 25;
		 _rigidBody->gravity = { 0, 0 };
	 }
}

void PlayerMovement::Update(float* timeStep)
{
	Debug::Log("Distance: " + std::to_string(VectorMath::Distance(*_transform->GetPosition(),
		*_distanceTest->GetComponent<Transform>()->GetPosition())));

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