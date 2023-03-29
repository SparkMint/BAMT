#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(float Width, float Height, const char* spriteLocation)
{
	width = Width;
	height = Height;
	spriteFileLocation = spriteLocation;

	_rect = new SDL_Rect();
}

SpriteRenderer::~SpriteRenderer()
= default;

void SpriteRenderer::Start()
{
	Renderer::Start();
}

void SpriteRenderer::Render(SDL_Renderer* renderer)
{
	if(_texture)
	{
		// Get the height and width of the texture.
		// We will use this to prevent stretching.
		int textureWidth, textureHeight;
		SDL_QueryTexture(_texture, nullptr, nullptr, &textureWidth, &textureHeight);

		// Scale down the given height and width to fit the scale of our world.
		textureWidth /= BAMT_WORLD_SCALE;
		textureHeight /= BAMT_WORLD_SCALE;

		_rect->w = (width * textureWidth * BAMT_WORLD_SCALE *_transform->scale) / 4;
		_rect->h = (height * textureHeight * BAMT_WORLD_SCALE * _transform->scale) / 4;

		_rect->x = roundf((_transform->GetX() * BAMT_WORLD_SCALE - _rect->w * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;
		_rect->y = roundf((_transform->GetY() * BAMT_WORLD_SCALE - _rect->h * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;

		// Display the Sprite.
		SDL_RenderCopy(renderer, _texture, nullptr, _rect);

		//Debug::Log("SPRITE RENDERER VALUES");
		//Debug::Log("----------------------");
		//Debug::Log("Width: " + std::to_string(_rect->w));
		//Debug::Log("Height: " + std::to_string(_rect->h));
		//Debug::Log("X: " + std::to_string(_rect->x));
		//Debug::Log("Y: " + std::to_string(_rect->y));
	}
	else
	{
		const std::string filePathToString = spriteFileLocation;
		Debug::Log("Loading Texture at " + filePathToString, this);
		SDL_Surface* surface = IMG_Load(spriteFileLocation);
		_texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		if(_texture == nullptr)
		{
			Debug::LogError("SpriteRenderer could not load sprite successfully at path: " + filePathToString, this);
		}
	}
}