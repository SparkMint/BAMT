#ifndef ASSIGNMENT_PLAYER_WEAPON
#define ASSIGNMENT_PLAYER_WEAPON

#include "../../Core/EngineManager.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Component.h"
#include "../../Core/Misc/Input.h"
#include "../../Core/Components/RectRenderer.h"
#include "EntityPooler.h"
#include "MouseAim.h"

class PlayerWeapon : public Component
{
	float fireRateCurTime = 0;
	bool canFire = false;
	public:
		float projectileSize = 0;

		std::string projectileSprite;
		float fireRate;
		float projectileSpeed;
		int projectileDamage;
		float projectileKnockback;

		int projectilePoolCount = 100;
		EntityPooler* entityPool = nullptr;
		MouseAim* mouseAim = nullptr;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif