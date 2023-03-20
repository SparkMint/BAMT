#include "PinballGameLevel.h"
void PinballGameLevel::Start()
{
	_player = AddEntity<Player>();
	auto* collisionTest = AddEntity<Entity>();

	collisionTest->AddComponent<Transform>(640, 720);
	collisionTest->AddComponent<BoxCollider>(1280, 50);
	collisionTest->GetComponent<BoxCollider>()->DebugMode(true);
	collisionTest->AddComponent<RigidBody>();
	collisionTest->GetComponent<RigidBody>()->isKinematic = true;


	auto* collisionTest1= AddEntity<Entity>();

	collisionTest1->AddComponent<Transform>(0, 360);
	collisionTest1->AddComponent<BoxCollider>(50, 720);
	collisionTest1->GetComponent<BoxCollider>()->DebugMode(true);
	collisionTest1->AddComponent<RigidBody>();
	collisionTest1->GetComponent<RigidBody>()->isKinematic = true;

	auto* collisionTest2 = AddEntity<Entity>();

	collisionTest2->AddComponent<Transform>(640, 0);
	collisionTest2->AddComponent<BoxCollider>(1280, 50);
	collisionTest2->GetComponent<BoxCollider>()->DebugMode(true);
	collisionTest2->AddComponent<RigidBody>();
	collisionTest2->GetComponent<RigidBody>()->isKinematic = true;

	auto* collisionTest3 = AddEntity<Entity>();

	collisionTest3->AddComponent<Transform>(1280, 360);
	collisionTest3->AddComponent<BoxCollider>(50, 720);
	collisionTest3->GetComponent<BoxCollider>()->DebugMode(true);
	collisionTest3->AddComponent<RigidBody>();
	collisionTest3->GetComponent<RigidBody>()->isKinematic = true;

	for (int i = 0; i < 100; ++i)
	{
		auto thing = AddEntity<Player>();
		thing->GetComponent<Transform>()->SetPosition(50 + (i * 20), 100 + (i * 5));
	}
}
