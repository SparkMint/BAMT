#include "Transform.h"

#include <cmath>

namespace VectorMath
{
	float Distance(const Vector2& v1, const Vector2& v2)
	{
		const float x = pow(v2.x - v1.x, 2);
		const float y = pow(v2.y - v1.y, 2);
		return sqrt(x + y);
	}

	Vector2 Normalize(const Vector2& vector)
	{
		const float magnitude = Magnitude(vector);

		// If the Magnitude is zero. Return Zero.
		if (magnitude == 0)	return { 0,0 };

		return { vector.x / magnitude, vector.y / magnitude };
	}

	float Magnitude(const Vector2& vector)
	{
		return sqrt(vector.x * vector.x + vector.y * vector.y);
	}
}

bool Vector2::operator==(const Vector2& vector) const
{
	return this->x == vector.x && this->y == vector.y;
}

Transform::Transform(float x, float y) : _position(new Vector2{ x, y }){ }

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