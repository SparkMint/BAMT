#include "AssignmentGameLevel.h"

void AssignmentGameLevel::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	const float thickness = 5;
	// Left Wall
	auto* collisionTest = AddEntity<StaticCollider>();

	collisionTest->GetComponent<Transform>()->SetPosition(-thickness / 2, height / 2);
	collisionTest->GetComponent<RigidBody>()->width = thickness;
	collisionTest->GetComponent<RigidBody>()->height = height;
	collisionTest->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest->GetComponent<RectRenderer>()->width = thickness;
	collisionTest->GetComponent<RectRenderer>()->height = height;
	collisionTest->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	// Top Wall
	auto* collisionTest1 = AddEntity<StaticCollider>();

	collisionTest1->GetComponent<Transform>()->SetPosition(width / 2, -thickness / 2);
	collisionTest1->GetComponent<RigidBody>()->width = width;
	collisionTest1->GetComponent<RigidBody>()->height = thickness;
	collisionTest1->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest1->GetComponent<RectRenderer>()->width = width;
	collisionTest1->GetComponent<RectRenderer>()->height = thickness;
	collisionTest1->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	// Right Wall
	auto* collisionTest2 = AddEntity<StaticCollider>();

	collisionTest2->GetComponent<Transform>()->SetPosition(width + thickness / 2, height / 2);
	collisionTest2->GetComponent<RigidBody>()->width = thickness;
	collisionTest2->GetComponent<RigidBody>()->height = height;
	collisionTest2->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest2->GetComponent<RectRenderer>()->width = thickness;
	collisionTest2->GetComponent<RectRenderer>()->height = height;
	collisionTest2->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	// Bottom Wall
	auto* collisionTest3 = AddEntity<StaticCollider>();

	collisionTest3->GetComponent<Transform>()->SetPosition(width / 2, height + thickness / 2);
	collisionTest3->GetComponent<RigidBody>()->width = width;
	collisionTest3->GetComponent<RigidBody>()->height = thickness;
	collisionTest3->GetComponent<RectRenderer>()->width = width;
	collisionTest3->GetComponent<RectRenderer>()->height = thickness;
	collisionTest3->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	gameManager = AddEntity<GameManager>();

	gameManager->spawnSystem->AddSpawnPoint({ width / 2, height + thickness / 4 });
	gameManager->spawnSystem->AddSpawnPoint({width + thickness / 4, height / 2});
	gameManager->spawnSystem->AddSpawnPoint({width / 2, -thickness / 4});
	gameManager->spawnSystem->AddSpawnPoint({ -thickness / 4, height / 2 });
}

void AssignmentGameLevel::Update(float* timeStep)
{
	Scene::Update(timeStep);
}