#include "CellLogic.h"

void CellLogic::Start()
{
	_rectRenderer = entity->GetComponent<RectRenderer>();
}

void CellLogic::Update(float* timeStep)
{
	_rectRenderer->fillRect = alive;

	int livingNeighbors = 0;

	// UP
	if (CheckNeighbor(x, y + 1)) livingNeighbors++;

	// DOWN
	if (CheckNeighbor(x, y - 1)) livingNeighbors++;

	// LEFT
	if (CheckNeighbor(x + 1, y)) livingNeighbors++;

	// RIGHT
	if (CheckNeighbor(x - 1, y)) livingNeighbors++;

	// UP-LEFT
	if (CheckNeighbor(x + 1, y + 1)) livingNeighbors++;

	// UP-RIGHT
	if (CheckNeighbor(x - 1, y + 1)) livingNeighbors++;

	// DOWN-LEFT
	if (CheckNeighbor(x + 1, y - 1)) livingNeighbors++;

	// DOWN-RIGHT
	if (CheckNeighbor(x - 1, y - 1)) livingNeighbors++;

	//Debug::Log(std::to_string(livingNeighbors));

		
}

bool CellLogic::CheckNeighbor(int x, int y)
{
	// Invalid Spot.
	if (x > LIFEGRID_WIDTH || x < 0) return false;

	// Invalid Spot.
	if (y > LIFEGRID_HEIGHT || y < 0) return false;


	// Check if this neighbor is alive.
	if(gameOfLife->lifeGrid[x][y])
	{
		return gameOfLife->lifeGrid[x][y]->alive;
	}

	return false;
}

void CellLogic::Render(SDL_Renderer* renderer) {}
