#ifndef BAMT_STATIC_COLLIDER
#define BAMT_STATIC_COLLIDER

#include "Entity.h"
#include "Transform.h"
#include "RectRenderer.h"
#include "RigidBody.h"

class StaticCollider : public Entity
{
public:
	Transform* transform = nullptr;
	RigidBody* rigidBody = nullptr;
	RectRenderer* rectRenderer = nullptr;

	// Shared Values
	float width = .4f;
	float height = 0.4f;

	// RigidBody Values
	float bounciness = 100;

	// RectRenderer Values
	bool fillRect = false;


	void Start() override;
};
#endif
