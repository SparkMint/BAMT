#include "Transform.h"

Transform::Transform(int x, int y)
{
	SetPosition(x, y);
}

void Transform::Start(){}
void Transform::Update(){}
void Transform::Render(){}

void Transform::SetX(short int x) const { position->x = x; }

void Transform::SetY(short int y) const { position->y = y; }

short int Transform::GetX() const { return position->x; }

short int Transform::GetY() const { return position->y; }

void Transform::Translate(short int x, short int y) const
{
	position->x += x;
	position->y += y;
}

void Transform::SetPosition(short int x, short int y) const
{
	position->x = x;
	position->y = y;
}
