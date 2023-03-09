#ifndef BAMT_GAME_OF_LIFE
#define BAMT_GAME_OF_LIFE

#include "EngineManager.h"
#include "Entity.h"
#include "CellLogic.h"

#define LIFEGRID_WIDTH 10
#define LIFEGRID_HEIGHT 10

class CellLogic;

class GameOfLife : public Entity
{
	public:
		void Start() override;
		CellLogic* lifeGrid[LIFEGRID_WIDTH][LIFEGRID_HEIGHT];
};

#endif
