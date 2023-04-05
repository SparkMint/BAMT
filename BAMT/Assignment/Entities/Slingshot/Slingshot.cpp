#include "Slingshot.h"

#include <algorithm>
#include "../../../Core/Misc/BamtMath.h"

constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

void Slingshot::Start()
{
	Entity::Start();

	transform->SetPosition(width / 2, height - poleHeight / 2);

	leftPole = scene->AddEntity<Entity>();
	leftPole->AddComponent<RectRenderer>(poleWidth, poleHeight, true);
	leftPole->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_PURPLE;
	leftPole->transform->SetPosition(transform->GetPosition());
	leftPole->transform->Translate(-poleDistance, 0.0f);


	rightPole = scene->AddEntity<Entity>();
	rightPole->AddComponent<RectRenderer>(poleWidth, poleHeight, true);
	rightPole->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_PURPLE;
	rightPole->transform->SetPosition(transform->GetPosition());
	rightPole->transform->Translate(poleDistance, 0.0f);

	box = scene->AddEntity<Player>();
	box->rigidBody->maxVelocity = 50;
	box->rigidBody->mass = 2;
	box->rigidBody->drag = 5;
	//box->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_RED;

	leftLine = AddComponent<LineRenderer>();
	leftLine->Position1 = { leftPole->transform->GetX(), leftPole->transform->GetY() - poleHeight / 2 };
	rightLine = AddComponent<LineRenderer>();
	rightLine->Position1 = { rightPole->transform->GetX(), rightPole->transform->GetY() - poleHeight / 2 };
}

void Slingshot::Update(float* timeStep)
{
	Entity::Update(timeStep);
	const Vector2 mousePos = Input::GetMousePosition();

	if(Input::GetMouseButtonDown(SDL_BUTTON_LEFT))
	{
		mouseDragBegin = mousePos;
	}
	const Vector2 mouseDragBack = mouseDragBegin - mousePos;

	const Vector2 slingRestTargetPos = { transform->GetX(), transform->GetY() - poleHeight / 4 };

	const Vector2 slingPullBackPos = slingRestTargetPos - mouseDragBack;

	// Get the direction of the box relative to the slingshot.
	const Vector2 slingRestingDirection = slingRestTargetPos - *box->transform->GetPosition();

	const Vector2 slingToMouseDirection = slingPullBackPos - *box->transform->GetPosition();


	if(Input::GetMouseButtonHold(SDL_BUTTON_LEFT))
	{
		box->GetComponent<RigidBody>()->AddReactionForce(slingToMouseDirection, 1000);
		box->GetComponent<RigidBody>()->drag = 10;
	}
	else
	{
		box->GetComponent<RigidBody>()->AddReactionForce(slingRestingDirection, 1000);
	}

	leftLine->Position2 = *box->transform->GetPosition();
	rightLine->Position2 = *box->transform->GetPosition();
}