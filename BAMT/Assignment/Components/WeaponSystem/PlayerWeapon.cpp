#include "PlayerWeapon.h"

void PlayerWeapon::Start()
{
	Weapon::Start();

	mouseAim = entity->GetComponent<MouseAim>();

	if (!mouseAim)
	{
		Debug::LogWarn("No mouseAim found on the player! Adding one now...", entity);
		mouseAim = entity->AddComponent<MouseAim>();
	}
}

void PlayerWeapon::Update(float* timeStep)
{
	Weapon::Update(timeStep);

	if (Input::GetMouseButtonHold(SDL_BUTTON_LEFT) && canFire)
	{
		Entity* projectile = entityPool->GetAvaliableObject();

		if (projectile == nullptr)
		{
			Debug::LogWarn("Player cannot fire projectile. All are currently active in the scene!");
			return;
		}
		const Vector2 firingDirection = VectorMath::Normalize(mouseAim->GetAimDirection(entity->transform->GetPosition()));
		Fire(projectile, firingDirection);
	}
}