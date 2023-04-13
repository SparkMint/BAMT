#ifndef ASSIGNMENT_HEALTH
#define ASSIGNMENT_HEALTH

#include "../../Core/ECS/Component.h"

class Health : public Component
{
	int currentHealth = 0;
	public:
		Health(int health);

		void Start() override;

		int maxHealth = 1;

		int GetHealth() const;
		void SetHealth(int health);
		virtual void RemoveHealth(int healthToRemove);

		virtual void OnDead() = 0;
};
#endif