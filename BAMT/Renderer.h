#ifndef BAMT_RENDERER
#define BAMT_RENDERER

#include "Component.h"
#include "Transform.h"
#include "Colour.h"

class Renderer : public Component
{
	protected:
		Transform* _transform = nullptr;

	public:
		Colour colour = BAMT_COLOUR_WHITE;

		void Start() override;
};
#endif