#include "Entity.h"

Entity::Entity()
{
	active = true;
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