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
}

void RigidBody::Render(SDL_Renderer* renderer)
{
}

void RigidBody::Simulate()
{
}

void RigidBody::AddForce(Vector2 direction, float force)
{
}
