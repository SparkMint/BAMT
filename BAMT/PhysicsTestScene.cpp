#include "PhysicsTestScene.h"

void PhysicsTestScene::Start()
{
	auto* collisionTest = AddEntity<StaticCollider>();

	collisionTest->GetComponent<Transform>()->SetPosition(6.4f, 7.20f);
	collisionTest->GetComponent<RigidBody>()->colliderWidth = 12.80f;
	collisionTest->GetComponent<RigidBody>()->colliderHeight = .50f;
	collisionTest->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest->GetComponent<RectRenderer>()->UpdateSize(12.80f, .50f);
	collisionTest->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	auto* collisionTest1 = AddEntity<StaticCollider>();

	collisionTest1->GetComponent<Transform>()->SetPosition(6.4f, 0);
	collisionTest1->GetComponent<RigidBody>()->colliderWidth = 12.80f;
	collisionTest1->GetComponent<RigidBody>()->colliderHeight = .50f;
	collisionTest1->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest1->GetComponent<RectRenderer>()->UpdateSize(12.80f, .50f);
	collisionTest1->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	auto* collisionTest2 = AddEntity<StaticCollider>();

	collisionTest2->GetComponent<Transform>()->SetPosition(0, 3.60f);
	collisionTest2->GetComponent<RigidBody>()->colliderWidth = 0.50;
	collisionTest2->GetComponent<RigidBody>()->colliderHeight = 7.20f;
	collisionTest2->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest2->GetComponent<RectRenderer>()->UpdateSize(0.50f, 7.20f);
	collisionTest2->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	auto* collisionTest3 = AddEntity<StaticCollider>();

	collisionTest3->GetComponent<Transform>()->SetPosition(12.80f, 3.60f);
	collisionTest3->GetComponent<RigidBody>()->colliderWidth = 0.50;
	collisionTest3->GetComponent<RigidBody>()->colliderHeight = 7.20f;
	collisionTest3->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest3->GetComponent<RectRenderer>()->UpdateSize(0.50f, 7.20f);
	collisionTest3->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;


	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			const auto thing = AddEntity<Player>();
			thing->GetComponent<Transform>()->SetPosition(.75f + (j * .31f), .75f + (i * .31f));
			thing->playerMovement->enabled = false;
			//thing->rigidBody->isKinematic = true;

			int r = rand() & 255;
			int g = rand() & 255;
			int b = rand() & 255;
			thing->rectRenderer->colour = { r, g ,b, 255 };
		}
	}

	const auto thing = AddEntity<Player>();
	thing->GetComponent<Transform>()->SetPosition(6, 6);
	thing->GetComponent<RigidBody>()->mass = 1;
	thing->playerMovement->enabled = true;

}
