#ifndef BAMT_PLAYER_MOVEMENT
#define BAMT_PLAYER_MOVEMENT

#include "Input.h"
#include "Component.h"

#include "Transform.h"
#include "RigidBody.h"

class PlayerMovement : public Component
{
	private:
		Transform* _transform = nullptr;
		RigidBody* _rigidBody = nullptr;

		Vector2 _zeroGravity{ 0,0 };
		Vector2 _Gravity{ 0,250 };

	public:
		float movementSpeed;

		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;
};
#endif