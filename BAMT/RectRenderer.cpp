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

void RectRenderer::Render()
{
	DrawRectangle(entity->renderer);
}
void RectRenderer::DrawRectangle(SDL_Renderer* renderer)
{
	rect->x = transform->GetX() - rect->w / 2;
	rect->y = transform->GetY() - rect->h / 2;
	// Draw the outline for the Rectangle.
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, rect);

	if (fillRect)
	{
		// Fill the inside of the Rectangle.
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, rect);
	}
}