#ifndef BAMT_GAMEOBJECT
#define BAMT_GAMEOBJECT

#include "Entity.h"
#include "PlayerMovement.h"
#include "Transform.h"
#include "RectRenderer.h"
#include "RigidBody.h"

class Player : public Entity
{
	public:
		Transform* transform = nullptr;
		RigidBody* rigidBody = nullptr;
		PlayerMovement* playerMovement = nullptr;
		RectRenderer* rectRenderer = nullptr;

		//Transform Values
		Vector2 initialPosition = { 100, 100 };

		// RigidBody Values
		float maxSpeed = 500;
		float dragForce = 0;
		float mass = 1;
		float bounciness = 1;

		// Player Movement Values
		float movementSpeed = 500000;

		// RectRenderer Values
		float rendererWidth = 20;
		float rendererHeight = 20;
		bool fillRect = true;
		

		void Start() override;
};
#endif