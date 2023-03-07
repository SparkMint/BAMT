#ifndef BAMT_PLAYER_MOVEMENT
#define BAMT_PLAYER_MOVEMENT

#include "Entity.h"
#include "Component.h"
#include "Input.h"
#include "Transform.h"

class PlayerMovement : public Component
{
	private:
		Transform* _transform = nullptr;
	public:
		float accelerationSpeed = 2000;
		float maxSpeed = 200;
		float drag = 500;
		float stopThreshold = 2;
		Vector2 velocity;

		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;

		void Accelerate(const float* timeStep);
		void DoDrag(const Vector2* previousVelocity, const float* timeStep);
};
#endif