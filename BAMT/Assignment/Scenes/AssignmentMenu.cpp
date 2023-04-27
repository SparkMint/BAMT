#include "AssignmentMenu.h"

void AssignmentMenu::Start()
{
	auto* button = AddEntity();
	button->transform->SetPosition(1, 1);
	auto* buttonComponent = button->AddComponent<Button>();
	buttonComponent->width = buttonComponent->height = 1;
}

void AssignmentMenu::Update(float* timeStep)
{

}