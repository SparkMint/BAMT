#include "GameOfLife.h"

#include "LifeCell.h"


void GameOfLife::Start()
{
	for (int i = 0; i < LIFEGRID_WIDTH - 1; ++i)
	{
		for (int j = 0; j < LIFEGRID_HEIGHT - 1; ++j)
		{
			auto* cell = engine->AddEntity<LifeCell>();
			cell->GetComponent<Transform>()->SetPosition(i * 25, j * 25);
			cell->GetComponent<CellLogic>()->gameOfLife = this;
			cell->GetComponent<CellLogic>()->x = i;
			cell->GetComponent<CellLogic>()->y = j;

			//int randomInt = rand() & 1;
			

			//cell->GetComponent<CellLogic>()->alive = randomInt == 1;

			lifeGrid[i][j] = cell->GetComponent<CellLogic>();
		}
	}

	lifeGrid[5][5]->alive = true;
	lifeGrid[5][6]->alive = true;
	lifeGrid[5][7]->alive = true;
}
