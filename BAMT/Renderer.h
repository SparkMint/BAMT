#ifndef BAMT_RENDERER
#define BAMT_RENDERER

#include "Entity.h"
#include "Component.h"
#include "Transform.h"
#include "Colour.h"

class Transform;

class Renderer : public Component
{
	protected:
		///<summary>
		/// The Position of the object within the game world.
		///</summary>
		Transform* _transform = nullptr;

		///<summary>
		/// Determines the size of the game world. By Default. One 100 pixel is classed as one BAMT unit
		///</summary>
		int scaleMultiplier = 100;

	public:
		Colour colour = BAMT_COLOUR_WHITE;

		void Start() override;
};
#endif