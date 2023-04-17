#ifndef ASSIGNMENT_ENEMY
#define ASSIGNMENT_ENEMY

#include "Entity.h"
#include "SpriteRenderer.h"
#include "RigidBody.h"
#include "../Components/WeaponSystem/EnemyWeapon.h"
#include "../Components/HealthSystem/EnemyHealth.h"
#include "../Components/EnemyMovement.h"
#include "../Components/UIManager.h"

class EnemyHealth;

class Enemy : public Entity
{
	const char* enemyTag = "Enemy";

	public:
		Entity* target = nullptr;

		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRenderer = nullptr;
		std::string sprite = "default.png";

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

		void Init();
		void UpdateTarget(Entity* newTarget);

		void Stop();
		void Restart();
};
#endif