#pragma once
class Player
{
public:
	Player();
	~Player();
	void moveToCenter();
	void moveToLeft();
	void moveToRight();
	int w = 50, h = 10, x1, y1, x2, y2;
};

