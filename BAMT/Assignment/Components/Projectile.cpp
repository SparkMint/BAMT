#include "Projectile.h"

void Projectile::Start()
{
	Component::Start();

	// Tell this object its tag is now a projectile.
	entity->tag = projectileTag;

	// Look for a RigidBody.
	rigidBody = entity->GetComponent<RigidBody>();

	if(rigidBody == nullptr)
	{
		Debug::LogWarn("RigidBody not found on this projectile! Adding one now...", entity);
		rigidBody = entity->AddComponent<RigidBody>();

	}

	rigidBody->maxVelocity = 100;
	rigidBody->drag = 0;
	rigidBody->isTrigger = true;

	spriteRenderer = entity->GetComponent<SpriteRenderer>();

	if (spriteRenderer == nullptr)
	{
		Debug::LogWarn("SpriteRenderer not found on this projectile! Adding one now...", entity);
		spriteRenderer = entity->AddComponent<SpriteRenderer>();
	}
}

void Projectile::Update(float* timeStep)
{
	Component::Update(timeStep);

	// Check for collision.

	for (auto rb : rigidBody->collisionList)
	{
		// If we were fired by a player for example. Ignore the collision.
		if (rb == whoSpawnedMe || rb->entity->tag == entity->tag) continue;

		Vector2 dir = VectorMath::Normalize(*rb->entity->transform->GetPosition() - *entity->transform->GetPosition());

		// Do stuff.
		rb->AddForce(dir, projectileKnockback);
		entity->active = false;
	}

}