#ifndef BAMT_PLAYER_MOVEMENT
#define BAMT_PLAYER_MOVEMENT

#include "../../Core/EngineManager.h"
#include "../../Core/Components/RectRenderer.h"
#include "../../Core/Components/RigidBody.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Component.h"
#include "../../Core/Misc/Input.h"

class KeyboardMovement : public Component
{
	RigidBody* _rigidBody = nullptr;

	public:
		float movementSpeed;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif