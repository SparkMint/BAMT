#include "Transform.h"

Transform::Transform(int x, int y)
{
	SetPosition(x, y);
}

void Transform::Start(){}
void Transform::Update(){}
void Transform::Render(){}

void Transform::SetX(int x) const { position->x = x; }

void Transform::SetY(int y) const { position->y = y; }

int Transform::GetX() const { return position->x; }

int Transform::GetY() const { return position->y; }

void Transform::Translate(int x, int y) const
{
	position->x += x;
	position->y += y;
}

void Transform::SetPosition(int x, int y) const
{
	position->x = x;
	position->y = y;
}
