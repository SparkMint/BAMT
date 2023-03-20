#include "BoxCollider.h"

BoxCollider::BoxCollider(int Width, int Height)
{
	width = Width;
	height = Height;
}

void BoxCollider::Start()
{
	transform = entity->GetComponent<Transform>();

	if(transform == nullptr)
	{
		Debug::LogWarn("BoxCollider Component couldn't find a Transform Component. Adding one now...", this);
		transform = entity->AddComponent<Transform>();
	}

	// Add our debug Renderer. And disable it for now.
	rectRenderer = entity->AddComponent<RectRenderer>(width, height, false);
	rectRenderer->colour = BAMT_COLOUR_GREEN;
	rectRenderer->enabled = false;
}

void BoxCollider::Update(float* timeStep)
{

}

void BoxCollider::DebugMode(bool active) const
{
	rectRenderer->enabled = active;
}
