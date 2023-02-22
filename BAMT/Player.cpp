#include "Player.h"

Player::Player()
{
	AddComponent<Transform>();
	AddComponent<PlayerMoveMouse>();
	//AddComponent<TriRenderer>(30);
	AddComponent<RectRenderer>(30,30,true);
}