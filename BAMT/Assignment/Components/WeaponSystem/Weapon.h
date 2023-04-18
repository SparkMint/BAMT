#ifndef ASSIGNMENT_WEAPON
#define ASSIGNMENT_WEAPON

#include "WeaponData.h"
#include "Transform.h"
#include "Component.h"
#include "EntityPooler.h"
#include "../Projectile.h"

class Weapon : public Component
{
	protected:
		float time = 0;
		bool canFire = false;

	public:
		Weapon();
		Weapon(int projectiles);
		~Weapon();

		WeaponData* weaponData = nullptr;

		EntityPooler* entityPool = nullptr;
		int maxProjectiles = 10;

		void Start() override;
		void Update(float* timeStep) override;
		void Fire(Vector2& directionToFire);
};
#endif