#include "TriRenderer.h"

TriRenderer::TriRenderer(short int triSize)
{
	size = triSize;
}

void TriRenderer::Start()
{
	// Try get a transform
	transform = entity->GetComponent<Transform>();
}

void TriRenderer::Update()
{
}

void TriRenderer::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	//point1 = transform->GetX(), transform->SetY() - size / 2;
	//point2 = transform->GetX() - size / 2, transform->SetY() + size / 2 ;
	//point3 = transform->GetX() + size / 2, transform->SetY() + size / 2 ;

	SDL_RenderDrawLine(renderer, transform->GetX(), transform->GetY() - size / 2,
		transform->GetX() - size / 2, transform->GetY() + size / 2);

	SDL_RenderDrawLine(renderer, transform->GetX() - size / 2, transform->GetY() + size / 2,
		transform->GetX() + size / 2, transform->GetY() + size / 2);

	SDL_RenderDrawLine(renderer, transform->GetX(), transform->GetY() - size / 2,
		transform->GetX() + size / 2, transform->GetY() + size / 2);
}
