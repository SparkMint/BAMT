#include "Slingshot.h"

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

	box = scene->AddEntity<PhysicsCube>();
	box->rigidBody->maxVelocity = 20;
	box->rigidBody->mass = 1;
	box->rigidBody->drag = 2;
	//box->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_RED;

	leftLine = AddComponent<LineRenderer>();
	leftLine->Position1 = { leftPole->transform->GetX(), leftPole->transform->GetY() - poleHeight / 2 };
	rightLine = AddComponent<LineRenderer>();
	rightLine->Position1 = { rightPole->transform->GetX(), rightPole->transform->GetY() - poleHeight / 2 };
}

void Slingshot::Update(float* timeStep) const
{
	Entity::Update(timeStep);
	Vector2 mousePos = Input::GetMousePosition();

	if(Input::GetMouseButtonHold(SDL_BUTTON_LEFT))
	{
		box->transform->SetPosition(&mousePos);
	}
	else 
	{
		Vector2 dir = Vector2{ transform->GetX() - box->transform->GetX() , (transform->GetY() - poleHeight / 2) - box->transform->GetY() };
		box->GetComponent<RigidBody>()->AddForce(dir, 200);
	}
	leftLine->Position2 = *box->transform->GetPosition();
	rightLine->Position2 = *box->transform->GetPosition();
}
