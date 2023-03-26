#include "TriRenderer.h"

TriRenderer::TriRenderer(int triSize)
{
	size = triSize;
}

void TriRenderer::Start()
{
	// Try get a transform
	transform = entity->GetComponent<Transform>();
}

void TriRenderer::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	//point1 = transform->GetX(), transform->SetY() - size / 2;
	//point2 = transform->GetX() - size / 2, transform->SetY() + size / 2 ;
	//point3 = transform->GetX() + size / 2, transform->SetY() + size / 2 ;

	SDL_RenderDrawLine(renderer, (int)transform->GetX(), (int)transform->GetY() - size * 0.5f,
		(int)transform->GetX() - size * 0.5f, (int)transform->GetY() + size * 0.5f);

	SDL_RenderDrawLine(renderer, (int)transform->GetX() - size / 2, (int)transform->GetY() + size * 0.5f,
		(int)transform->GetX() + size * 0.5f, (int)transform->GetY() + size * 0.5f);

	SDL_RenderDrawLine(renderer, (int)transform->GetX(), (int)transform->GetY() - size * 0.5f,
		(int)transform->GetX() + size * 0.5f, (int)transform->GetY() + size * 0.5f);
}
