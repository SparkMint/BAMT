#ifndef BAMT_GAMEOBJECT
#define BAMT_GAMEOBJECT

#include "../../Core/Components/RectRenderer.h"
#include "../../Core/Components/SpriteRenderer.h"
#include "../../Core/Components/RigidBody.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Entity.h"
#include "../Components/KeyboardMovement.h"
#include "../Components/MouseAim.h"
#include "../Components/PlayerWeapon.h"

class Player : public Entity
{
	public:
		RigidBody* rigidBody = nullptr;
		KeyboardMovement* playerMovement = nullptr;
		MouseAim* mouseAim = nullptr;
		
		//RectRenderer* rectRenderer = nullptr;
		SpriteRenderer* spriteRend = nullptr;

		PlayerWeapon* pistolWeapon = nullptr;
		std::string pistolSprite = "Logo.png";

		// Transform Values
		Vector2 initialPosition = { 1, 1 };

		// Size Values
		float width = .5f;
		float height = .5f;

		// RigidBody Values
		float maxSpeed = 10;
		float dragForce = 1;
		float mass = 1;
		float bounciness = 2;

		// Player Movement Values
		float movementSpeed = 100;

		// RectRenderer Values
		bool fillRect = true;

		void Start() override;
};
#endif