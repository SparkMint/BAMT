#include "Weapon.h"

void Weapon::Start()
{
	entityPool = entity->GetComponent<EntityPooler>();
	if(!entityPool)
	{
		Debug::LogWarn("No Pooler found on the player! Adding one now...", entity);
		entityPool = entity->AddComponent<EntityPooler>();
	}
	WeaponData defaultData = WEAPON_DATA_PISTOL;
	weaponData = &defaultData;
}

void Weapon::Update(float* timeStep)
{
	if(time < weaponData->fireRate)
	{
		time += *timeStep;
		canFire = false;
	}
	else canFire = true;
}

void Weapon::Fire(Entity* projectileToFire, const Vector2& directionToFire)
{
	time = 0;
	if(weaponData == nullptr)
	{
		Debug::LogError("Weapon Data not found. Cannot fire!", this);
		return;
	}

	Projectile* projComponent = projectileToFire->GetComponent<Projectile>();

	projComponent->projectileDamage = weaponData->projectileDamage;
	projComponent->projectileKnockback = weaponData->projectileKnockback;
	projComponent->spriteRenderer->SetSprite(weaponData->projectileSprite.c_str());
	projComponent->whoSpawnedMe = entity->GetComponent<RigidBody>();

	projComponent->spriteRenderer->width = weaponData->projectileSize;
	projComponent->spriteRenderer->height = weaponData->projectileSize;

	projComponent->rigidBody->width = weaponData->projectileSize;
	projComponent->rigidBody->height = weaponData->projectileSize;
	projComponent->projectileLifetime = weaponData->projectileLifeTime;

	projComponent->rigidBody->velocity = VECTOR2_ZERO;
	projectileToFire->transform->SetPosition(entity->transform->GetPosition());
	projectileToFire->active = true;

	projComponent->rigidBody->AddForce(directionToFire, weaponData->projectileSpeed);
}