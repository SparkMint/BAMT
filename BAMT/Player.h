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
		Vector2 initialPosition = { 1, 1 };

		// RigidBody Values
		float maxSpeed = 10;
		float dragForce = 1;
		float mass = 1;
		float bounciness = 1;

		// Player Movement Values
		float movementSpeed = 1000;

		// RectRenderer Values
		float rendererWidth = 0.2f;
		float rendererHeight = 0.2f;
		bool fillRect = true;
		

		void Start() override;
};
#endif