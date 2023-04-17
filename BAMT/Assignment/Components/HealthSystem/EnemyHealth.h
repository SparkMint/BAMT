#ifndef ASSIGNMENT_ENEMY_HEALTH
#define ASSIGNMENT_ENEMY_HEALTH

#include "Health.h"
#include "../Powerup.h"
#include "../../Entities/Enemy.h"

class EnemyHealth : public Health
{
	public:
		Entity* powerup = nullptr;

		explicit EnemyHealth(int health) : Health(health){}

		void OnDead() override;
		void Start() override;
		void DisablePowerup();
};
#endif