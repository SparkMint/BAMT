#include "Scene.h"

#include "EngineSettings.h"

void Scene::Start(){ }

void Scene::Update(float* timeStep)
{
	for (int i = 0; i < BAMT_PHYSICS_STEPS; ++i)
	{
		HandleCollisionLogic();
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

void Scene::HandleCollisionLogic()
{
	SortRigidBodies();

	//TODO: Your problem now me. I got this working, you make it look nice.

	// Screw you :(
	std::vector<RigidBody*> activeInterval;
	for (auto& i : rigidBodiesList)
	{
		// Clear this RigidBodies collision list. As it will update here.
		i->collisionList.clear();

		for(int j = 0; j < activeInterval.size(); ++j)
		{
			//if (rigidBodiesList[i] == activeInterval[j]) continue;
			if (i->transform->GetX() - (i->colliderWidth * 0.5f) > activeInterval[j]->transform->GetX() + (activeInterval[j]->colliderWidth * 0.5f))
			{
				activeInterval.erase(activeInterval.begin() + j);
				j--;
			}
			else
			{
				if (VectorMath::OverlapOnAxis(i->transform->GetY(), i->colliderHeight, activeInterval[j]->transform->GetY(), activeInterval[j]->colliderHeight))
				{
					i->ReactToCollisions(activeInterval[j]);
					activeInterval[j]->ReactToCollisions(i);

					if (!i->collisionList.empty())
					{
						auto iterator = std::find(i->collisionList.begin(), i->collisionList.end(), activeInterval[j]);

						if (iterator == i->collisionList.end())
							i->collisionList.push_back(activeInterval[j]);
					}
					else
					{
						i->collisionList.push_back(activeInterval[j]);
					}

					if (!activeInterval[j]->collisionList.empty())
					{
						auto iterator = std::find(activeInterval[j]->collisionList.begin(), activeInterval[j]->collisionList.end(),
						                          i);

						if (iterator == activeInterval[j]->collisionList.end())
							activeInterval[j]->collisionList.push_back(i);
					}
					else
					{
						activeInterval[j]->collisionList.push_back(activeInterval[j]);
					}
				}
			}
		}
		activeInterval.push_back(i);
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