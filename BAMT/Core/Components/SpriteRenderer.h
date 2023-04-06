#ifndef BAMT_SPRITE_RENDERER
#define BAMT_SPRITE_RENDERER

#include "Renderer.h"
#include "SDL_image.h"
#include "../EngineSettings.h"

class SpriteRenderer : public Renderer
{
	SDL_Texture* _texture = nullptr;
	SDL_Rect* _rect = nullptr;
	SDL_Rect* _animationRect = nullptr;

	int w = 1;
	int h = 1;

	float time = 0;
	float _timeStep = 0;

	///<summary>
	/// Location of the Sprite we want to render.
	///</summary>
	const char* sprite;

	public:

		///<summary>
		/// Width of the sprite when rendered.
		///</summary>
		float width = 1;

		///<summary>
		/// Height of the sprite when Rendered.
		///</summary>
		float height = 1;


		// ANIMATION SETTINGS

		///<summary>
		/// Determines if the sprite should be animated.
		///</summary>
		bool animate = false;

		///<summary>
		/// Width of the SpriteSheet
		///</summary>
		int spriteSheetWidth = 1;

		///<summary>
		/// Height of the SpriteSheet
		///</summary>
		int spriteSheetHeight = 1;

		///<summary>
		/// How much time must pass before the next frame of animation is shown?
		///</summary>
		float animationSpeedSeconds = 1;

		/// <summary>
		/// Constructs a rectangle with specified inputs.
		/// </summary>
		/// <param name="Width">- The width of the Sprite.</param>
		/// <param name="Height">- The width of the Sprite.</param>
		/// <param name="projectileSprite">Location of the sprite we want to load.</param>
		SpriteRenderer(float Width = 0, float Height = 0, const char* spriteLocation = "");

		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;

		void SetSprite(const char* targetSprite);

};
#endif