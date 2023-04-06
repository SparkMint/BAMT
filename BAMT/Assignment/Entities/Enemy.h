#ifndef ASSIGNMENT_ENEMY
#define ASSIGNMENT_ENEMY

#include "../../Core/Components/SpriteRenderer.h"
#include "../../Core/Components/RigidBody.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Entity.h"
#include "../Components/WeaponSystem/EnemyWeapon.h"
#include "../Components/EnemyMovement.h"

class Enemy : public Entity
{
	const char* enemyTag = "Enemy";

	public:
		Entity* target = nullptr;

		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRenderer = nullptr;

		EnemyMovement* movement = nullptr;

		EntityPooler* entityPool = nullptr;
		int projectilePoolCount = 1;

		EnemyWeapon* weapon = nullptr;
		WeaponData weaponData = WEAPON_DATA_PISTOL;

		Vector2 initialPosition = { 5, 5 };

		// Size Values
		float width = .5f;
		float height = .5f;

		// RigidBody Values
		float maxSpeed = 25;
		float dragForce = 10;
		float mass = 1;
		float bounciness = .2f;

		float movementSpeed = 5;

		void Start() override;
		void Update(float* timeStep) override;

		void UpdateTarget(Entity* newTarget);
};
#endif