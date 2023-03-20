#include "Scene.h"

void Scene::Start(){ }

void Scene::Update(float* timeStep)
{
	SortRigidBodies();

	//TODO: Your problem. I got this working, you make it look nice.
	std::vector<RigidBody*> activeInterval;
	for(int i = 0; i < rigidBodiesList.size(); ++i)
	{
		rigidBodiesList[i]->collisionList.clear();
		for (int j = 0; j < activeInterval.size(); ++j)
		{
			if (rigidBodiesList[i] == activeInterval[j]) continue;
			if(rigidBodiesList[i]->transform->GetX() - (rigidBodiesList[i]->colliderWidth * 0.5f) > activeInterval[j]->transform->GetX() + (activeInterval[j]->colliderWidth * 0.5f))
			{
				activeInterval.erase(activeInterval.begin() + j);
				j--;
			}
			else
			{
				if (VectorMath::OverlapOnAxis(rigidBodiesList[i]->transform->GetY(), rigidBodiesList[i]->colliderHeight, activeInterval[j]->transform->GetY() , activeInterval[j]->colliderHeight))
				{
					rigidBodiesList[i]->ReactToCollisions(activeInterval[j]);
					activeInterval[j]->ReactToCollisions(rigidBodiesList[i]);

					if(!rigidBodiesList[i]->collisionList.empty())
					{
						auto iterator = std::find(rigidBodiesList[i]->collisionList.begin(), rigidBodiesList[i]->collisionList.end(), activeInterval[j]);

						if (iterator == rigidBodiesList[i]->collisionList.end())
							rigidBodiesList[i]->collisionList.push_back(activeInterval[j]);
					}
					else
					{
						rigidBodiesList[i]->collisionList.push_back(activeInterval[j]);
					}

					if (!activeInterval[j]->collisionList.empty())
					{
						auto iterator = std::find(activeInterval[j]->collisionList.begin(), activeInterval[j]->collisionList.end(), rigidBodiesList[i]);

						if (iterator == activeInterval[j]->collisionList.end())
							activeInterval[j]->collisionList.push_back(rigidBodiesList[i]);
					}
					else
					{
						activeInterval[j]->collisionList.push_back(activeInterval[j]);
					}
				}
			}
		}
		activeInterval.push_back(rigidBodiesList[i]);
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
