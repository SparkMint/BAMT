#ifndef BAMT_LIFE_CELL
#define BAMT_LIFE_CELL


#include "Entity.h"
#include "CellLogic.h"
#include "RectRenderer.h"
#include "Transform.h"

class CellLogic;


class LifeCell : public Entity
{
	Transform* _transform = nullptr;
	RectRenderer* _rectRenderer = nullptr;
	CellLogic* _cellLogic;

	public:
	void Start() override;

};

#endif
