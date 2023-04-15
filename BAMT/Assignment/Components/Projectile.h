#ifndef ASSIGNMENT_PROJECTILE
#define ASSIGNMENT_PROJECTILE

#include "Component.h"
#include "RigidBody.h"
#include "SpriteRenderer.h"
#include "ScoreSystem.h"
#include "HealthSystem/Health.h"

/// <summary>
/// Projectiles can be fired by enemies and the player. They collide with everything
///	but themselves and whoever fired them.
/// </summary>
class Projectile : public Component
{
		const char* projectileTag = "Projectile";
		float time = 0;
	public:
		ScoreSystem* scoreSystem = nullptr;
		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRenderer = nullptr;

		int projectileDamage = 0;
		float projectileKnockback = 0;
		float projectileLifetime = 1;

		RigidBody* whoSpawnedMe;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif
