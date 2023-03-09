#ifndef BAMT_CELL_LOGIC
#define BAMT_CELL_LOGIC

#include "Component.h"
#include "GameOfLife.h"
#include "RectRenderer.h"

class GameOfLife;

class CellLogic : public Component
{
	RectRenderer* _rectRenderer;

	public:
		GameOfLife* gameOfLife;
		int x, y;
		bool alive;

		void Start() override;
		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;

		bool CheckNeighbor(int x, int y);
};
#endif
