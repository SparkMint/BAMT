#ifndef BAMT_PHYSICS_TEST_SCENE
#define BAMT_PHYSICS_TEST_SCENE

#include "../../../Core/EngineSettings.h"
#include "../../../Core/ECS/Scene.h"
#include "../../../Core/Entities/CoordinateGrid.h"
#include "../../Entities/Player.h"
#include "../../Entities/StaticCollider.h"

class PhysicsTestScene : public Scene
{
	public:
		void Start() override;
};
#endif