#ifndef BAMT_COORDINATE_GRID
#define BAMT_COORDINATE_GRID
#include "Entity.h"

class CoordinateGrid : public Entity
{
	int width = 32;
	int height = 18;

	float gridSize = 1;

	public:
		void Start() override;
};
#endif
