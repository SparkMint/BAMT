#include "Scene.h"

#include "EngineSettings.h"

void Scene::Start(){ }

void Scene::Update(float* timeStep)
{
	for (int i = 0; i < BAMT_PHYSICS_STEPS; ++i)
	{
		DetectCollisions();
	}

	for (const Entity* entity : entityList)
	{
		if (entity->active)
			entity->Update(timeStep);
	}
}

void Scene::Render(SDL_Renderer* renderer) const
{
	for (const Entity* entity : entityList)
	{
		if (entity->active)
			entity->Render(renderer);
	}
}

void Scene::SortEntities()
{
	std::sort(entityList.begin(), entityList.end(), [](const Entity* a, const Entity* b)
		{return a->renderLayer < b->renderLayer; });
}

void Scene::SortRigidBodies()
{
	std::sort(rigidBodiesList.begin(), rigidBodiesList.end(), [](const RigidBody* a, const RigidBody* b)
		{return a->transform->GetX() - a->colliderWidth * 0.5f < b->transform->GetX() - b->colliderWidth * 0.5f; });
}

void Scene::DetectCollisions()
{
	SortRigidBodies();

	std::vector<RigidBody*> activeInterval;
	activeInterval.reserve(rigidBodiesList.size());

	// Initialise a list of collisions we could find.
	std::vector<std::pair<RigidBody*, RigidBody*>> collisionPairs;
	collisionPairs.reserve(rigidBodiesList.size() * (rigidBodiesList.size() - 1) / 2);

	for (auto& i : rigidBodiesList)
	{
		// Clear this RigidBodies collision list. As it will update here.
		i->collisionList.clear();


		for(int j = 0; j < activeInterval.size(); ++j)
		{
			if (i->transform->GetX() - (i->colliderWidth * 0.5f) > activeInterval[j]->transform->GetX() + (activeInterval[j]->colliderWidth * 0.5f))
			{
				activeInterval.erase(activeInterval.begin() + j);
				j--;
			}
			else
			{
				if (VectorMath::OverlapOnAxis(i->transform->GetY(), i->colliderHeight, activeInterval[j]->transform->GetY(), activeInterval[j]->colliderHeight))
				{
					collisionPairs.emplace_back(i, activeInterval[j]);
				}
			}
		}
		activeInterval.emplace_back(i);
	}

	SolveRigidBodyCollisions(collisionPairs);
}

void Scene::SolveRigidBodyCollisions(std::vector<std::pair<RigidBody*, RigidBody*>> collisionPairs) const
{
	for (auto pair : collisionPairs)
	{
		pair.first->collisionList.emplace_back(pair.second);
		pair.second->collisionList.emplace_back(pair.first);

		Vector2 relativeVelocity = pair.second->GetVelocity() - pair.first->GetVelocity();

		Vector2 collisionNormal;
		const float xOverlap = (pair.first->colliderWidth + pair.second->colliderWidth) * 0.5f - fabs(pair.first->transform->GetX() - pair.second->transform->GetX());
		const float yOverlap = (pair.first->colliderHeight + pair.second->colliderHeight) * 0.5f - fabs(pair.first->transform->GetY() - pair.second->transform->GetY());

		// Calculate the bounce of the collision
		const float bounce = min(pair.first->bounciness, pair.second->bounciness);

		if (xOverlap < yOverlap)
		{
			if (pair.first->transform->GetX() < pair.second->transform->GetX())
			{
				collisionNormal = Vector2{ 1, 0 };
			}
			else
			{
				collisionNormal = Vector2{ -1, 0 };
			}
		}
		else
		{
			if (pair.first->transform->GetY() < pair.second->transform->GetY())
			{
				collisionNormal = Vector2{ 0, 1 };
			}
			else
			{
				collisionNormal = Vector2{ 0, -1 };
			}
		}

		const float relativeVelocityInNormalDirection = VectorMath::Dot(relativeVelocity, collisionNormal);

		// Check if the objects are moving away from each other
		if (relativeVelocityInNormalDirection > 0)
		{
			continue;
		}


		// Calculate the impulse force
		const float impulseScalar = -(1.0f + bounce) * relativeVelocityInNormalDirection / (-pair.first->mass + -pair.second->mass);

		pair.first->AddForce(collisionNormal, impulseScalar);
		pair.second->AddForce(collisionNormal, -impulseScalar);

		const Vector2 displacement = {collisionNormal.x * xOverlap, collisionNormal.y * yOverlap};
		if(!pair.first->isKinematic)
		{
			pair.first->transform->Translate(-displacement.x / 2, -displacement.y / 2);
		}
		if(!pair.second->isKinematic)
		{
			pair.second->transform->Translate(displacement.x / 2, displacement.y / 2);
		}



	}
}

Scene::Scene()
{
	Debug::Log("Scene Created.", this);
}
Scene::~Scene()
{
	Debug::Log("Scene Destroyed.", this);

	for (const Entity* entity : entityList)
	{
		delete(entity);
	}
}

/*
 * 		if (!pair[0]->collisionList.empty())
		{
			auto iterator = std::find(pair[0]->collisionList.begin(), pair[0]->collisionList.end(), pair[1]);

			if (iterator == pair[0]->collisionList.end())

		}

		if (!pair[1]->collisionList.empty())
		{
			auto iterator = std::find(pair[1]->collisionList.begin(), pair[1]->collisionList.end(), pair[0]);

			if (iterator == pair[1]->collisionList.end())

		}
 */