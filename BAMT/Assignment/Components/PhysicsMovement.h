#ifndef BAMT_PLAYER_MOVEMENT
#define BAMT_PLAYER_MOVEMENT

#include "../../Core/EngineManager.h"
#include "../../Core/Components/RectRenderer.h"
#include "../../Core/Components/RigidBody.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Component.h"
#include "../../Core/Misc/Input.h"

class PhysicsMovement : public Component
{
	Transform* _transform = nullptr;
	RigidBody* _rigidBody = nullptr;

	Vector2 _zeroGravity{ 0,0 };
	Vector2 _Gravity{ 0,3 };

	public:
		float movementSpeed;

		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;
};
#endif