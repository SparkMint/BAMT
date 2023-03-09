#include "LifeCell.h"

void LifeCell::Start()
{
	_transform = AddComponent<Transform>();
	_rectRenderer = AddComponent<RectRenderer>(50,50,false);
	_cellLogic = AddComponent<CellLogic>();
}
