#ifndef ASSIGNMENT_POWERUP
#define ASSIGNMENT_POWERUP

#include "../../Core/ECS/Component.h"
#include "../../Core/EngineManager.h"
#include "../../Core/Components/SpriteRenderer.h"
#include "PowerupReciever.h"

enum PowerupType {speed = 0, doublePoints = 1};

class Powerup : public Component
{
	std::string powerupTag = "Item";

	float powerupWidth = .5f;
	float powerupHeight = .5f;

	public:
		PowerupType type;

		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRenderer = nullptr;

		void Start() override;
		void Update(float* timeStep) override;
		void UpdateType(PowerupType typeToUpdateTo);
};
#endif