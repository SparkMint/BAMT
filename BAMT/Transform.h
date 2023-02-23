#ifndef BAMT_TRANSFORM
#define BAMT_TRANSFORM

#include "Component.h"
#include "Entity.h"

class Entity;
class Component;


struct Vector2
{
	int x = 0;
	int y = 0;
};

class Transform : public Component
{
	Vector2* position = new Vector2{0, 0};

	public:
		Transform(int x = 0, int y = 0);

		void Start() override;
		void Update() override;
		void Render(SDL_Renderer* renderer) override;


		// Getter / Setter Functions

		void SetX(int x) const;
		void SetY(int y) const;

		int GetX() const;
		int GetY() const;


		/// <summary>
		/// Moves this transform by X and Y.
		/// </summary>
		void Translate(int x, int y) const;

		/// <summary>
		/// Sets the position of the Transform to a specified location.
		/// </summary>
		void SetPosition(int x = 0, int y = 0) const;
};
#endif