#include "Entity.h"

Entity::Entity()
{
	active = true;
	renderer = NULL;
}

Entity::Entity(SDL_Renderer* SDLRenderer)
{
	active = true;
	renderer = SDLRenderer;
}

void Entity::ComponentsCallUpdate()
{
	for (Component* c : components) c->Update();
}

void Entity::ComponentsCallLateUpdate()
{
	for (Component* c : components) c->LateUpdate();
}