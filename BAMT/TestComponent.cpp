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
	if (bamting)
	{
		bamting = false;
	}
	else 
	{
		bamting = true; 
	}
}