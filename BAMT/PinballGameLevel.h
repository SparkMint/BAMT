#ifndef BAMT_PINBALL_GAME_LEVEL
#define BAMT_PINBALL_GAME_LEVEL

#include "Scene.h"
#include "Player.h"

class PinballGameLevel : public Scene
{
	Player* _player = nullptr;

	public:
		void Start() override;
};
#endif