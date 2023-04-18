#ifndef ASSIGNMENT_ENEMY_ANIMATION_SYSTEM
#define ASSIGNMENT_ENEMY_ANIMATION_SYSTEM

#include "Animator.h"
#include "Component.h"
#include "EnemyMovement.h"
#include "RigidBody.h"

class EnemyAnimationSystem : public Component
{
	public:
		void Start() override;
		void Update(float* timeStep)override;

		Animator* animator = nullptr;
		EnemyMovement* movementSystem;
		Animation* walkRightAnim = nullptr;
		Animation* walkLeftAnim = nullptr;
};
#endif