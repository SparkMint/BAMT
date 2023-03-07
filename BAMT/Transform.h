#ifndef BAMT_TRANSFORM
#define BAMT_TRANSFORM

#include "Component.h"

class Entity;
class Component;


struct Vector2
{
	float x = 0;
	float y = 0;

	Vector2 Normalize();

	bool operator ==(const Vector2* vector) const;
};

class Transform : public Component
{
	Vector2* position = new Vector2{0, 0};

	public:
		Transform(float x = 0, float y = 0);

		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;


		// Getter / Setter Functions

		void SetX(float x) const;
		void SetY(float y) const;

		float GetX() const;
		float GetY() const;


		/// <summary>
		/// Moves this transform by X and Y.
		/// </summary>
		void Translate(int x, int y) const;

		/// <summary>
		/// Moves this transform by X and Y.
		/// </summary>
		void Translate(float x, float y) const;

		/// <summary>
		/// Sets the position of the Transform to a specified location.
		/// </summary>
		void SetPosition(float x = 0, float y = 0) const;
};
#endif