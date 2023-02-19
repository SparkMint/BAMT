#ifndef BAMT_TRANSFORM
#define BAMT_TRANSFORM
#include "Component.h"

class Transform : public Component
{
	public:
		Transform(int x = 0, int y = 0);

		void Start() override;
		void Update() override;
		void LateUpdate() override;

		int x() const;
		int y() const;

		/// <summary>
		/// Moves this transform by X and Y.
		/// </summary>
		/// <param name="y"></param>
		/// <param name="x"></param>
		void Translate(int x, int y);

	private:
		int _xPos = 0;
		int _yPos = 0;
};

#endif// !BAMT_TRANSFORM

