#include "PlayerMovement.h"

#include "EngineManager.h"

void PlayerMovement::Start()
{
	 _transform = entity->GetComponent<Transform>();

	// If we don't have a transform on this object for some reason.
	// Disable this component to prevent errors.
	 if (_transform == nullptr)
	 {
		 Debug::LogError("PlayerMovement Component Disabled. Transform Missing!");

		 enabled = false;
	 }
}

void PlayerMovement::Update(float* timeStep)
{
	const Vector2 previousVelocity = velocity;
	Accelerate(timeStep);
	DoDrag(&previousVelocity, timeStep);

	//Debug::Log("Velocity: " + std::to_string(velocity.x) + " " + std::to_string(velocity.y));
	_transform->Translate(velocity.x * *timeStep, velocity.y * *timeStep);
}



void PlayerMovement::Accelerate(const float* timeStep)
{
	if (Input::GetKeyDown(SDLK_w) && velocity.y > -maxSpeed)
	{
		velocity.y += -accelerationSpeed * *timeStep;
	}
	if (Input::GetKeyDown(SDLK_s) && velocity.y < maxSpeed)
	{
		velocity.y += accelerationSpeed * *timeStep;
	}

	if (Input::GetKeyDown(SDLK_a) && velocity.x > -maxSpeed)
	{
		velocity.x += -accelerationSpeed * *timeStep;
	}
	if (Input::GetKeyDown(SDLK_d) && velocity.x < maxSpeed)
	{
		velocity.x += accelerationSpeed * *timeStep;
	}
}

void PlayerMovement::DoDrag(const Vector2* previousVelocity, const float* timeStep)
{
	const Vector2 normalizedVelocity = velocity.Normalize();
	if(previousVelocity->x == velocity.x)
		velocity.x += (normalizedVelocity.x * -drag) * *timeStep;
	if (previousVelocity->y == velocity.y)
		velocity.y += (normalizedVelocity.y * -drag) * *timeStep;

	if (velocity.x < stopThreshold && velocity.x > -stopThreshold)
	{
		velocity.x = 0;
	}
	if(velocity.y < stopThreshold && velocity.y > -stopThreshold)
	{
		velocity.y = 0;
	}
}

void PlayerMovement::Render(SDL_Renderer* renderer)
{
}