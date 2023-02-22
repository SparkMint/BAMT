#include "RectRenderer.h"
#include <time.h>
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
	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255;
	int a = rand() % 255;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawRect(renderer, rect);

	if (fillRect)
	{
		// Fill the inside of the Rectangle.
		SDL_SetRenderDrawColor(renderer,  r, g, b, a);
		SDL_RenderFillRect(renderer, rect);
	}
}

void RectRenderer::UpdateSize(int width, int height)
{
	rect->w = width;
	rect->h = height;
}