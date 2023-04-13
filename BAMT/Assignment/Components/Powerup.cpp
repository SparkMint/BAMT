#include "Powerup.h"

void Powerup::Start()
{
	entity->tag = powerupTag;

	rigidBody = entity->AddComponent<RigidBody>();

	rigidBody->isTrigger = true;
	rigidBody->isKinematic = true;
	rigidBody->width = powerupWidth;
	rigidBody->height = powerupHeight;

	spriteRenderer = entity->AddComponent<SpriteRenderer>(powerupWidth, powerupHeight, "default.png");
}

void Powerup::Update(float* timeStep)
{
	for (auto rb : rigidBody->collisionList)
	{
		if (rb->entity->tag != "Player") continue;

		auto* reciever = rb->entity->GetComponent<PowerupReciever>();
		if (reciever != nullptr)
		{
			// We have been collected!
			reciever->ApplyPowerupEffects(type);
		}
		entity->active = false;
	}
}

void Powerup::UpdateType(PowerupType typeToUpdateTo)
{
	type = typeToUpdateTo;
	switch (typeToUpdateTo)
	{
		case speed:
			spriteRenderer->SetSprite("speedItem.png");
			break;

		case doublePoints:
			spriteRenderer->SetSprite("doublePointsItem.png");
			break;
	}
}