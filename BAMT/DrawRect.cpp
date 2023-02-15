#include "DrawRect.h"

DrawRect::DrawRect(float xPos, float yPos, float width, float height)
{
	x = xPos;
	y = yPos;
	w = width;
	h = height;
}

void DrawRect::Render(SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.x = 250;
	rect.y = 150;
	rect.w = 200;
	rect.h = 200;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderPresent(renderer);
}
