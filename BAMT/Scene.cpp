#include "Scene.h"

void Scene::Start(){ }

void Scene::Update(float* timeStep) const
{
	for (const Entity* entity : _entityList)
	{
		if (entity->active)
			entity->Update(timeStep);
	}
}

void Scene::Render(SDL_Renderer* renderer) const
{
	for (const Entity* entity : _entityList)
	{
		if (entity->active)
			entity->Render(renderer);
	}
}

void Scene::SortEntities()
{
	std::sort(_entityList.begin(), _entityList.end(), [](const Entity* a, const Entity* b)
		{return a->renderLayer < b->renderLayer; });
}

Scene::Scene()
{
	Debug::Log("Scene Created.", this);
}

Scene::~Scene()
{
	Debug::Log("Scene Destroyed.", this);

	for (const Entity* entity : _entityList)
	{
		delete(entity);
	}
}
