#ifndef BAMT_COORDINATE_GRID
#define BAMT_COORDINATE_GRID

#include "../ECS/Entity.h"
#include "../ECS/Scene.h"
#include "../Components/RectRenderer.h"

class CoordinateGrid : public Entity
{
	int width = 32;
	int height = 18;

	float gridSize = 1;

	public:
		void Start() override;
};
#endif
