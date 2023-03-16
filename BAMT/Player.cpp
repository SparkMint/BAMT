#include "Player.h"

void Player::Start()
{
	AddComponent<Transform>()->SetPosition(250,250);
	AddComponent<RigidBody>();
	AddComponent<PlayerMovement>();
	AddComponent<RectRenderer>(30, 30, true)->colour = BAMT_COLOUR_BLUE;
	//renderLayer = 1;
}