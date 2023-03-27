#include "CoordinateGrid.h"

void CoordinateGrid::Start()
{
	const auto halfGridSize = gridSize / 2;
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			auto* gridSquare = scene->AddEntity<Entity>();
			gridSquare->AddComponent<Transform>(halfGridSize + (i * gridSize), halfGridSize + (j * gridSize));
			gridSquare->AddComponent<RectRenderer>(gridSize - .02f, gridSize - .02f, false);
			gridSquare->GetComponent<RectRenderer>()->colour = { 20,20,20,255 };
			gridSquare->renderLayer = -1;
		}
	}
}