#ifndef ASSIGNMENT_ENEMY
#define ASSIGNMENT_ENEMY

#include "Animator.h"
#include "Entity.h"
#include "SpriteRenderer.h"
#include "RigidBody.h"
#include "../Components/WeaponSystem/EnemyWeapon.h"
#include "../Components/HealthSystem/EnemyHealth.h"
#include "../Components/EnemyMovement.h"
#include "../Components/EnemyAnimationSystem.h"
#include "../Components/UIManager.h"

class EnemyHealth;

class Enemy : public Entity
{
	const char* enemyTag = "Enemy";

	public:
		Entity* target = nullptr;

		RigidBody* rigidBody = nullptr;
		Animator* animator = nullptr;
		EnemyAnimationSystem* animationSystem = nullptr;

		EnemyMovement* movement = nullptr;
		EnemyHealth* health = nullptr;
		int maxHealth = 10;

		EntityPooler* entityPool = nullptr;
		int projectilePoolCount = 1;

		EnemyWeapon* weapon = nullptr;
		WeaponData weaponData = WEAPON_DATA_NONE;

		UIManager* uiManager = nullptr;
		ScoreSystem* scoreSystem = nullptr;

		Vector2 initialPosition = { 5, 5 };

		// Size Values
		float width = 1;
		float height = 1;

		float colliderWidth = 1;
		float colliderHeight = 1;

		// RigidBody Values
		float maxSpeed = 25;
		float dragForce = 10;
		float mass = 1;
		float bounciness = .2f;

		float movementSpeed = 5;

		void Start() override;
		void Update(float* timeStep) override;

		void Init();
		void UpdateTarget(Entity* newTarget);

		void Stop();
		void Restart();
};
#endif