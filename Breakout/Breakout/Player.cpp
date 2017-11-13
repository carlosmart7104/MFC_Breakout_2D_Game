#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	moveToCenter();
}


Player::~Player()
{
}

void Player::moveToCenter() {
	x1 = 220;
	y1 = 265;
	x2 = x1 + w;
	y2 = y1 + h;
}

void Player::moveToLeft()
{
	if (x1 > 10)
	{
		x1 -= 10;
		x2 = x1 + w;
	}
}

void Player::moveToRight()
{
	if (x1 < 420)
	{
		x1 += 10;
		x2 = x1 + w;
	}
}
