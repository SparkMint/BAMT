#ifndef BAMT_PLAYER_MOVEMENT
#define BAMT_PLAYER_MOVEMENT

#include "Entity.h"
#include "Component.h"
#include "Input.h"
#include "Transform.h"
#include "RigidBody.h"

class PlayerMovement : public Component
{
	private:
		Transform* _transform = nullptr;
		RigidBody* _rigidBody = nullptr;
		Entity* _distanceTest = nullptr;
	public:
		float accelerationSpeed = 1000;

		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;
};
#endif