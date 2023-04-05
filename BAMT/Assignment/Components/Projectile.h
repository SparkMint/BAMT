#ifndef ASSIGNMENT_PROJECTILE
#define ASSIGNMENT_PROJECTILE

#include "../../Core/EngineManager.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Component.h"
#include "../../Core/Misc/Input.h"

#include "../../Core/Components/SpriteRenderer.h"

/// <summary>
/// Projectiles can be fired by enemies and the player. They collide with everything
///	but themselves and whoever fired them.
/// </summary>
class Projectile : public Component
{
	const char* projectileTag = "Projectile";
	public:
		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRenderer = nullptr;

		int projectileDamage = 0;
		float projectileKnockback = 0;

		RigidBody* whoSpawnedMe;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif
