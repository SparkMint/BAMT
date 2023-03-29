#ifndef BAMT_IMAGE_RENDERER
#define BAMT_IMAGE_RENDERER

#include "Renderer.h"
#include "SDL_image.h"
#include "../EngineSettings.h"

class SpriteRenderer : public Renderer
{
	SDL_Texture* _texture = nullptr;
	SDL_Rect* _rect = nullptr;
	public:
		///<summary>
		/// Location of the Sprite we want to render.
		///</summary>
		const char* sprite;

		float width = 1;
		float height = 1;

		/// <summary>
		/// Constructs a rectangle with specified inputs.
		/// </summary>
		/// <param name="Width">- The width of the Sprite.</param>
		/// <param name="Height">- The width of the Sprite.</param>
		/// <param name="spriteLocation">Location of the sprite we want to load.</param>
		SpriteRenderer(float Width = 0, float Height = 0, const char* spriteLocation = "");
		~SpriteRenderer();

		void Render(SDL_Renderer* renderer) override;
		void Start() override;
};
#endif