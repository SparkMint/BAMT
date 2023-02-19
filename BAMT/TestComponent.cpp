#include "TestComponent.h"

void TestComponent::Start()
{
	
}

void TestComponent::Update() 
{
	DoTheBamt();
}

void TestComponent::LateUpdate()
{

}

void TestComponent::DoTheBamt()
{
	Debug::Log("Bamting");
	TriRenderer* renderer = entity->GetComponent<TriRenderer>();
	if (bamting)
	{
		renderer->point1->x += 20;
		renderer->point2->x += 20;
		renderer->point3->x += 20;
		bamting = false;
	}
	else 
	{
		renderer->point1->x -= 20;
		renderer->point2->x -= 20;
		renderer->point3->x -= 20;
		bamting = true; 
	}

}