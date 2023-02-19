#include "TriRenderer.h"

TriRenderer::TriRenderer(int triSize)
{
	size = triSize;
}

void TriRenderer::Start()
{
	// Try get a transform
	transform = entity->GetComponent<Transform>();
	if(!transform)
	{
		Debug::LogError("No Transform found on this entity!");
	}
}

void TriRenderer::Update()
{
	Render(entity->renderer);
}

void TriRenderer::LateUpdate()
{
	Render(entity->renderer);
}

void TriRenderer::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	// Update transform points
	const SDL_Point* point1 = new SDL_Point{ transform->x(), transform->y() - size / 2};
	const SDL_Point* point2 = new SDL_Point{ transform->x() - size / 2, transform->y() + size / 2 };
	const SDL_Point* point3 = new SDL_Point{ transform->x() + size / 2, transform->y() + size / 2 };

	SDL_RenderDrawLine(renderer, point1->x, point1->y,
		point2->x, point2->y);

	SDL_RenderDrawLine(renderer, point2->x, point2->y, 
		point3->x, point3->y);

	SDL_RenderDrawLine(renderer, point1->x, point1->y,
		point3->x, point3->y);

	SDL_RenderPresent(renderer);

	delete(point1);
	delete(point2);
	delete(point3);
}
