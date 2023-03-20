#include "RigidBody.h"

#include "Scene.h"

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
	// Simulate the next position for our RigidBody.
	const Vector2 stepPosition = Simulate(timeStep, _velocity, *transform->GetPosition());

	transform->SetPosition(&stepPosition);
}

Vector2 RigidBody::Simulate(const float* timeStep, Vector2 velocity, Vector2 position)
{
	const float speed = VectorMath::Magnitude(velocity);

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

		velocity.x += gravity.x * *timeStep;
		velocity.y += gravity.y * *timeStep;

		// Apply the newly made velocity to the position we are going to return.
		position.x += velocity.x * *timeStep;
		position.y += velocity.y * *timeStep;
	}

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

void RigidBody::ReactToCollisions(const RigidBody* otherRigidBody)
{
	if (isKinematic) return;
	// Calculate the collision normal vector
	Vector2 normal;
	const float xOverlap = (colliderWidth + otherRigidBody->colliderWidth) * 0.5f - fabs(transform->GetX() - otherRigidBody->transform->GetX());
	const float yOverlap = (colliderHeight + otherRigidBody->colliderHeight) * 0.5f - fabs(transform->GetY() - otherRigidBody->transform->GetY());

	// How far is this object in the other one? Use more force to get it out!
	const float penetration = fmax(xOverlap, yOverlap);
	//_velocity = { _velocity.x * .8f, _velocity.y * .8f };

	if (xOverlap < yOverlap)
	{
		if (transform->GetX() < otherRigidBody->transform->GetX())
		{
			normal = Vector2{ -1, 0 };
		}
		else
		{
			normal = Vector2{ 1, 0 };
		}
	}
	else
	{
		if (transform->GetY() < otherRigidBody->transform->GetY())
		{
			normal = Vector2{ 0, -1 };
		}
		else
		{
			normal = Vector2{ 0, 1 };
		}
	}
	AddForce(normal, penetration * 2);
}