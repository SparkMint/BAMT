#include "Transform.h"

Transform::Transform(int x, int y)
{
	_xPos = x;
	_yPos = y;
}

void Transform::Start()
{
	
}
void Transform::Update()
{
	
}
void Transform::LateUpdate()
{
	
}

int Transform::x() const { return _xPos; }
int Transform::y() const { return _yPos; }

void Transform::Translate(int x, int y)
{
	_xPos += x;
	_yPos += y;
}