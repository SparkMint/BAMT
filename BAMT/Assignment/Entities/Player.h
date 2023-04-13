#ifndef BAMT_GAMEOBJECT
#define BAMT_GAMEOBJECT

#include "../../Core/Components/SpriteRenderer.h"
#include "../../Core/Components/RigidBody.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Entity.h"
#include "../Components/KeyboardMovement.h"
#include "../Components/PowerupReciever.h"
#include "../Components/ScoreSystem.h"
#include "../Components/PlayerHealth.h"
#include "../Components/WeaponSystem/PlayerWeapon.h"


class Player : public Entity
{
	const char* playerTag = "Player";

	public:
		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRenderer = nullptr;
		KeyboardMovement* playerMovement = nullptr;
		EntityPooler* entityPool = nullptr;
		PlayerWeapon* weapon = nullptr;
		PlayerHealth* playerHealth = nullptr;
		WeaponData pistolData = WEAPON_DATA_RIFLE;
		PowerupReciever* powerupReciever = nullptr;
		ScoreSystem* scoreSystem = nullptr;

		// Transform Values
		Vector2 initialPosition = { 1, 1 };

		int projectilePoolCount = 10;

		// Size Values
		float width = .5f;
		float height = .5f;

		// RigidBody Values
		float maxSpeed = 10;
		float dragForce = 5;
		float mass = 2;
		float bounciness = .2f;

		// Player Movement Values
		float movementSpeed = 1;

		void Start() override;
};
#endif