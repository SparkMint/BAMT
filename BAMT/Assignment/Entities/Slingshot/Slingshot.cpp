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

	box = scene->AddEntity<>();
	box->AddComponent<RectRenderer>(.5f, .5f, true);
	box->GetComponent<RectRenderer>()->colour = BAMT_COLOUR_RED;

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
		leftLine->Position2 = mousePos;
		rightLine->Position2 = mousePos;
		box->transform->SetPosition(&mousePos);
	}
}
