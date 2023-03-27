#include "RectRenderer.h"



RectRenderer::RectRenderer(float Width, float Height, bool Fill)
{
	width = Width;
	height = Height;
	fillRect = Fill;

	rect = new SDL_Rect();
	UpdateSize(width, height);
}

void RectRenderer::Start()
{
	// Finds or creates Transform on this object.
	Renderer::Start();
}

void RectRenderer::Render(SDL_Renderer* renderer)
{
	rect->x = roundf((_transform->GetX() * BAMT_RENDERER_SCALE - rect->w / 2) * 100) / 100;
	rect->y = roundf((_transform->GetY() * BAMT_RENDERER_SCALE - rect->h / 2) * 100) / 100;

	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderDrawRect(renderer, rect);

	if (fillRect)
	{
		// Fill the inside of the Rectangle.
		SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
		SDL_RenderFillRect(renderer, rect);
	}
}

void RectRenderer::UpdateSize(const float width, const float height) const
{
	rect->w = width * BAMT_RENDERER_SCALE;
	rect->h = height * BAMT_RENDERER_SCALE;
}	