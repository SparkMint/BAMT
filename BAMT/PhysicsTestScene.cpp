#include "PhysicsTestScene.h"

#include "CoordinateGrid.h"
#include "EngineSettings.h"

void PhysicsTestScene::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_RENDERER_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_RENDERER_SCALE;

	// Left Wall
	auto* collisionTest = AddEntity<StaticCollider>();

	collisionTest->GetComponent<Transform>()->SetPosition(-.25, height / 2);
	collisionTest->GetComponent<RigidBody>()->colliderWidth = .5f;
	collisionTest->GetComponent<RigidBody>()->colliderHeight = height;
	collisionTest->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest->GetComponent<RectRenderer>()->UpdateSize(.5f, height);
	collisionTest->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	// Top Wall
	auto* collisionTest1 = AddEntity<StaticCollider>();

	collisionTest1->GetComponent<Transform>()->SetPosition(width / 2, -.25f);
	collisionTest1->GetComponent<RigidBody>()->colliderWidth = width;
	collisionTest1->GetComponent<RigidBody>()->colliderHeight = .5f;
	collisionTest1->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest1->GetComponent<RectRenderer>()->UpdateSize(width, .5f);
	collisionTest1->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	// Right Wall
	auto* collisionTest2 = AddEntity<StaticCollider>();

	collisionTest2->GetComponent<Transform>()->SetPosition(width + .25f, height / 2);
	collisionTest2->GetComponent<RigidBody>()->colliderWidth = .5f;
	collisionTest2->GetComponent<RigidBody>()->colliderHeight = height;
	collisionTest2->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest2->GetComponent<RectRenderer>()->UpdateSize(.5f, height);
	collisionTest2->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	// Bottom Wall
	auto* collisionTest3 = AddEntity<StaticCollider>();

	collisionTest3->GetComponent<Transform>()->SetPosition(width / 2, height + .25f);
	collisionTest3->GetComponent<RigidBody>()->colliderWidth = width;
	collisionTest3->GetComponent<RigidBody>()->colliderHeight = .5f;
	collisionTest3->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest3->GetComponent<RectRenderer>()->UpdateSize(width, .5f);
	collisionTest3->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	AddEntity<CoordinateGrid>();


	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			const auto thing = AddEntity<Player>();
			thing->GetComponent<Transform>()->SetPosition(1 + (j * .21f), 1 + (i * .21f));
			thing->playerMovement->enabled = false;
			//thing->rigidBody->isKinematic = true;

			int r = rand() & 255;
			int g = rand() & 255;
			int b = rand() & 255;
			thing->rectRenderer->colour = { r, g ,b, 255 };
		}
	}

	const auto thing = AddEntity<Player>();
	thing->GetComponent<Transform>()->SetPosition(.25f, .25f);
	//thing->GetComponent<RigidBody>()->mass = 1;
	//thing->GetComponent<RigidBody>()->debugMode = true;
	thing->playerMovement->enabled = true;

}
