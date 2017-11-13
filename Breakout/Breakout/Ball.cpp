#include "stdafx.h"
#include "Ball.h"


Ball::Ball()
{
	setPoint(230, 140);
}


Ball::~Ball()
{
}


void Ball::setPoint(int x, int y)
{
	x1 = x;
	x2 = x1 + d;
	y1 = y;
	y2 = y1 + d;
}