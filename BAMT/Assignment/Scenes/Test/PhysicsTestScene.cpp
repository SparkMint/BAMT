#include "PhysicsTestScene.h"

void PhysicsTestScene::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	// Left Wall
	auto* collisionTest = AddEntity<StaticCollider>();

	collisionTest->GetComponent<Transform>()->SetPosition(-.25, height / 2);
	collisionTest->GetComponent<RigidBody>()->width = .5f;
	collisionTest->GetComponent<RigidBody>()->height = height;
	collisionTest->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest->GetComponent<RectRenderer>()->width = .5f;
	collisionTest->GetComponent<RectRenderer>()->height = height;
	collisionTest->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	// Top Wall
	auto* collisionTest1 = AddEntity<StaticCollider>();

	collisionTest1->GetComponent<Transform>()->SetPosition(width / 2, -.25f);
	collisionTest1->GetComponent<RigidBody>()->width = width;
	collisionTest1->GetComponent<RigidBody>()->height = .5f;
	collisionTest1->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest1->GetComponent<RectRenderer>()->width = width;
	collisionTest1->GetComponent<RectRenderer>()->height = .5f;
	collisionTest1->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	// Right Wall
	auto* collisionTest2 = AddEntity<StaticCollider>();

	collisionTest2->GetComponent<Transform>()->SetPosition(width + .25f, height / 2);
	collisionTest2->GetComponent<RigidBody>()->width = .5f;
	collisionTest2->GetComponent<RigidBody>()->height = height;
	collisionTest2->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest2->GetComponent<RectRenderer>()->width =.5f;
	collisionTest2->GetComponent<RectRenderer>()->height = height;
	collisionTest2->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	// Bottom Wall
	auto* collisionTest3 = AddEntity<StaticCollider>();

	collisionTest3->GetComponent<Transform>()->SetPosition(width / 2, height + .25f);
	collisionTest3->GetComponent<RigidBody>()->width = width;
	collisionTest3->GetComponent<RigidBody>()->height = .5f;
	collisionTest3->GetComponent<RectRenderer>()->width = width;
	collisionTest3->GetComponent<RectRenderer>()->height = .5f;
	collisionTest3->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	AddEntity<CoordinateGrid>();

	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			const auto thing = AddEntity<Entity>();
			thing->GetComponent<Transform>()->SetPosition(2 + (j * .26f), 2 + (i * .26f));
			auto* rb = thing->AddComponent<RigidBody>();
			rb->width = .25f;
			rb->height = .25f;
			rb->bounciness = .2f;
			rb->drag = 2;
			rb->maxVelocity = 10;
			rb->mass = 1;
			auto* rr = thing->AddComponent<RectRenderer>();
			rr->width = .25f;
			rr->height = .25f;
			rr->fillRect = true;

			int r = rand() & 255;
			int g = rand() & 255;
			int b = rand() & 255;
			rr->colour = { r, g ,b, 255 };
		}
	}

	const auto thing = AddEntity<Entity>();
	thing->GetComponent<Transform>()->SetPosition(1,1);
	auto* rb = thing->AddComponent<RigidBody>();
	rb->width = .25f;
	rb->height = .25f;
	rb->bounciness = .2f;
	rb->drag = 2;
	rb->maxVelocity = 10;
	rb->mass = 1;
	auto* rr = thing->AddComponent<RectRenderer>();
	rr->width = .25f;
	rr->height = .25f;
	rr->fillRect = true;

	int r = rand() & 255;
	int g = rand() & 255;
	int b = rand() & 255;
	rr->colour = { r, g ,b, 255 };
	thing->AddComponent<KeyboardMovement>()->currentMovementSpeed = 10;


	gravity = { 0, 5 };
}