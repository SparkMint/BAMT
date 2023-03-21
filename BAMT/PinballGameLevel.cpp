#include "PinballGameLevel.h"
void PinballGameLevel::Start()
{
	auto* collisionTest = AddEntity<Entity>();

	collisionTest->AddComponent<Transform>(6.4, 7.20);
	collisionTest->AddComponent<RigidBody>();
	collisionTest->GetComponent<RigidBody>()->colliderWidth = 12.80f;
	collisionTest->GetComponent<RigidBody>()->colliderHeight = .50f;
	collisionTest->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest->AddComponent<RectRenderer>(12.80, .50, false);
	collisionTest->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;


	auto* collisionTest1= AddEntity<Entity>();

	collisionTest1->AddComponent<Transform>(0, 3.60);
	collisionTest1->AddComponent<RigidBody>();
	collisionTest1->GetComponent<RigidBody>()->colliderWidth = .50f;
	collisionTest1->GetComponent<RigidBody>()->colliderHeight = 7.20f;
	collisionTest1->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest1->AddComponent<RectRenderer>(.50, 7.20, false);
	collisionTest1->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	auto* collisionTest2 = AddEntity<Entity>();

	collisionTest2->AddComponent<Transform>(6.40, 0);
	collisionTest2->AddComponent<RigidBody>();
	collisionTest2->GetComponent<RigidBody>()->colliderWidth = 12.80f;
	collisionTest2->GetComponent<RigidBody>()->colliderHeight = .50f;
	collisionTest2->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest2->AddComponent<RectRenderer>(12.80, .50, false);
	collisionTest2->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	auto* collisionTest3 = AddEntity<Entity>();

	collisionTest3->AddComponent<Transform>(12.80, 3.60);
	collisionTest3->AddComponent<RigidBody>();
	collisionTest3->GetComponent<RigidBody>()->colliderWidth = .50f;
	collisionTest3->GetComponent<RigidBody>()->colliderHeight = 7.20f;
	collisionTest3->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest3->AddComponent<RectRenderer>(.50, 7.20, false);
	collisionTest3->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;




	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			const auto thing = AddEntity<Player>();
			thing->GetComponent<Transform>()->SetPosition(.75f + (j * .21f), .75f + (i * .21f));
			thing->playerMovement->enabled = false;

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