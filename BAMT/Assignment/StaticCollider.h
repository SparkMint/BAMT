#ifndef BAMT_STATIC_COLLIDER
#define BAMT_STATIC_COLLIDER

#include "../Core/ECS/Entity.h"
#include "../Core/Components/Transform.h"
#include "../Core/Components/RectRenderer.h"
#include "../Core/Components/RigidBody.h"

class StaticCollider : public Entity
{
public:
	Transform* transform = nullptr;
	RigidBody* rigidBody = nullptr;
	RectRenderer* rectRenderer = nullptr;

	// Shared Values
	float width = 0;
	float height = 0;

	// RigidBody Values
	float bounciness = 1;

	// RectRenderer Values
	bool fillRect = true;


	void Start() override;
};
#endif
