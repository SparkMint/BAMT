#include "Transform.h"

Transform::Transform(int x, int y)
{
	_x = x;
	_y = y;
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

int Transform::x() const { return _x; }
int Transform::y() const { return _y; }

void Transform::Translate(int x, int y)
{
	_x += x;
	_y += y;
}

void Transform::Position(int x, int y)
{
	_x = x;
	_y = y;
}
