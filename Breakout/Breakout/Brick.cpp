#include "stdafx.h"
#include "Brick.h"


Brick::Brick()
{
}

Brick::Brick(int x, int y)
{
	x1 = x;
	y1 = y;
	x2 = x1 + w;
	y2 = y1 + h;
}


Brick::~Brick()
{
}
