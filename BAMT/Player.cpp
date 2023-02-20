#include "Player.h"

Player::Player()
{
	AddComponent<Transform>();
	AddComponent<PlayerInput>();
	AddComponent<TriRenderer>(50);
}
