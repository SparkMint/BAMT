#include "Player.h"

void Player::Start()
{
	AddComponent<Transform>();
	AddComponent<RigidBody>();
	AddComponent<PlayerMovement>();
	AddComponent<RectRenderer>(30, 30, true);
}