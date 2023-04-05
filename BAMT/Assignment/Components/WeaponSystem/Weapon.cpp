#include "Weapon.h"

void Weapon::Start()
{
	Component::Start();

	entityPool = entity->GetComponent<EntityPooler>();

	if(!entityPool)
	{
		Debug::LogWarn("No Pooler found on the player! Adding one now...", entity);
		entityPool = entity->AddComponent<EntityPooler>();
	}
}

void Weapon::Update(float* timeStep)
{
	Component::Update(timeStep);

	if(time < weaponData->fireRate)
	{
		time += *timeStep;
		canFire = false;
	}
	else
	{
		canFire = true;
	}
}

void Weapon::Fire(Entity* projectileToFire, const Vector2& directionToFire)
{
	if(weaponData == nullptr)
	{
		Debug::LogError("Weapon Data not found. Cannot fire!", this);
		return;
	}
	time = 0;

	Projectile* projComponent = projectileToFire->GetComponent<Projectile>();

	projComponent->projectileDamage = weaponData->projectileDamage;
	projComponent->projectileKnockback = weaponData->projectileKnockback;
	projComponent->spriteRenderer->sprite = weaponData->projectileSprite.c_str();
	projComponent->whoSpawnedMe = entity->GetComponent<RigidBody>();

	projComponent->spriteRenderer->width = weaponData->projectileSize;
	projComponent->spriteRenderer->height = weaponData->projectileSize;

	projComponent->rigidBody->width = weaponData->projectileSize;
	projComponent->rigidBody->height = weaponData->projectileSize;

	// Reset this objects velocity.
	projComponent->rigidBody->velocity = VECTOR2_ZERO;
	projectileToFire->transform->SetPosition(entity->transform->GetPosition());

	projectileToFire->active = true;

	projComponent->rigidBody->AddForce(directionToFire, weaponData->projectileSpeed);
}
