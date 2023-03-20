#include "RigidBody.h"

#include "Scene.h"

void RigidBody::Start()
{
	transform = entity->GetComponent<Transform>();

	if (transform == nullptr)
	{
		Debug::LogWarn("Transform Component was not present on Entity with a RigidBody. Adding one now...");
		transform = entity->AddComponent<Transform>();
	}

	boxCollider = entity->GetComponent<BoxCollider>();

	if (boxCollider == nullptr)
	{
		Debug::LogWarn("BoxCollider Component was not present on Entity with a RigidBody. Adding one now...");
		boxCollider = entity->AddComponent<BoxCollider>();
	}
}

void RigidBody::Update(float* timeStep)
{
	// Simulate the next position for our RigidBody.
	const Vector2 stepPosition = Simulate(timeStep, _velocity, *transform->GetPosition());

	// Check for collisions and react according to them.
	DoCollisionDetection();

	ReactToCollision(timeStep);

	transform->SetPosition(&stepPosition);
}

Vector2 RigidBody::Simulate(const float* timeStep, Vector2 velocity, Vector2 position)
{
	const float speed = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

	// If we are moving, apply drag to the body. 
	if (speed > 0) 
	{
		const float dragForce = drag * speed;
		velocity.x -= (velocity.x / speed) * dragForce * *timeStep;
		velocity.y -= (velocity.y / speed) * dragForce * *timeStep;
	}
	
	// Apply Gravity.
	velocity.x += gravity.x * *timeStep;
	velocity.y += gravity.y * *timeStep;

	// Slow us down if we are going too fast.
	if (speed > maxVelocity) 
	{
		velocity.x = (velocity.x / speed) * maxVelocity;
		velocity.y = (velocity.y / speed) * maxVelocity;
	}

	// Apply the newly made velocity to the position we are going to return.
	position.x += velocity.x * *timeStep;
	position.y += velocity.y * *timeStep;

	// Set the new velocity to be the velocity we calculated in here.
	_velocity = velocity;
	// Return the position
	return position;
}

void RigidBody::AddForce(Vector2 direction, float force)
{
	// We should assume that the direction we are given is already normalized.
	_velocity.x += direction.x * force;
	_velocity.y += direction.y * force;
}

void RigidBody::DoCollisionDetection()
{
	for(Entity* ent : entity->scene->entityList)
	{
		bool passXCheck = false;
		bool passYCheck = false;
		BoxCollider* collider = ent->GetComponent<BoxCollider>();

		// Check for various things.
		if (collider == boxCollider) continue;
		if (collider == nullptr) continue;
		if (!collider->enabled) continue;

		// Check on both axis if this object collided with another. Check on the X axis first, and if nothing comes out of that, we don't
		// need to bother checking the Y axis. This results in slightly better performance.
		if (VectorMath::OverlapOnAxis(collider->transform->GetX(), collider->width, transform->GetX(), boxCollider->width)) passXCheck = true;

		if(passXCheck)
		{
			if (VectorMath::OverlapOnAxis(collider->transform->GetY(), collider->height, transform->GetY(), boxCollider->height)) passYCheck = true;
		}
		// Check if the entity is already a child of the new parent.
		auto iterator = std::find(objectsImCollidingWith.begin(), objectsImCollidingWith.end(), ent);

		if(passXCheck && passYCheck)
		{
			if (iterator == objectsImCollidingWith.end())
			{
				//Debug::Log("Collision Detected with another object! Adding to my Collision List.");
				objectsImCollidingWith.push_back(ent);
				boxCollider->rectRenderer->colour = BAMT_COLOUR_GREEN;
			}
		}
		else
		{
			// We probably had this object in our colliding list. So we should remove it.
			if(iterator != objectsImCollidingWith.end())
			{
				//Debug::Log("Im not longer colliding with an object! Removing this object from my Collision List.");
				objectsImCollidingWith.erase(iterator);
				boxCollider->rectRenderer->colour = BAMT_COLOUR_RED;
			}
		}
	}
}

void RigidBody::ReactToCollision(float* timeStep)
{
	if (isKinematic) return;

	for (auto ent : objectsImCollidingWith)
	{
		BoxCollider* otherCollider = ent->GetComponent<BoxCollider>();
		Transform* otherTransform = ent->GetComponent<Transform>();

		// Calculate the collision normal vector
		Vector2 normal;
		float xOverlap = (boxCollider->width + otherCollider->width) / 2 - fabs(transform->GetX() - otherTransform->GetX());
		float yOverlap = (boxCollider->height + otherCollider->height) / 2 - fabs(transform->GetY() - otherTransform->GetY());
		if (xOverlap < yOverlap)
		{
			if (transform->GetX() < otherTransform->GetX())
			{
				normal = Vector2{ -1, 0 };
			}
			else
			{
				normal = Vector2{ 1, 0 };
			}
		}
		else
		{
			if (transform->GetY() < otherTransform->GetY())
			{
				normal = Vector2{ 0, -1 };
			}
			else
			{
				normal = Vector2{ 0, 1 };
			}
		}

		float penetration = fmax(xOverlap, yOverlap) * 50;
		if(ent->GetComponent<RigidBody>()->isKinematic)
		{
			penetration *= 2;
		}

		AddForce(normal, penetration * *timeStep);
	}
}

/*Vector2 dir = { transform->GetX() - ent->GetComponent<Transform>()->GetX(), transform->GetY() - ent->GetComponent<Transform>()->GetY() };
dir = VectorMath::Normalize(dir);

if(debugMode)
	Debug::Log("Dir X: (" + std::to_string(dir.x) + ") Y: (" + std::to_string(dir.y) + ")");

if (dir.y < 0.5 && dir.x > -0.5) dir.x = 0;
if (dir.y < 0.5 && dir.y > -0.5) dir.y = 0;
if(debugMode)
{
	Debug::Log("Target X: (" + std::to_string(ent->GetComponent<Transform>()->GetX()) + ") Y: (" + std::to_string(ent->GetComponent<Transform>()->GetY()) + ")");
	Debug::Log("My X: (" + std::to_string(transform->GetX()) + ") Y: (" + std::to_string(transform->GetY()) + ")");
	Debug::Log("Dir X: (" + std::to_string(dir.x) + ") Y: (" + std::to_string(dir.y) + ")");
}*/