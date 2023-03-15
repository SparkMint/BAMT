#ifndef BAMT_TRANSFORM
#define BAMT_TRANSFORM

#define VECTOR2_UP {0, -1}
#define VECTOR2_LEFT {-1, 0}
#define VECTOR2_DOWN {0, 1}
#define VECTOR2_RIGHT {1, 0}

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
	Vector2* _position = new Vector2{0, 0};

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
		/// Sets the _position of the Transform to a specified X and Y location.
		/// </summary>
		void SetPosition(float x = 0, float y = 0) const;

		/// <summary>
		/// Sets the _position of the Transform to a specified Vector2 location.
		/// </summary>
		void SetPosition(const Vector2* position) const;

		/// <summary>
		/// Gets the _position of this Transform.
		/// </summary>
		Vector2* GetPosition() const;
};
#endif