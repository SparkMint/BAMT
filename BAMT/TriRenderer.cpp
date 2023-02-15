#include "TriRenderer.h"

TriRenderer::TriRenderer(SDL_Point* p1, SDL_Point* p2, SDL_Point* p3)
{
	point1 = p1;
	point2 = p2;
	point3 = p3;
}

void TriRenderer::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderDrawLine(renderer, point1->x, point1->y, point2->x, point2->y);
	SDL_RenderDrawLine(renderer, point1->x, point1->y, point3->x, point3->y);
	SDL_RenderDrawLine(renderer, point2->x, point2->y, point3->x, point3->y);

	SDL_RenderPresent(renderer);
}
