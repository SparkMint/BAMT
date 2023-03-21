#include "PinballGameLevel.h"
void PinballGameLevel::Start()
{
	auto* collisionTest = AddEntity<Entity>();

	collisionTest->AddComponent<Transform>(640, 720);
	collisionTest->AddComponent<RigidBody>();
	collisionTest->GetComponent<RigidBody>()->colliderWidth = 1280;
	collisionTest->GetComponent<RigidBody>()->colliderHeight = 50;
	collisionTest->GetComponent<RigidBody>()->isKinematic = true;

	auto* collisionTest1= AddEntity<Entity>();

	collisionTest1->AddComponent<Transform>(0, 360);
	collisionTest1->AddComponent<RigidBody>();
	collisionTest1->GetComponent<RigidBody>()->colliderWidth = 50;
	collisionTest1->GetComponent<RigidBody>()->colliderHeight = 720;
	collisionTest1->GetComponent<RigidBody>()->isKinematic = true;

	auto* collisionTest2 = AddEntity<Entity>();

	collisionTest2->AddComponent<Transform>(640, 0);
	collisionTest2->AddComponent<RigidBody>();
	collisionTest2->GetComponent<RigidBody>()->colliderWidth = 1280;
	collisionTest2->GetComponent<RigidBody>()->colliderHeight = 50;
	collisionTest2->GetComponent<RigidBody>()->isKinematic = true;

	auto* collisionTest3 = AddEntity<Entity>();

	collisionTest3->AddComponent<Transform>(1280, 360);
	collisionTest3->AddComponent<RigidBody>();
	collisionTest3->GetComponent<RigidBody>()->colliderWidth = 50;
	collisionTest3->GetComponent<RigidBody>()->colliderHeight = 720;
	collisionTest3->GetComponent<RigidBody>()->isKinematic = true;

	const auto thing = AddEntity<Player>();
	thing->GetComponent<Transform>()->SetPosition(50 , 50);
	thing->GetComponent<RigidBody>()->mass = 5;
	thing->playerMovement->enabled = true;

	int r = rand() & 255;
	int g = rand() & 255;
	int b = rand() & 255;
	thing->rectRenderer->colour = { r, g ,b, 255 };

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			const auto thing = AddEntity<Player>();
			thing->GetComponent<Transform>()->SetPosition(75 + (j * 21), 75 + (i * 21));
			thing->playerMovement->enabled = false;
		}
	}
}