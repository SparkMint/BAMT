#ifndef BAMT_GAMEOBJECT
#define BAMT_GAMEOBJECT

#include "../../Core/Components/SpriteRenderer.h"
#include "../../Core/Components/RigidBody.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Entity.h"
#include "../Components/KeyboardMovement.h"
#include "../Components/MouseAim.h"
#include "../Components/WeaponSystem/PlayerWeapon.h"


class Player : public Entity
{
	const char* playerTag = "Player";

	public:
		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRend = nullptr;

		KeyboardMovement* playerMovement = nullptr;
		MouseAim* mouseAim = nullptr;

		EntityPooler* entityPool = nullptr;
		int projectilePoolCount = 20;

		PlayerWeapon* pistolWeapon = nullptr;
		WeaponData pistolData = WEAPON_DATA_PISTOL;

		// Transform Values
		Vector2 initialPosition = { 1, 1 };

		// Size Values
		float width = .5f;
		float height = .5f;

		// RigidBody Values
		float maxSpeed = 10;
		float dragForce = 5;
		float mass = 1;
		float bounciness = 1;

		// Player Movement Values
		float movementSpeed = 50;

		void Start() override;
};
#endif