#include "Player.h"

Player::Player()
{
	AddComponent<Transform>();
	AddComponent<RigidBody>();
	AddComponent<PlayerMovement>();
	AddComponent<RectRenderer>(30,30,true);
}