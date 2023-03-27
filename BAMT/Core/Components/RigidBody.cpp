#include "RigidBody.h"

#include "../EngineSettings.h"

RigidBody::RigidBody()
{
}

RigidBody::~RigidBody()
{
	// Check if the entity is already a child of the new parent.
	auto iterator = std::find(entity->scene->rigidBodiesList.begin(), entity->scene->rigidBodiesList.end(), this);
	entity->scene->rigidBodiesList.erase(iterator);
}

void RigidBody::Start()
{
	transform = entity->GetComponent<Transform>();

	if (transform == nullptr)
	{
		Debug::LogWarn("Transform Component was not present on Entity with a RigidBody. Adding one now...");
		transform = entity->AddComponent<Transform>();
	}
	entity->scene->rigidBodiesList.push_back(this);
}

void RigidBody::Update(float* timeStep)
{
	if (isKinematic) return;
	_timeStep = *timeStep / BAMT_PHYSICS_STEPS;

	for (int i = 0; i < BAMT_PHYSICS_STEPS; ++i)
	{
		// Simulate the next position for our RigidBody.
		const Vector2 stepPosition = Simulate(&_timeStep, _velocity, *transform->GetPosition());

		transform->SetPosition(&stepPosition);
	}
}

Vector2 RigidBody::Simulate(const float* timeStep, Vector2 velocity, Vector2 position)
{
	const float speed = VectorMath::Magnitude(velocity);
	const Vector2 gravity = entity->scene->gravity;

	// If we are moving, apply drag to the body. 
	if (speed > 0) 
	{
		const float dragForce = drag * speed;
		velocity.x -= (velocity.x / speed) * dragForce * *timeStep;
		velocity.y -= (velocity.y / speed) * dragForce * *timeStep;

		// Slow us down if we are going too fast.
		if (speed > maxVelocity)
		{
			velocity.x = (velocity.x / speed) * maxVelocity;
			velocity.y = (velocity.y / speed) * maxVelocity;
		}


		// Apply the newly made velocity to the position we are going to return.
		position.x += velocity.x * *timeStep;
		position.y += velocity.y * *timeStep;
	}


	velocity.x += gravity.x * *timeStep;
	velocity.y += gravity.y * *timeStep;

	// Set the new velocity to be the velocity we calculated in here.
	_velocity = velocity;

	// Return the position
	return position;
}

void RigidBody::AddForce(Vector2 direction, float force)
{
	// Use F = ma to get the acceleration force.
	// Acceleration = Force / Mass
	const float acceleration = force / mass;

	// We should assume that the direction we are given is already normalized.
	_velocity.x += direction.x * acceleration * (_timeStep * BAMT_PHYSICS_STEPS);
	_velocity.y += direction.y * acceleration * (_timeStep * BAMT_PHYSICS_STEPS);
}

void RigidBody::AddImpulseForce(Vector2 direction, float force)
{

	// We should assume that the direction we are given is already normalized.
	_velocity.x += direction.x * force * (_timeStep * BAMT_PHYSICS_STEPS);
	_velocity.y += direction.y * force * (_timeStep * BAMT_PHYSICS_STEPS);
}

Vector2 RigidBody::GetVelocity() const
{
	return _velocity;
}