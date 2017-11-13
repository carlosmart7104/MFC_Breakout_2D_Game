#pragma once
class Ball
{
public:
	Ball();
	~Ball();
	void setPoint(int x, int y);
	int d = 15, stepX = 2, stepY = 8, x1, x2, y1, y2;
};

