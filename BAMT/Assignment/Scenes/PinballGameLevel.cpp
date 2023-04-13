#include "PinballGameLevel.h"

void PinballGameLevel::Start()
{
	auto* scoreSystemEnt = AddEntity();
	scoreSystem = scoreSystemEnt->AddComponent<ScoreSystem>();

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

	auto* spawnPoint1 = AddEntity<>();
	spawnPoint1->GetComponent<Transform>()->SetPosition(-thickness / 4, height / 2);
	spawnPoints.push_back(spawnPoint1);

	// Top Wall
	auto* collisionTest1 = AddEntity<StaticCollider>();

	collisionTest1->GetComponent<Transform>()->SetPosition(width / 2, -thickness / 2);
	collisionTest1->GetComponent<RigidBody>()->width = width;
	collisionTest1->GetComponent<RigidBody>()->height = thickness;
	collisionTest1->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest1->GetComponent<RectRenderer>()->width = width;
	collisionTest1->GetComponent<RectRenderer>()->height = thickness;
	collisionTest1->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	auto* spawnPoint2 = AddEntity<>();
	spawnPoint2->GetComponent<Transform>()->SetPosition(width / 2, -thickness / 4);
	spawnPoints.push_back(spawnPoint2);

	// Right Wall
	auto* collisionTest2 = AddEntity<StaticCollider>();

	collisionTest2->GetComponent<Transform>()->SetPosition(width + thickness / 2, height / 2);
	collisionTest2->GetComponent<RigidBody>()->width = thickness;
	collisionTest2->GetComponent<RigidBody>()->height = height;
	collisionTest2->GetComponent<RigidBody>()->isKinematic = true;
	collisionTest2->GetComponent<RectRenderer>()->width = thickness;
	collisionTest2->GetComponent<RectRenderer>()->height = height;
	collisionTest2->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	auto* spawnPoint3 = AddEntity<>();
	spawnPoint3->GetComponent<Transform>()->SetPosition(width + thickness / 4, height / 2);
	spawnPoints.push_back(spawnPoint3);

	// Bottom Wall
	auto* collisionTest3 = AddEntity<StaticCollider>();

	collisionTest3->GetComponent<Transform>()->SetPosition(width / 2, height + thickness / 2);
	collisionTest3->GetComponent<RigidBody>()->width = width;
	collisionTest3->GetComponent<RigidBody>()->height = thickness;
	collisionTest3->GetComponent<RectRenderer>()->width = width;
	collisionTest3->GetComponent<RectRenderer>()->height = thickness;
	collisionTest3->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_GREEN;

	auto* spawnPoint4 = AddEntity<>();
	spawnPoint4->GetComponent<Transform>()->SetPosition(width / 2, height + thickness / 4);
	spawnPoints.push_back(spawnPoint4);

	auto* coordGrid = AddEntity<CoordinateGrid>();
	coordGrid->renderLayer = -1;

	_player = AddEntity<Player>();

	auto* enemyPoolEnt = AddEntity();
	enemyPool = enemyPoolEnt->AddComponent<EntityPooler>();



	for (int i = 0; i < maxZombieCount; ++i)
	{
		auto* enemy = AddEntity<Enemy>();
		enemy->maxHealth = 5;
		enemy->movementSpeed = 30;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .3f;
		enemy->height = .3f;

		// RB Stuff
		enemy->maxSpeed = 40;
		enemy->mass = 1;
		enemy->dragForce = 5;
		enemy->bounciness = .2f;
		enemy->weaponData = WEAPON_DATA_ZOMBIE;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->UpdateTarget(_player);
		enemy->active = false;
	}

	for (int i = 0; i < maxRangedCount; ++i)
	{
		auto* enemy = AddEntity<Enemy>();
		enemy->maxHealth = 2;
		enemy->movementSpeed = 3;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .5f;
		enemy->height = .5f;

		// RB Stuff
		enemy->maxSpeed = 40;
		enemy->mass = .6f;
		enemy->dragForce = 5;
		enemy->bounciness = .4f;
		enemy->weaponData = WEAPON_DATA_RANGER;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->UpdateTarget(_player);
		enemy->active = false;
	}

	for (int i = 0; i < maxTankCount; ++i)
	{
		auto* enemy = AddEntity<Enemy>();
		enemy->maxHealth = 10;
		enemy->movementSpeed = 10;
		enemy->sprite = "enemyPlaceholder.png";

		enemy->width = .8f;
		enemy->height = .8f;

		// RB Stuff
		enemy->maxSpeed = 40;
		enemy->mass = 5;
		enemy->dragForce = 5;
		enemy->bounciness = .2f;
		enemy->weaponData = WEAPON_DATA_TANK;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->UpdateTarget(_player);
		enemy->active = false;
	}

	
}

void PinballGameLevel::Update(float* timeStep)
{
	Scene::Update(timeStep);

	if (time < enemySpawnSpeedSeconds)
	{
		time += *timeStep;
	}
	else
	{
		time = 0;
		Entity* enemyBase = enemyPool->GetRandomAvaliableObject();

		Enemy* enemy = dynamic_cast<Enemy*>(enemyBase);
		if (enemy == nullptr) return;
		enemy->Init();

		int spawnPoint = rand() % spawnPoints.size();
		enemy->transform->SetPosition(spawnPoints[spawnPoint]->transform->GetPosition());

		enemy->active = true;
	}
}