#ifndef BAMT_MOVE_MOUSE
#define BAMT_MOVE_MOUSE
#include "Component.h"
#include "Transform.h"
#include <vector>

class PlayerMoveMouse : public Component
{
public:
	/// <summary>
	/// Transform of the entity we are attached to.
	/// </summary>
	Transform* transform = nullptr;

	std::vector<Vector2*> positions;

	int movementdelay = 0;

	void Start() override;

	void Update() override;

	void Render(SDL_Renderer* renderer) override;
};
#endif