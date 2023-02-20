#include "Entity.h"

Entity::Entity(SDL_Renderer* SDLRenderer)
{
	active = true;
	renderer = SDLRenderer;

	//AddComponent<Transform>();
	//transform = GetComponent<Transform>();
}

void Entity::Update()
{
	for (Component* c : _components) c->Update();
}

void Entity::LateUpdate()
{
	for (Component* c : _components) c->LateUpdate();
}