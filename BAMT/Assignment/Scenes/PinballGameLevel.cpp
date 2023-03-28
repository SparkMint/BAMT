#include "PinballGameLevel.h"



void PinballGameLevel::Start()
{
	auto* coordGrid = AddEntity<CoordinateGrid>();
	coordGrid->renderLayer = -1;

	_player = AddEntity<Slingshot>();

}