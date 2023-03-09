#include "Transform.h"

#include <cmath>

Vector2 Vector2::Normalize()
{
	const float magnitude = sqrt(x * x + y * y);
	Vector2 normalizedVector = *this;
	if (magnitude == 0)
	{
		normalizedVector.x = 0;
		normalizedVector.y = 0;
		return normalizedVector;
	}

	normalizedVector.x /= magnitude;
	normalizedVector.y /= magnitude;
	return normalizedVector;
}

bool Vector2::operator==(const Vector2* vector) const
{
	return this->x == vector->x && this->y == vector->y;
}

Transform::Transform(float x, float y)
{
	SetPosition(x, y);
}

void Transform::Start(){}
void Transform::Update(float* timeStep){}
void Transform::Render(SDL_Renderer* renderer){}

void Transform::SetX(float x) const { _position->x = x; }

void Transform::SetY(float y) const { _position->y = y; }

float Transform::GetX() const { return _position->x; }

float Transform::GetY() const { return _position->y; }

void Transform::Translate(int x, int y) const
{
	_position->x += x;
	_position->y += y;
}

void Transform::Translate(float x, float y) const
{
	_position->x += x;
	_position->y += y;
}

void Transform::SetPosition(float x, float y) const
{
	_position->x = x;
	_position->y = y;
}

void Transform::SetPosition(const Vector2* position) const
{
	_position->x = position->x;
	_position->y = position->y;
}

Vector2* Transform::GetPosition() const
{
	return _position;
}
