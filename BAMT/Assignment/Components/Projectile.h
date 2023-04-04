#ifndef ASSIGNMENT_PROJECTILE
#define ASSIGNMENT_PROJECTILE

#include "../../Core/EngineManager.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Component.h"
#include "../../Core/Misc/Input.h"

#include "../../Core/Components/SpriteRenderer.h"

class Projectile : public Component
{
	public:
		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRenderer = nullptr;

		int projectileDamage = 1;
		float projectileKnockback = 0;


		std::string tagOfWhoFiredMe;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif
