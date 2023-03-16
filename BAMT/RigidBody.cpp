#include "RigidBody.h"

void RigidBody::Start()
{
	_transform = entity->GetComponent<Transform>();

	// If we don't have a transform on this object for some reason.
	// Disable this component to prevent errors.
	if (_transform == nullptr)
	{
		Debug::LogWarn("Transform Component was not present on Entity with a RigidBody. Adding one now...");
		_transform = entity->AddComponent<Transform>();
	}
}

void RigidBody::Update(float* timeStep)
{
	// Simulate the next tick.
	const Vector2 stepPosition = Simulate(timeStep, _velocity, *_transform->GetPosition());

	// TODO: Look for colliders on this Entity, and find out if the position given is valid.

	_transform->SetPosition(&stepPosition);
}

void RigidBody::Render(SDL_Renderer* renderer){}

Vector2 RigidBody::Simulate(const float* timeStep, Vector2 velocity, Vector2 position)
{
	const float speed = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

	// If we are moving, apply drag to the body. 
	if (speed > 0) 
	{
		const float dragForce = drag * speed;
		velocity.x -= (velocity.x / speed) * dragForce * *timeStep;
		velocity.y -= (velocity.y / speed) * dragForce * *timeStep;
	}
	
	// Apply Gravity.
	velocity.x += gravity.x * *timeStep;
	velocity.y += gravity.y * *timeStep;

	// Slow us down if we are going too fast.
	if (speed > maxVelocity) 
	{
		velocity.x = (velocity.x / speed) * maxVelocity;
		velocity.y = (velocity.y / speed) * maxVelocity;
	}

	// Apply the newly made velocity to the position we are going to return.
	position.x += velocity.x * *timeStep;
	position.y += velocity.y * *timeStep;

	// Set the new velocity to be the velocity we calculated in here.
	_velocity = velocity;
	// Return the position
	return position;
}

void RigidBody::AddForce(Vector2 direction, float force)
{
	// We should assume that the direction we are given is already normalized.
	_velocity.x += direction.x * force;
	_velocity.y += direction.y * force;
}