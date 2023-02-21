#include "Entity.h"

Entity::Entity(SDL_Renderer* SDLRenderer)
{
	active = true;
	renderer = SDLRenderer;
}


void Entity::Update() const
{
	for (Component* c : _components) c->Update();
}

void Entity::Render() const
{
	for (Component* c : _components) c->Render();
}