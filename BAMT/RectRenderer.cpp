#include "RectRenderer.h"

RectRenderer::RectRenderer(float xPos, float yPos, float width, float height) : Renderer()
{
	rect = new SDL_Rect();
	rect->x = xPos;
	rect->y = yPos;
	rect->w = width;
	rect->h = height;
}

void RectRenderer::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderPresent(renderer);
}
