#include "RectRenderer.h"

RectRenderer::RectRenderer(int width, int height, bool fill)
{
	rect = new SDL_Rect();
	rect->w = width;
	rect->h = height;
	fillRect = fill;
}

void RectRenderer::Start()
{
	// Try get a transform
	_transform = entity->GetComponent<Transform>();
	if (_transform == nullptr)
	{
		Debug::LogError("No Transform found on this entity!");
	}
}

void RectRenderer::Update(float* timeStep)
{
}

void RectRenderer::Render(SDL_Renderer* renderer)
{
	rect->x = (int)_transform->GetX() - rect->w / 2;
	rect->y = (int)_transform->GetY() - rect->h / 2;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, rect);

	if (fillRect)
	{
		// Fill the inside of the Rectangle.
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, rect);
	}
}

void RectRenderer::UpdateSize(int width, int height)
{
	rect->w = width;
	rect->h = height;
}