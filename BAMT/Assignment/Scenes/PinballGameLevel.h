#ifndef BAMT_PINBALL_GAME_LEVEL
#define BAMT_PINBALL_GAME_LEVEL

#include "../../Core/EngineSettings.h"
#include "../../Core/ECS/Scene.h"
#include "../../Core/Entities/CoordinateGrid.h"
#include "../Entities/PhysicsCube.h"
#include "../Entities/StaticCollider.h"
#include "../Entities/Slingshot/Slingshot.h"

class PinballGameLevel : public Scene
{
	Slingshot* _player = nullptr;

	public:
		void Start() override;
};
#endif