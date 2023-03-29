#ifndef BAMT_GAMEOBJECT
#define BAMT_GAMEOBJECT

#include "../../Core/Components/RectRenderer.h"
#include "../../Core/Components/SpriteRenderer.h"
#include "../../Core/Components/RigidBody.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Entity.h"
#include "../Components/PhysicsMovement.h"

class PhysicsCube : public Entity
{
	public:
		RigidBody* rigidBody = nullptr;
		PhysicsMovement* playerMovement = nullptr;
		//RectRenderer* rectRenderer = nullptr;
		SpriteRenderer* spriteRend;

		// Transform Values
		Vector2 initialPosition = { 1, 1 };

		// Size Values
		float width = .4f;
		float height = .4f;

		// RigidBody Values
		float maxSpeed = 10;
		float dragForce = 1;
		float mass = 1;
		float bounciness = .6f;

		// PhysicsCube Movement Values
		float movementSpeed = 1000;

		// RectRenderer Values
		bool fillRect = true;

		void Start() override;
};
#endif