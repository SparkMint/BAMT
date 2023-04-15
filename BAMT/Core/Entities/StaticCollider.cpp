#include "StaticCollider.h"

void StaticCollider::Start()
{
	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();
	rigidBody->width = width;
	rigidBody->height = height;
	rigidBody->isKinematic = true;

	rigidBody->bounciness = bounciness;

	// Renderer Setup
	rectRenderer = AddComponent<RectRenderer>(width, height, fillRect);
}