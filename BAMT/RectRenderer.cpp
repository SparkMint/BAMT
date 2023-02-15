#include "RectRenderer.h"

RectRenderer::RectRenderer(float xPos, float yPos, float width, float height, bool fill) : Renderer()
{
	rect = new SDL_Rect();
	rect->x = xPos;
	rect->y = yPos;
	rect->w = width;
	rect->h = height;
	fillRect = fill;
}

void RectRenderer::Render(SDL_Renderer* renderer)
{
	// Draw the outline for the Rectangle.
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, rect);

	if (!fillRect) return;

	// Fill the inside of the Rectangle.
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, rect);
}