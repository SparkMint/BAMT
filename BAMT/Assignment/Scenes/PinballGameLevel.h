#ifndef BAMT_PINBALL_GAME_LEVEL
#define BAMT_PINBALL_GAME_LEVEL

#include "../../Core/ECS/Scene.h"
#include "../Entities/PhysicsCube.h"

class PinballGameLevel : public Scene
{
	PhysicsCube* _player = nullptr;

	public:
		void Start() override;
};
#endif