#include "Player.h"

Player::Player()
{
	AddComponent<Transform>();
	AddComponent<PlayerMovement>();
	AddComponent<RectRenderer>(30,30,true);
}