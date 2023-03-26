#include "Component.h"

Component::Component()
{
	Debug::Log("Component Created.", this);
}

Component::~Component()
{
	Debug::Log("Component Destroyed.", this);
}

void Component::Start()
{
	if (!entity)
	{
		Debug::LogError("This component does not have an entity. Disabling.", this);
		enabled = false;
	}
}
void Component::Update(float* timeStep) {}
void Component::Render(SDL_Renderer* renderer) {}
