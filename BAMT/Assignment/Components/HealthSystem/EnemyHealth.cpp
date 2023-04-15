#include "EnemyHealth.h"

void EnemyHealth::Start()
{
	Health::Start();

	powerup = entity->scene->AddEntity();
	powerup->AddComponent<Powerup>();
	powerup->active = false;
}

void EnemyHealth::OnDead()
{
	if (scoreSystem) scoreSystem->AddScore(maxHealth);
	const int dropChance = rand() % 10;
	if(dropChance == 1)
	{
		auto* powerupComponent = powerup->GetComponent<Powerup>();
		const PowerupType type = static_cast<PowerupType>(rand() % 2);
		powerupComponent->UpdateType(type);
		powerup->transform->SetPosition(entity->transform->GetPosition());
		powerup->active = true;
	}
	entity->active = false;
}