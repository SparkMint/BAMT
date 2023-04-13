#include "Health.h"

Health::Health(int health) { maxHealth = health; }

void Health::Start() { currentHealth = maxHealth; }

int Health::GetHealth() const { return currentHealth; }

void Health::SetHealth(int health) { currentHealth = health; }

void Health::RemoveHealth(int healthToRemove)
{
	currentHealth -= healthToRemove;

	if(currentHealth <= 0)
	{
		currentHealth = 0;
		OnDead();
	}
}