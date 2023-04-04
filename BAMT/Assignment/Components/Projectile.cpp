#include "Projectile.h"

void Projectile::Start()
{
	Component::Start();

	entity->tag = "Projectile";

	rigidBody = entity->GetComponent<RigidBody>();

	if(rigidBody == nullptr)
	{
		Debug::LogWarn("RigidBody not found on this projectile! Adding one now...", entity);
		rigidBody = entity->AddComponent<RigidBody>();
		rigidBody->maxVelocity = 100;
	}

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
		if (rb->entity->tag == tagOfWhoFiredMe || rb->entity->tag == entity->tag) continue;

		// Do stuff.
		entity->active = false;
	}

}