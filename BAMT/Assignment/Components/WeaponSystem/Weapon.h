#ifndef ASSIGNMENT_WEAPON
#define ASSIGNMENT_WEAPON

#include "WeaponData.h"
#include "../../../Core/EngineManager.h"
#include "../../../Core/Components/Transform.h"
#include "../../../Core/ECS/Component.h"
#include "../../../Core/Misc/Input.h"
#include "../Projectile.h"
#include "../EntityPooler.h"
#include "../MouseAim.h"

class Weapon : public Component
{
	protected:
		float time = 0;
		bool canFire = false;


	public:
		WeaponData* weaponData = nullptr;

		EntityPooler* entityPool = nullptr;

		void Start() override;
		void Update(float* timeStep) override;
		void Fire(Entity* projectileToFire, const Vector2& directionToFire);
};
#endif