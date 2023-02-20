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
	transform = entity->GetComponent<Transform>();
	if (!transform)
	{
		Debug::LogError("No Transform found on this entity!");
	}
}

void RectRenderer::Update()
{
}

void RectRenderer::LateUpdate()
{
	Render(entity->renderer);
}
void RectRenderer::Render(SDL_Renderer* renderer)
{
	rect->x = transform->x() - rect->w / 2;
	rect->y = transform->y() - rect->h / 2;
	// Draw the outline for the Rectangle.
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, rect);

	if (fillRect)
	{
		// Fill the inside of the Rectangle.
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, rect);
	}
	SDL_RenderPresent(renderer);
}