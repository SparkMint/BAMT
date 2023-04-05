#ifndef ASSIGNMENT_PLAYER_WEAPON
#define ASSIGNMENT_PLAYER_WEAPON

#include "Weapon.h"
#include "../../../Core/EngineManager.h"
#include "../../../Core/Components/Transform.h"
#include "../../../Core/ECS/Component.h"
#include "../../../Core/Misc/Input.h"
#include "../Projectile.h"
#include "../MouseAim.h"

class PlayerWeapon : public Weapon
{
	public:
		MouseAim* mouseAim = nullptr;
		void Start() override;
		void Update(float* timeStep) override;
};
#endif