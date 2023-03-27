#ifndef BAMT_GAMEOBJECT
#define BAMT_GAMEOBJECT

#include "../Core/ECS/Entity.h"
#include "PlayerMovement.h"
#include "../Core/Components/Transform.h"
#include "../Core/Components/RectRenderer.h"
#include "../Core/Components/RigidBody.h"

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
		float maxSpeed = 5;
		float dragForce = 1;
		float mass = 1;
		float bounciness = .6f;

		// Player Movement Values
		float movementSpeed = 1000;

		// RectRenderer Values
		float rendererWidth = .2f;
		float rendererHeight = .2f;
		bool fillRect = true;
		

		void Start() override;
};
#endif