#ifndef BAMT_GAMEOBJECT
#define BAMT_GAMEOBJECT

#include "BoxCollider.h"
#include "Entity.h"
#include "PlayerMovement.h"
#include "Transform.h"
#include "RectRenderer.h"
#include "RigidBody.h"

class Player : public Entity
{
	public:
		Transform* transform = nullptr;
		BoxCollider* boxCollider = nullptr;
		RigidBody* rigidBody = nullptr;
		PlayerMovement* playerMovement = nullptr;
		RectRenderer* rectRenderer = nullptr;

		//Transform Values
		Vector2 initialPosition = { 100, 100 };

		// RigidBody Values
		int maxSpeed = 500;
		int dragForce = 0;
		Vector2 gravity = {0, 250};

		// Player Movement Values
		float movementSpeed = 1000;

		// RectRenderer Values
		int rendererWidth = 20;
		int rendererHeight = 20;
		bool fillRect = true;
		

		void Start() override;
};
#endif