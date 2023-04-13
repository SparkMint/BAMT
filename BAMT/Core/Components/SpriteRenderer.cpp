#include "SpriteRenderer.h"

#include "../EngineManager.h"
#include "../ECS/Scene.h"

SpriteRenderer::SpriteRenderer(float Width, float Height, const char* spriteLocation)
{
	width = Width;
	height = Height;
	sprite = spriteLocation;

	_rect = new SDL_Rect();
	_animationRect = new SDL_Rect();
}

void SpriteRenderer::Update(float* timeStep)
{
	_timeStep = *timeStep;
}

void SpriteRenderer::Render(SDL_Renderer* renderer)
{
	if(_texture)
	{
		// Get the height and width of the texture.
		// Was using this but keeping it incase i need it later on.
		int textureWidth, textureHeight;
		SDL_QueryTexture(_texture, nullptr, nullptr, &textureWidth, &textureHeight);

		_rect->w = (width * _transform->scale) * BAMT_WORLD_SCALE;
		_rect->h = (height * _transform->scale) * BAMT_WORLD_SCALE;

		_rect->x = roundf((_transform->GetX() * BAMT_WORLD_SCALE - _rect->w * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;
		_rect->y = roundf((_transform->GetY() * BAMT_WORLD_SCALE - _rect->h * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;

		if(animate)
		{
			if (time > animationSpeedSeconds)
			{
				time = 0;
				// Get the width and height of the sprite from the spritesheet.
				_animationRect->w = textureWidth / spriteSheetWidth;
				_animationRect->h = textureHeight / spriteSheetHeight;

				w++;
				if (w > spriteSheetWidth - 1)
				{
					w = 0;
					h++;
				}
				if (h > spriteSheetHeight - 1)
				{
					w = 0;
					h = 0;
				}
				//Debug::Log("W = " + std::to_string(w) + " H: " + std::to_string(h));
			}
			else time += _timeStep;

			_animationRect->x = w * _animationRect->w;
			_animationRect->y = h * _animationRect->h;

			// Display the Sprite.
			SDL_RenderCopy(renderer, _texture, _animationRect, _rect);
		}
		else
		{
			// Display the Sprite.
			SDL_RenderCopy(renderer, _texture, nullptr, _rect);
		}

		//Debug::Log("SPRITE RENDERER VALUES");
		//Debug::Log("----------------------");
		//Debug::Log("Width: " + std::to_string(_rect->w));
		//Debug::Log("Height: " + std::to_string(_rect->h));
		//Debug::Log("X: " + std::to_string(_rect->x));
		//Debug::Log("Y: " + std::to_string(_rect->y));
	}
	else
	{
		_texture = entity->scene->engine->textureAtlas->FindTexture(sprite);

		if(_texture == nullptr)
		{
			Debug::LogError("SpriteRenderer could not load sprite. Setting it to default!", this);
			_texture = entity->scene->engine->textureAtlas->FindTexture("default.png");
			enabled = false;
		}
	}
}

void SpriteRenderer::SetSprite(const char* targetSprite)
{
	sprite = targetSprite;

	// Reset the animation to the beginning.
	w = 1;
	h = 1;
}
