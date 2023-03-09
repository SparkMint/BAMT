#include "Component.h"

Component::Component()
{
	Debug::Log("Component Created.", this);
}

Component::~Component()
{
	Debug::Log("Component Destroyed.", this);
}