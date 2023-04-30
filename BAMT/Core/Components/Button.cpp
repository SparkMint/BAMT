#include "Button.h"

void Button::Start()
{
	renderer = entity->GetComponent<RectRenderer>();

	if (renderer == nullptr)
	{
		renderer = entity->AddComponent<RectRenderer>();
	}

	renderer->width = width;
	renderer->height = height;
	renderer->fillRect = true;
}

void Button::Update(float* timeStep)
{
	Debug::Log("Hello");
	// Get the direction of the mouse on the screen.
	const Vector2 mousePos = Input::GetMousePosition();

	if (entity->transform->GetX() - width * 0.5f > mousePos.x + 1 * 0.5f)
	{
		Debug::Log("Mouse Overlapped on X");
	}

	if (VectorMath::OverlapOnAxis(mousePos.x, 1, entity->transform->GetX(), width)
		&& VectorMath::OverlapOnAxis(mousePos.y, 1, entity->transform->GetY(), height))
	{
		renderer->colour = highlightedColour;
	}
	else renderer->colour = normalColour;
}