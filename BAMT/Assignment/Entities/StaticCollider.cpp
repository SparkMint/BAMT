#include "StaticCollider.h"

void StaticCollider::Start()
{
	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();
	rigidBody->colliderWidth = width;
	rigidBody->colliderHeight = height;
	rigidBody->isKinematic = true;

	rigidBody->bounciness = bounciness;

	// Renderer Setup
	rectRenderer = AddComponent<RectRenderer>(width, height, fillRect);
}