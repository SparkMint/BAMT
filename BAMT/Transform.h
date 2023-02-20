#ifndef BAMT_TRANSFORM
#define BAMT_TRANSFORM

#include "Component.h"
#include "Entity.h"

class Entity;
class Component;


struct Vector2
{
	short int x = 0;
	short int y = 0;
};

class Transform : public Component
{
	Vector2* position = new Vector2{0, 0};

	public:
		Transform(int x = 0, int y = 0);

		void Start() override;
		void Update() override;
		void Render() override;


		// Getter / Setter Functions

		void SetX(short int x) const;
		void SetY(short int y) const;

		short int GetX() const;
		short int GetY() const;


		/// <summary>
		/// Moves this transform by X and Y.
		/// </summary>
		void Translate(short int x, short int y) const;

		/// <summary>
		/// Sets the position of the Transform to a specified location.
		/// </summary>
		void SetPosition(short int x = 0, short int y = 0) const;
};
#endif