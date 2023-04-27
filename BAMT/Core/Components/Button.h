#ifndef BAMT_BUTTON
#define BAMT_BUTTON

#include "Component.h"
#include "RectRenderer.h"
#include "Input.h"

class Button : public Component
{
	RectRenderer* renderer;

	Colour normalColour = BAMT_COLOUR_WHITE;
	Colour highlightedColour = BAMT_COLOUR_GREEN;

	public:
		float width = 1;
		float height = 1;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif