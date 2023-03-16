#include "Entity.h"

Entity::Entity()
{
	active = true;
	Debug::Log("Entity Created.", this);
}

Entity::~Entity()
{
	// Clear all memory taken up by this entity.
	for (Component* c : _components)
	{
		delete(c);
	}
	Debug::Log("Entity Destroyed.", this);
}

void Entity::Start()
{
}

void Entity::Update(float* timeStep) const
{
	for (Component* c : _components)
	{
		if(c->enabled)
			c->Update(timeStep);
	}
}

void Entity::Render(SDL_Renderer* renderer) const
{
	for (Component* c : _components)
	{
		if (c->enabled)
			c->Render(renderer);
	}
}

