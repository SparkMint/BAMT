#include "PlayerWeapon.h"

#include "Projectile.h"

void PlayerWeapon::Start()
{
	Component::Start();
	entityPool = entity->GetComponent<EntityPooler>();

	if(!entityPool)
	{
		Debug::LogWarn("No Pooler found on the player! Adding one now...", entity);
		entityPool = entity->AddComponent<EntityPooler>();
	}

	mouseAim = entity->GetComponent<MouseAim>();

	if (!mouseAim)
	{
		Debug::LogWarn("No mouseAim found on the player! Adding one now...", entity);
		mouseAim = entity->AddComponent<MouseAim>();
	}

	for (int i = 0; i < projectilePoolCount; ++i)
	{
		auto* projectile = entity->scene->AddEntity<Entity>();
		auto* projComponent = projectile->AddComponent<Projectile>();
		projComponent->spriteRenderer = projectile->AddComponent<SpriteRenderer>();
		entityPool->AddEntityToPool(projectile);

	}
}

void PlayerWeapon::Update(float* timeStep)
{
	Component::Update(timeStep);

	if(fireRateCurTime < fireRate)
	{
		fireRateCurTime += *timeStep;
		canFire = false;
	}
	else
	{
		canFire = true;
	}

	if(Input::GetMouseButtonHold(SDL_BUTTON_LEFT) && canFire)
	{
		fireRateCurTime = 0;
		Entity* projectile = entityPool->GetAvaliableObject();

		if(projectile == nullptr)
		{
			Debug::LogWarn("Player cannot fire projectile. All are active!");
			return;
		}

		Projectile* projComponent = projectile->GetComponent<Projectile>();

		projComponent->projectileDamage = projectileDamage;
		projComponent->projectileKnockback = projectileKnockback;
		projComponent->spriteRenderer->sprite = projectileSprite.c_str();
		projComponent->tagOfWhoFiredMe = "Player";

		projComponent->spriteRenderer->width = projectileSize;
		projComponent->spriteRenderer->height = projectileSize;

		projComponent->rigidBody->width = projectileSize;
		projComponent->rigidBody->height = projectileSize;

		const Vector2 projectileFiringDirection = VectorMath::Normalize(mouseAim->GetAimDirection(entity->transform->GetPosition()));

		// Reset this objects velocity.
		projComponent->rigidBody->velocity = VECTOR2_ZERO;
		projectile->transform->SetPosition(entity->transform->GetPosition());

		projectile->active = true;

		projComponent->rigidBody->AddForce(projectileFiringDirection, projectileSpeed);
	}
}