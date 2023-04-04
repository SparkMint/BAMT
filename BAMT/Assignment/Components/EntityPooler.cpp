#include "EntityPooler.h"

void EntityPooler::Start()
{
	Component::Start();
}

void EntityPooler::Update(float* timeStep)
{
	Component::Update(timeStep);
}

void EntityPooler::AddEntityToPool(Entity* entityToAdd)
{
	entityPool.push_back(entityToAdd);
}

Entity* EntityPooler::GetAvaliableObject()
{
	for (const auto object : entityPool)
	{
		if(!object->active)
		{
			return object;
		}
	}
	// If all objects in the pool are active, return nothing.
	return nullptr;
}