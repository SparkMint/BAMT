#ifndef BAMT_BOX_COLLIDER
#define BAMT_BOX_COLLIDER
#include "Component.h"
#include "RectRenderer.h"

class BoxCollider : public Component
{
	public:
		Transform* transform = nullptr;
		RectRenderer* rectRenderer = nullptr;

		int height;
		int width;

		BoxCollider(int Width = 0, int Height = 0);

		void Start() override;
		void Update(float* timeStep) override;
		void DebugMode(bool active) const;
};
#endif