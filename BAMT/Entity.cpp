#include "Entity.h"

Entity::Entity()
{
	active = true;
}


void Entity::Update() const
{
	for (Component* c : _components) c->Update();
}

void Entity::Render(SDL_Renderer* renderer) const
{
	for (Component* c : _components) c->Render(renderer);
}