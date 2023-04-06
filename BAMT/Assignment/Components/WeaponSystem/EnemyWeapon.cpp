#include "EnemyWeapon.h"

void EnemyWeapon::Start()
{
	Weapon::Start();
}

void EnemyWeapon::Update(float* timeStep)
{
	Weapon::Update(timeStep);

	if (!canFire || target == nullptr) return;

	Entity* projectile = entityPool->GetAvaliableObject();

	if (projectile == nullptr)
	{
		Debug::LogWarn("Enemy cannot fire projectile. All are currently active in the scene!");
		return;
	}

	const Vector2 firingDirection = VectorMath::Normalize(*target->transform->GetPosition() - *entity->transform->GetPosition());
	Fire(projectile, firingDirection);
}