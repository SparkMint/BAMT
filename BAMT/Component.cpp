#include "Component.h"

Component::Component()
{
	Debug::Log("Component Created.", this);
}

Component::~Component()
{
	Debug::Log("Component Destroyed.", this);
}

void Component::Start(){}
void Component::Update(float* timeStep) {}
void Component::Render(SDL_Renderer* renderer) {}
