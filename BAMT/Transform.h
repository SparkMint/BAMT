#ifndef BAMT_TRANSFORM
#define BAMT_TRANSFORM

#include "Component.h"
#include "Entity.h"

class Entity;
class Component;

class Transform : public Component
{
	int _x = 0;
	int _y = 0;

	public:
		Transform(int x = 0, int y = 0);

		void Start() override;
		void Update() override;
		void LateUpdate() override;

		/// <summary>
		/// Returns X position of this transform.
		/// </summary>
		int x() const;

		/// <summary>
		/// Returns Y position of this transform.
		/// </summary>
		int y() const;

		/// <summary>
		/// Moves this transform by X and Y.
		/// </summary>
		void Translate(int x, int y);

		/// <summary>
		/// Sets the position of the Transform to a specified location.
		/// </summary>
		void Position(int x = 0, int y = 0);
};
#endif