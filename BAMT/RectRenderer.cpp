#include "RectRenderer.h"

RectRenderer::RectRenderer(int Width, int Height, bool Fill)
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
	rect->x = (int)_transform->GetX() - rect->w / 2;
	rect->y = (int)_transform->GetY() - rect->h / 2;

	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderDrawRect(renderer, rect);

	if (fillRect)
	{
		// Fill the inside of the Rectangle.
		SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
		SDL_RenderFillRect(renderer, rect);
	}
}

void RectRenderer::UpdateSize(const int width, const int height) const
{
	rect->w = width;
	rect->h = height;
}